//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "Content.hpp"

#include "Events/AppEventType.hpp"
#include "MUI/Context/ApplicationContext.hpp"
#include "MUI/Notifier/Notifier.hpp"
#include "TextResources/Labels.hpp"

namespace Components
{
    Content::Content()
      : mComponent({
            { Label::CPUTab, mCPUTab },
            { Label::MainboardTab, mMainboardTab },
            { Label::MemoryTab, mMemoryTab },
            { Label::GraphicsTab, mGraphicsTab },
            { Label::BoardsTab, mBoardsTab },
            { Label::OperatingSystemTab, mOSTab },
            { Label::AboutTab, mAboutTab },
        })
    {
    }

    void Content::RegisterEvents()
    {
        auto appWindow = MUI::ApplicationContext::instance().getAppWindow();
        MUI::Notifier::from(appWindow)
            .onMenuAction(static_cast<unsigned long>(AppEventType::OnMenuAbout))
            .notifyObject(mComponent)
            .setActivePage(MUI::Group_ActivePage::Last);
        MUI::Notifier::from(appWindow).onMenuAction(static_cast<unsigned long>(AppEventType::OnMenuAbout)).notifySelf().toFront();
    }
}
