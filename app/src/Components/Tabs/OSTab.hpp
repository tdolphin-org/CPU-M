//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#pragma once

#include "Components/Base.hpp"
#include "Components/Core/Root.hpp"
#include "Components/Tabs/TabsContainer.hpp"

#include "MUI/Group.hpp"
#include "MUI/List.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class OSTab : public Root<MUI::Group>, public Base
    {
        MUI::Text mFullOSNameText;
        MUI::Text mRegisteredToText;
        MUI::Text mUserText;
        MUI::Text mUserLoginText;
        MUI::Text mUserHomePathText;
        MUI::Text mKickstartVersionText;
        MUI::Text mExecVersionText;
        MUI::Text mAmbientVersionText;
        MUI::Text mWorkbenchVersionText;
        MUI::Text mTimeZoneText;
        MUI::Text mCodePageText;
        MUI::Text mLocaleText;

        MUI::List mLoadedLibrariesList;
        MUI::List mLoadedDevicesList;
        MUI::List mLoadedDatatypesList;
        MUI::List mLoadedMUIList;
        MUI::List mLoadedResourcesList;
        MUI::List mLoadedOtherList;
        TabsContainer mExecNodesTabs;

        MUI::Group mComponent;

      public:
        OSTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}