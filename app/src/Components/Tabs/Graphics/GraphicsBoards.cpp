//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GraphicsBoards.hpp"

#include "AOS/Cybergraphics/Library.hpp"
#include "AOS/PCIIDS/Library.hpp"
#include "AOS/PCIX/Library.hpp"
#include "Components/Tabs/Graphics/TheoreticalPerformance.hpp"
#include "DataInfo/GfxBoardSpec.hpp"
#include "DataInfo/PCI2IDSpec.hpp"
#include "MUI/Core/MakeObject.hpp"

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
            for (const auto &board : displayBoards)
            {
                // first show basic info taken directly from PCI IDs
                {
                    std::stringstream fullIdStream;
                    fullIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << board.vendorId << ":" << std::setfill('0')
                                 << std::setw(4) << std::hex << board.classId;

                    mComponent.AddMember(MUI::MakeObject::HCenter(
                        MUI::MakeObject::FreeCLabel2(MUIX_B + AOS::PCIIDS::Library::libGetDeviceName(board.vendorId, board.deviceId)
                                                     + MUIX_N " [" + fullIdStream.str() + "]")));

                    mComponent.AddMember(MUI::GroupBuilder()
                                             .tagColumns(2)
                                             .tagChild(LabelText(MUIX_R "Vendor:"))
                                             .tagChild(MUI::TextBuilder()
                                                           .tagFrame(MUI::Frame::String)
                                                           .tagContents(AOS::PCIIDS::Library::libGetVendorName(board.vendorId))
                                                           .object())
                                             .object());
                }

                // try to find full spec
                auto boardId = DataInfo::vendorAndDevice2gfxBoardId.find({ board.vendorId, board.deviceId });
                if (boardId != DataInfo::vendorAndDevice2gfxBoardId.end())
                {
                    if (boardId->second.size() > 1)
                    {
                        mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeCLabel2(
                            "This PCI ID corresponds to multiple possible graphics cards. The specifications shown below refer to one of "
                            "these possible models, as CPU-M was unable to determine the exact card variant.")));
                    }
                    for (auto gfxBoardId : boardId->second)
                    {
                        auto gfxBoard2spec = DataInfo::gfxBoard2spec.find(gfxBoardId);
                        if (gfxBoard2spec != DataInfo::gfxBoard2spec.end())
                        {
                            mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeCLabel2(gfxBoard2spec->second.name)));

                            MUI::Group boardGroup = MUI::GroupBuilder().horizontal().object();
                            boardGroup.AddMember(
                                MUI::GroupBuilder()
                                    .tagColumns(4)
                                    .tagChild(LabelText(MUIX_R "Vendor:"))
                                    .tagChild(MUI::TextBuilder()
                                                  .tagFrame(MUI::Frame::String)
                                                  .tagContents(std::to_string(gfxBoard2spec->second.manufacturer))
                                                  .object())
                                    .tagChild(LabelText(MUIX_R "Premiere:"))
                                    .tagChild(MUI::TextBuilder()
                                                  .tagFrame(MUI::Frame::String)
                                                  .tagContents(std::to_string(gfxBoard2spec->second.premiere))
                                                  .object())
                                    .tagChild(LabelText(MUIX_R "Interface:"))
                                    .tagChild(MUI::TextBuilder()
                                                  .tagFrame(MUI::Frame::String)
                                                  .tagContents(ToString::Concatenate(
                                                      [&]() -> std::vector<std::string> {
                                                          std::vector<std::string> interfaceStrings;
                                                          for (const auto &interface : gfxBoard2spec->second.interfaces)
                                                              interfaceStrings.push_back(std::to_string(interface));
                                                          return interfaceStrings;
                                                      }(),
                                                      ", "))
                                                  .object())
                                    .tagChild(LabelText(MUIX_R "TDP:"))
                                    .tagChild(MUI::TextBuilder()
                                                  .tagFrame(MUI::Frame::String)
                                                  .tagContents(gfxBoard2spec->second.TDP ? std::to_string(gfxBoard2spec->second.TDP.value())
                                                                                         : "N/A")
                                                  .object())
                                    .object());

                            boardGroup.AddMember(TheoreticalPerformance(gfxBoard2spec->second.theoreticalPerformance));

                            mComponent.AddMember(boardGroup);
                        }
                    }
                }

                mComponent.AddMember(MUI::MakeObject::HBar(0));
            }
        }
    }

    GraphicsBoards::~GraphicsBoards()
    {
        for (const auto *pButton : mGPUSpecButtons)
            delete pButton;
    }
}
