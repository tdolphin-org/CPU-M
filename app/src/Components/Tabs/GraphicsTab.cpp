//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GraphicsTab.hpp"

#include "AOS/Graphics/Library.hpp"
#include "Graphics/CGXBoards.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Core/NullObject.hpp"

namespace Components
{
    GraphicsTab::GraphicsTab()
      : mGfxSystemText(ValueText("Graphic OS"))
      , mMountedMonitors(MUI::GroupBuilder()
                             .tagFrame(MUI::Frame::Group)
                             .tagBackground(MUI::ImageOrBackground::WindowBack)
                             .tagFrameTitle("Mounted Devs Monitor(s)")
                             .object())
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagBackground(MUI::ImageOrBackground::WindowBack)
                                     .tagFrameTitle("Graphic System")
                                     .tagColumns(2)
                                     .tagChild(LabelText(MUIX_R "Name"))
                                     .tagChild(mGfxSystemText)
                                     .object())
                       .tagChild(mMountedMonitors)
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
    }

    GraphicsTab::~GraphicsTab()
    {
    }
}
