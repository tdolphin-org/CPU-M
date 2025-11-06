//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GraphicsBoards.hpp"

#include "AOS/Cybergraphics/Library.hpp"
#include "AOS/Exec/Library.hpp"
#include "AOS/PCIIDS/Library.hpp"
#include "AOS/PCIX/Library.hpp"
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
      : mComponent(MUI::GroupBuilder().vertical().tagFrame(MUI::Frame::Group).tagFrameTitle("Graphics Boards(s)").object())
    {
        auto displayBoards = AOS::PCIX::Library::GetBoards({ AOS::PCIX::BaseClass::Display });
        if (displayBoards.empty())
            mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("none")));
        else
        {
            size_t boardIndex = 0;
            for (const auto &board : displayBoards)
            {
                // first show basic info taken directly from PCI IDs
                {
                    std::stringstream fullIdStream;
                    fullIdStream << std::setfill('0') << std::setw(4) << std::hex << board.vendorId << ":" << std::setfill('0')
                                 << std::setw(4) << std::hex << board.classId;

                    mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeCLabel2(
                        "PCIID[" + fullIdStream.str() + "] " + AOS::PCIIDS::Library::libGetVendorName(board.vendorId) + " " + MUIX_B
                        + AOS::PCIIDS::Library::libGetDeviceName(board.vendorId, board.deviceId))));
                }

                // try to find full spec
                auto boardId = DataInfo::vendorAndDevice2gfxBoardId.find({ board.vendorId, board.deviceId });
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
                            if (std::find(boardIds.begin(), boardIds.end(), integratedGraphicsBoard.value()) != boardIds.end())
                                boardIds = { integratedGraphicsBoard.value() };
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
                    for (auto gfxBoardId : boardIds)
                    {
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
                                    .tagChild(MUI::GroupBuilder()
                                                  .horizontal()
                                                  .tagChild(ValueText("Graphics board interface(s)",
                                                                      ToString::Concatenate(
                                                                          [&]() -> std::vector<std::string> {
                                                                              std::vector<std::string> interfaceStrings;
                                                                              for (const auto &interface : gfxBoard2spec->second.interfaces)
                                                                                  interfaceStrings.push_back(std::to_string(interface));
                                                                              return interfaceStrings;
                                                                          }(),
                                                                          ", "),
                                                                      true))
                                                  .tagChild(LabelText(MUIX_R "TDP:"))
                                                  .tagChild(ValueText("Thermal Design Power in watts",
                                                                      gfxBoard2spec->second.TDP
                                                                          ? std::to_string(gfxBoard2spec->second.TDP.value()) + " W"
                                                                          : "N/A",
                                                                      true))
                                                  .object())
                                    .object());

                            mGPUNameComponents.push_back(new GPUName(gfxBoard2spec->second.gpu));

                            mainSpecGroup.AddMember(
                                MUI::GroupBuilder()
                                    .vertical()
                                    .tagColumns(2)
                                    .tagChild(LabelText(MUIX_R "Premiere:"))
                                    .tagChild(ValueText("Graphics card premiere", std::to_string(gfxBoard2spec->second.premiere), true))
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
                if (boardIndex < displayBoards.size())
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
