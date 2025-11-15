//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GraphicsBoards.hpp"

#include "AOS/Exec/Library.hpp"
#include "AOS/Intuition/Library.hpp"
#include "AOS/PCIIDS/Library.hpp"
#include "Components/Tabs/Graphics/TheoreticalPerformance.hpp"
#include "DataInfo/GfxBoardSpec.hpp"
#include "DataInfo/HardwareSystemSpec.hpp"
#include "DataInfo/PCI2IDSpec.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Scrollgroup.hpp"
#include "MUI/Virtgroup.hpp"

#include <algorithm>
#include <iomanip>
#include <sstream>

namespace Components
{
    GraphicsBoards::GraphicsBoards()
      : mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagFrame(MUI::Frame::Group)
                       .tagFrameTitle("Mounted Devs Monitor(s) / Graphics Boards(s)")
                       .object())
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
                        .tagChild(ValueText("Manufacturer of this graphics board",
                                            AOS::PCIIDS::Library::libGetVendorName(monitor.manufacturerId)))
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
                auto boardId = DataInfo::vendorAndDevice2gfxBoardId.find(DataInfo::PCIDeviceKey(monitor.manufacturerId, monitor.productId));
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
                                                          return value.gfxBoardId == integratedGraphicsBoard.value();
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
                        auto gfxBoardId = boardValue.gfxBoardId;
                        auto gfxBoard2spec = DataInfo::gfxBoard2spec.find(gfxBoardId);
                        if (gfxBoard2spec != DataInfo::gfxBoard2spec.end())
                        {
                            MUI::Group boardsGroup = MUI::GroupBuilder().horizontal().object();
                            MUI::Group mainSpecGroup
                                = MUI::GroupBuilder().horizontal().tagFrame(MUI::Frame::Group).tagFrameTitle("Specification").object();

                            mainSpecGroup.AddMember(MUI::GroupBuilder()
                                                        .vertical()
                                                        .tagChild(LabelText(MUIX_R "Name:"))
                                                        .tagChild(LabelText(MUIX_R "Interface(s):"))
                                                        .object());

                            mainSpecGroup.AddMember(
                                MUI::GroupBuilder()
                                    .vertical()
                                    .tagChild(ValueText(
                                        "Normalized graphics card name",
                                        std::to_string(gfxBoard2spec->second.manufacturer) + " " + gfxBoard2spec->second.name, true))
                                    .tagChild(
                                        MUI::GroupBuilder()
                                            .horizontal()
                                            .tagChild(ValueText("Graphics board interface(s)",
                                                                boardValue.interface.has_value()
                                                                    ? std::to_string(boardValue.interface.value())
                                                                    : ToString::Concatenate(
                                                                          [&]() -> std::vector<std::string> {
                                                                              std::vector<std::string> interfaceStrings;
                                                                              for (const auto &interface : gfxBoard2spec->second.interfaces)
                                                                                  interfaceStrings.push_back(std::to_string(interface));
                                                                              return interfaceStrings;
                                                                          }(),
                                                                          ", ")))
                                            .tagChild(LabelText(MUIX_R "TDP:"))
                                            .tagChild(ValueText("Thermal Design Power in watts",
                                                                gfxBoard2spec->second.TDP
                                                                    ? std::to_string(gfxBoard2spec->second.TDP.value()) + " W"
                                                                    : "N/A"))
                                            .object())
                                    .object());

                            mGPUNameComponents.push_back(new GPUName(gfxBoard2spec->second.gpu));

                            mainSpecGroup.AddMember(
                                MUI::GroupBuilder()
                                    .vertical()
                                    .tagColumns(2)
                                    .tagChild(LabelText(MUIX_R "Premiere:"))
                                    .tagChild(ValueText("Graphics card premiere", std::to_string(gfxBoard2spec->second.premiere)))
                                    .tagChild(LabelText(MUIX_R "GPU:"))
                                    .tagChild(*mGPUNameComponents.back())
                                    .object());

                            boardsGroup.AddMember(mainSpecGroup);
                            boardsGroup.AddMember(TheoreticalPerformance(gfxBoard2spec->second.theoreticalPerformance));

                            allBoardsVirtgroup.AddMember(boardsGroup);
                        }
                        else
                        {
                            allBoardsVirtgroup.AddMember(MUI::MakeObject::HCenter(
                                MUI::MakeObject::FreeLabel("No detailed specification found for this graphics board (GfxBoardID: "
                                                           + std::to_string((unsigned long)gfxBoardId) + ")")));
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
