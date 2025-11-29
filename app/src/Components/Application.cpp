//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "Application.hpp"

#include "Events/AppEventType.hpp"
#include "MUI/Notifier/Notifier.hpp"
#include "ProgDefines.hpp"
#include "Version.hpp"
#include "WindowManager.hpp"

namespace Components
{
    Application::Application()
      : mAppIcon(AOS::Icon::DiskObjectScope("PROGDIR:" CMD_NAME))
      , mComponent(MUI::ApplicationBuilder()
                       .tagAuthor(AUTHORS)
                       .tagBase(CMD_NAME)
                       .tagCopyright(APP_TDOLPHIN_COPYRIGHTS)
                       .tagDescription(APP_DESCRIPTION)
                       .tagTitle(APP_NAME)
                       .tagVersion(AMIGAOS_VER_PREFIX " " CMD_NAME " " APP_VERSION " " APP_DATE)
                       .tagWindow(mAppWindow)
                       .tagWindows(WindowManager::instance().getAllWindows())
                       .tagDiskObject(*mAppIcon.diskObject())
                       .tagMenustrip(mMainMenu)
                       .object())
    {
    }

    void Application::RegisterEvents()
    {
        MUI::Notifier::from(mAppWindow).onCloseRequest(true).notifyObject(mComponent).returnIDQuit();
        MUI::Notifier::from(mAppWindow)
            .onMenuAction(static_cast<unsigned long>(AppEventType::OnMenuMUISettings))
            .notifyObject(mComponent)
            .openConfigWindow();

        mAppWindow.RegisterEvents();
    }
}
