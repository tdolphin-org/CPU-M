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
                auto boardId = DataInfo::vendorAndDevice2gfxBoardId.find({ board.vendorId, board.deviceId });
                std::optional<DataInfo::GfxBoardSpec> gfxBoardSpec;
                if (boardId != DataInfo::vendorAndDevice2gfxBoardId.end())
                {
                    auto gfxBoard2spec = DataInfo::gfxBoard2spec.find(boardId->second);
                    if (gfxBoard2spec != DataInfo::gfxBoard2spec.end())
                        gfxBoardSpec = gfxBoard2spec->second;
                }

                if (gfxBoardSpec.has_value())
                {
                    mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeCLabel2(gfxBoardSpec->name)));

                    MUI::Group boardGroup = MUI::GroupBuilder().horizontal().object();
                    boardGroup.AddMember(
                        MUI::GroupBuilder()
                            .tagColumns(4)
                            .tagChild(LabelText(MUIX_R "Vendor:"))
                            .tagChild(MUI::TextBuilder()
                                          .tagFrame(MUI::Frame::String)
                                          .tagContents(std::to_string(gfxBoardSpec->manufacturer))
                                          .object())
                            .tagChild(LabelText(MUIX_R "Premiere:"))
                            .tagChild(MUI::TextBuilder()
                                          .tagFrame(MUI::Frame::String)
                                          .tagContents(std::to_string(gfxBoardSpec->premiere))
                                          .object())
                            .tagChild(LabelText(MUIX_R "Interface:"))
                            .tagChild(MUI::TextBuilder()
                                          .tagFrame(MUI::Frame::String)
                                          .tagContents(ToString::Concatenate(
                                              [&]() -> std::vector<std::string> {
                                                  std::vector<std::string> interfaceStrings;
                                                  for (const auto &interface : gfxBoardSpec->interfaces)
                                                      interfaceStrings.push_back(std::to_string(interface));
                                                  return interfaceStrings;
                                              }(),
                                              ", "))
                                          .object())
                            .tagChild(LabelText(MUIX_R "TDP:"))
                            .tagChild(MUI::TextBuilder()
                                          .tagFrame(MUI::Frame::String)
                                          .tagContents(gfxBoardSpec->TDP ? std::to_string(gfxBoardSpec->TDP.value()) : "N/A")
                                          .object())
                            .object());

                    boardGroup.AddMember(TheoreticalPerformance(gfxBoardSpec->theoreticalPerformance));

                    mComponent.AddMember(boardGroup);
                }
                else
                {
                    mComponent.AddMember(MUI::MakeObject::HCenter(
                        MUI::MakeObject::FreeCLabel2(AOS::PCIIDS::Library::libGetDeviceName(board.vendorId, board.deviceId))));

                    mComponent.AddMember(MUI::GroupBuilder()
                                             .tagColumns(2)
                                             .tagChild(LabelText(MUIX_R "Vendor:"))
                                             .tagChild(MUI::TextBuilder()
                                                           .tagFrame(MUI::Frame::String)
                                                           .tagContents(AOS::PCIIDS::Library::libGetVendorName(board.vendorId))
                                                           .object())
                                             .object());
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
