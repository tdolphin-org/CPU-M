//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GraphicsBoards.hpp"

#include "AOS/Exec/Library.hpp"
#include "AOS/Intuition/Library.hpp"
#include "AOS/PCIIDS/Library.hpp"
#include "AOS/PCIX/Library.hpp"
#include "DataInfo/GfxCardSpec.hpp"
#include "DataInfo/HardwareSystemSpec.hpp"
#include "DataInfo/PCI2IDSpec.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Core/NullObject.hpp"
#include "MUI/Scrollgroup.hpp"
#include "MUI/Virtgroup.hpp"
#include "TheoreticalPerformance.hpp"

#include <algorithm>
#include <iomanip>
#include <sstream>

namespace Components
{
    GraphicsBoards::GraphicsBoards()
      : mComponent(
            MUI::GroupBuilder().vertical().tagFrame(MUI::Frame::Group).tagFrameTitle("Mounted Devs Monitor(s) / Graphics Card(s)").object())
    {
        auto monitors = AOS::Intuition::Library::libGetMonitorList();
        if (monitors.empty())
            mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("none")));
        else
        {
            size_t boardIndex = 0;
            for (const auto &monitor : monitors)
            {
                std::stringstream fullIdStream;
                fullIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << monitor.manufacturerId << ":0x"
                             << std::setfill('0') << std::setw(4) << std::hex << monitor.productId;

                mComponent.AddMember(
                    MUI::GroupBuilder()
                        .horizontal()
                        .tagChild(LabelText(MUIX_R "Manufacturer:"))
                        .tagChild(
                            ValueText("Manufacturer of this graphics card", AOS::PCIIDS::Library::libGetVendorName(monitor.manufacturerId)))
                        .tagChild(LabelText(MUIX_R "Product name:"))
                        .tagChild(ValueText("Full product name",
                                            MUIX_B + AOS::PCIIDS::Library::libGetDeviceName(monitor.manufacturerId, monitor.productId)))
                        .object());

                mComponent.AddMember(
                    MUI::GroupBuilder()
                        .tagColumns(6)
                        .tagFrame(MUI::Frame::Group)
                        .tagFrameTitle("Detailed Monitor Information")
                        .tagChild(LabelText(MUIX_R "PCI ID:"))
                        .tagChild(ValueText("PCI ID in format (vendorId:deviceId)", fullIdStream.str()))
                        .tagChild(LabelText(MUIX_R "CGX Monitor:"))
                        .tagChild(ValueText("Cybergraphics monitor name", monitor.name))
                        .tagChild(LabelText(MUIX_R "Driver:"))
                        .tagChild(ValueText("Cybergraphics driver name", monitor.driverName))
                        .tagChild(LabelText(MUIX_R "Memory Size:"))
                        .tagChild(ValueText("Amount of video memory installed",
                                            ToString::FromBytesValue(monitor.memorySize, MemorySizeUnit::MegaBytes, true)))
                        .tagChild(LabelText(MUIX_R "Memory Clock:"))
                        .tagChild(ValueText(
                            "Memory clock speed",
                            monitor.memoryClock.has_value() ? ToString::FromClockHertzValue(monitor.memoryClock.value(), true) : "N/A"))
                        .tagChild(LabelText(MUIX_R "GPU Clock:"))
                        .tagChild(ValueText(
                            "GPU clock speed",
                            monitor.engineClock.has_value() ? ToString::FromClockHertzValue(monitor.engineClock.value(), true) : "N/A"))
                        .object());

                // try to find full spec

                // first find with subsystem ID, due to possible multiple graphics cards with same vendor/device ID
                // get subsystemVendorId and subsystemProductId
                std::optional<unsigned long> subsystemVendorId;
                std::optional<unsigned long> subsystemProductId;
                auto displayBoards = AOS::PCIX::Library::GetBoards({ AOS::PCIX::BaseClass::Display });
                for (const auto &board : displayBoards)
                {
#ifdef TRACE
                    std::cout << "Checking board VID:PID " << std::hex << std::setfill('0') << std::setw(4) << board.vendorId << ":"
                              << std::hex << std::setfill('0') << std::setw(4) << board.deviceId << std::dec << std::endl;
#endif

                    if (board.vendorId == monitor.manufacturerId && board.deviceId == monitor.productId)
                    {
#ifdef TRACE
                        std::cout << " Found matching board VID:PID" << std::endl;
#endif

                        if (board.subsystemVendorId.has_value() && board.subsystemId.has_value())
                        {
#ifdef TRACE
                            std::cout << "  Found matching board with subsystem VID:PID " << std::hex << std::setfill('0') << std::setw(4)
                                      << board.subsystemVendorId.value() << ":" << std::hex << std::setfill('0') << std::setw(4)
                                      << board.subsystemId.value() << std::dec << std::endl;
#endif

                            subsystemVendorId = board.subsystemVendorId.value();
                            subsystemProductId = board.subsystemId.value();
                            break;
                        }
                    }
                }

                auto boardId = DataInfo::vendorAndDevice2gfxBoardId.end();

                if (subsystemVendorId.has_value() && subsystemProductId.has_value())
                    boardId = DataInfo::vendorAndDevice2gfxBoardId.find(DataInfo::PCIDeviceKey(
                        monitor.manufacturerId, monitor.productId, subsystemVendorId.value(), subsystemProductId.value()));

                if (boardId == DataInfo::vendorAndDevice2gfxBoardId.end())
                {
#ifdef TRACE
                    std::cout << " No matching board found with subsystem VID:PID, trying without it" << std::endl;
#endif
                    boardId = DataInfo::vendorAndDevice2gfxBoardId.find(DataInfo::PCIDeviceKey(monitor.manufacturerId, monitor.productId));
                }
#ifdef TRACE
                else
                    std::cout << " Using subsystem VID:PID to find exact graphics card model" << std::endl;
#endif

                if (boardId != DataInfo::vendorAndDevice2gfxBoardId.end())
                {
                    auto boardIds = boardId->second;
                    if (boardIds.size() > 1)
                    {
                        // check if we have some info about graphics card for given hardware system
                        auto systemName = AOS::Exec::Library::libNewGetSystemAttrsAsString(AOS::Exec::SYSTEMINFOTYPE::SYSTEM);
                        auto hardwareSpec = DataInfo::hardwareSystem2spec.find(systemName);
                        if (hardwareSpec != DataInfo::hardwareSystem2spec.end() && hardwareSpec->second.integratedGraphicsBoard.has_value())
                        {
                            auto integratedGraphicsBoard = hardwareSpec->second.integratedGraphicsBoard;
                            // check if this board is among possible boards for given PCI ID
                            auto found = std::find_if(boardIds.begin(), boardIds.end(),
                                                      [&integratedGraphicsBoard](const DataInfo::PCIDeviceValue &value) {
                                                          return value.gfxCardId == integratedGraphicsBoard.value();
                                                      });
                            if (found != boardIds.end())
                                boardIds = { *found };
                        }

                        mComponent.AddMember(MUI::MakeObject::HCenter(
                            MUI::TextBuilder()
                                .tagFrameTitle("Note")
                                .tagFrame(MUI::Frame::Group)
                                .tagContents(boardIds.size() > 1 ? MUIX_B "This PCI ID corresponds to multiple possible graphics cards.\n"
                                                                          "The specifications shown below refer to one of these possible "
                                                                          "models, as CPU-M was unable to determine the exact card variant."
                                                                 : MUIX_B "This PCI ID corresponds to multiple possible graphics cards.\n"
                                                                          "But CPU-M was able to determine the exact card variant.")
                                .object()));
                    }

                    MUI::Virtgroup allBoardsVirtgroup = MUI::VirtgroupBuilder().vertical().object();
                    size_t boardIdIndex = 0;
                    for (auto boardValue : boardIds)
                    {
                        auto gfxCardId = boardValue.gfxCardId;
                        auto gfxCard2spec = DataInfo::gfxCard2spec.find(gfxCardId);
                        if (gfxCard2spec != DataInfo::gfxCard2spec.end())
                        {
                            MUI::Group boardsGroup = MUI::GroupBuilder().horizontal().object();
                            MUI::Group mainSpecGroup
                                = MUI::GroupBuilder().horizontal().tagFrame(MUI::Frame::Group).tagFrameTitle("Specification").object();

                            mainSpecGroup.AddMember(MUI::GroupBuilder()
                                                        .vertical()
                                                        .tagChild(LabelText(MUIX_R "Name:"))
                                                        .tagChild(LabelText(MUIX_R "Interface(s):"))
                                                        .object());

                            mBusInterfaceNamesComponents.push_back(new BusInterfaceNames(
                                boardValue.interface.has_value() ? std::to_string(boardValue.interface.value())
                                                                 : ToString::Concatenate(
                                                                       [&]() -> std::vector<std::string> {
                                                                           std::vector<std::string> interfaceStrings;
                                                                           for (const auto &interface : gfxCard2spec->second.interfaces)
                                                                               interfaceStrings.push_back(std::to_string(interface));
                                                                           return interfaceStrings;
                                                                       }(),
                                                                       ", ")));

                            mainSpecGroup.AddMember(
                                MUI::GroupBuilder()
                                    .vertical()
                                    .tagChild(ValueText("Normalized graphics card name",
                                                        std::to_string(gfxCard2spec->second.manufacturer) + " " + gfxCard2spec->second.name,
                                                        true))
                                    .tagChild(MUI::GroupBuilder()
                                                  .horizontal()
                                                  .tagChild(*mBusInterfaceNamesComponents.back())
                                                  .tagChild(LabelText(MUIX_R "TDP:"))
                                                  .tagChild(ValueText("Thermal Design Power in watts",
                                                                      gfxCard2spec->second.TDP
                                                                          ? std::to_string(gfxCard2spec->second.TDP.value()) + " W"
                                                                          : "N/A"))
                                                  .object())
                                    .object());

                            mGPUNameComponents.push_back(new GPUName(gfxCard2spec->second.gpu));

                            auto hasGpuVariant = gfxCard2spec->second.gpuVariant.has_value();
                            mainSpecGroup.AddMember(
                                MUI::GroupBuilder()
                                    .vertical()
                                    .tagColumns(2)
                                    .tagChild(LabelText(MUIX_R "Premiere:"))
                                    .tagChild(ValueText("Graphics card premiere", std::to_string(gfxCard2spec->second.premiere)))
                                    .tagChild(LabelText(MUIX_R "GPU:"))
                                    .tagChild(*mGPUNameComponents.back())
                                    .tagChild(LabelText(MUIX_R "GPU Variant:"), hasGpuVariant)
                                    .tagChild(ValueText("GPU variant name",
                                                        hasGpuVariant ? std::to_string(gfxCard2spec->second.gpuVariant.value()) : ""),
                                              hasGpuVariant)
                                    .object());

                            boardsGroup.AddMember(mainSpecGroup);
                            boardsGroup.AddMember(TheoreticalPerformance(gfxCard2spec->second.theoreticalPerformance));

                            allBoardsVirtgroup.AddMember(boardsGroup);
                        }
                        else
                        {
                            allBoardsVirtgroup.AddMember(MUI::MakeObject::HCenter(
                                MUI::MakeObject::FreeLabel("No detailed specification found for this graphics card (GfxCardID: "
                                                           + std::to_string((unsigned long)gfxCardId) + ")")));
                        }

                        boardIdIndex++;
                        if (boardIdIndex < boardIds.size())
                            allBoardsVirtgroup.AddMember(MUI::MakeObject::HBar(10));
                    }

                    allBoardsVirtgroup.AddMember(MUI::MakeObject::HVSpace());

                    mComponent.AddMember(MUI::ScrollgroupBuilder().tagContents(allBoardsVirtgroup).tagAutoBars(true).object());
                }

                boardIndex++;
                if (boardIndex < monitors.size())
                    mComponent.AddMember(MUI::MakeObject::HBar(0));
            }
        }
    }

    GraphicsBoards::~GraphicsBoards()
    {
        for (const auto *pComponent : mGPUNameComponents)
            delete pComponent;
    }
}
