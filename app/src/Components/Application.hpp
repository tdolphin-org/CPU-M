//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "AOS/Icon/DiskObjectScope.hpp"
#include "AppWindow.hpp"
#include "Components/Core/Root.hpp"
#include "Components/Menus/MainMenu.hpp"
#include "MUI/Application.hpp"

namespace Components
{
    class Application : public Root<MUI::Application>
    {
        AOS::Icon::DiskObjectScope mAppIcon;
        AppWindow mAppWindow;
        MainMenu mMainMenu;

        MUI::Application mComponent;

      public:
        Application();

        void RegisterEvents();

      protected:
        MUI::Application &muiRoot() const
        {
            return (MUI::Application &)mComponent;
        }
    };
}
