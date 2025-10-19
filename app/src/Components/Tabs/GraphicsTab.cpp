//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GraphicsTab.hpp"

#include "AOS/Graphics/Library.hpp"
#include "AOS/PCIIDS/Library.hpp"
#include "AOS/PCIX/Library.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Core/NullObject.hpp"

namespace Components
{
    GraphicsTab::GraphicsTab()
      : mGfxSystemText(ValueText("Graphic OS"))
      , mMountedMonitors(MUI::GroupBuilder().tagFrame(MUI::Frame::Group).tagFrameTitle("Mounted Devs Monitor(s)").object())
      , mGraphicsCards(MUI::GroupBuilder().tagFrame(MUI::Frame::Group).tagFrameTitle("Graphics Card(s)").object())
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::MakeObject::HVSpace())
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Graphic System")
                                     .tagColumns(2)
                                     .tagChild(LabelText(MUIX_R "Name:"))
                                     .tagChild(mGfxSystemText)
                                     .object())
                       .tagChild(mMountedMonitors)
                       .tagChild(mGraphicsCards)
                       .tagChild(MUI::MakeObject::HVSpace())
                       .object())
    {
        mGfxSystemText.setContents("CyberGraphX");

        auto mountedMonitors = AOS::Graphics::Library::GetMonitors();
        if (mountedMonitors.empty())
            mMountedMonitors.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("none")));
        else
        {
            mMountedMonitors.setColumns(mountedMonitors.size() < 4 ? mountedMonitors.size() : 4);
            for (const auto &monitorName : mountedMonitors)
                mMountedMonitors.AddMember(MUI::TextBuilder().tagFrame(MUI::Frame::String).tagContents(monitorName).object());
        }

        auto displayBoards = AOS::PCIX::Library::GetDisplayBoards();
        if (displayBoards.empty())
            mGraphicsCards.AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("none")));
        else
        {
            mGraphicsCards.setColumns(displayBoards.size() < 4 ? displayBoards.size() : 4);
            for (const auto &board : displayBoards)
            {
                mGraphicsCards.AddMember(
                    MUI::GroupBuilder()
                        .tagColumns(4)
                        .tagChild(LabelText(MUIX_R "Name:"))
                        .tagChild(MUI::TextBuilder()
                                      .tagFrame(MUI::Frame::String)
                                      .tagContents(AOS::PCIIDS::Library::libGetDeviceName(board.vendorId, board.deviceId))
                                      .object())
                        .tagChild(LabelText(MUIX_R "Manufacturer:"))
                        .tagChild(MUI::TextBuilder()
                                      .tagFrame(MUI::Frame::String)
                                      .tagContents(AOS::PCIIDS::Library::libGetVendorName(board.vendorId))
                                      .object())
                        .object());
            }
        }
    }

    GraphicsTab::~GraphicsTab() { }
}
