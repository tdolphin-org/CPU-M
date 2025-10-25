//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GraphicsBoards.hpp"

#include "AOS/Cybergraphics/Library.hpp"
#include "AOS/PCIIDS/Library.hpp"
#include "AOS/PCIX/Library.hpp"
#include "Components/Tabs/Graphics/Theoretical3DPerformance.hpp"
#include "DataInfo/GfxBoardSpec.hpp"
#include "DataInfo/PCI2IDSpec.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    GraphicsBoards::GraphicsBoards()
      : mComponent(MUI::GroupBuilder().tagFrame(MUI::Frame::Group).tagFrameTitle("Graphics Boards(s)").object())
    {
        auto displayBoards = AOS::PCIX::Library::GetBoards({ AOS::PCIX::BaseClass::Display });
        if (displayBoards.empty())
            mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("none")));
        else
        {
            mComponent.setColumns(displayBoards.size() < 4 ? displayBoards.size() : 4);
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

                MUI::Group boardGroup = MUI::GroupBuilder().horizontal().object();

                if (gfxBoardSpec.has_value())
                {
                    mComponent.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeCLabel2(gfxBoardSpec->name)));

                    boardGroup.AddMember(
                        MUI::GroupBuilder()
                            .tagColumns(4)
                            .tagChild(LabelText(MUIX_R "Vendor:"))
                            .tagChild(MUI::TextBuilder()
                                          .tagFrame(MUI::Frame::String)
                                          .tagContents(std::to_string(gfxBoardSpec->manufacturer))
                                          .object())
                            .tagChild(LabelText("Premiere:"))
                            .tagChild(MUI::TextBuilder()
                                          .tagFrame(MUI::Frame::String)
                                          .tagContents(std::to_string(gfxBoardSpec->premiere))
                                          .object())
                            .tagChild(LabelText("Interface:"))
                            .tagChild(MUI::TextBuilder()
                                          .tagFrame(MUI::Frame::String)
                                          .tagContents(std::to_string(gfxBoardSpec->interface))
                                          .object())
                            .tagChild(LabelText("TDP:"))
                            .tagChild(MUI::TextBuilder()
                                          .tagFrame(MUI::Frame::String)
                                          .tagContents(gfxBoardSpec->TDP ? std::to_string(gfxBoardSpec->TDP.value()) : "N/A")
                                          .object())
                            .object());

                    boardGroup.AddMember(Theoretical3DPerformance(gfxBoardSpec->theoretical3DPerformance));

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
