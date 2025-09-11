//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "TabBase.hpp"

#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class MainboardTab : public Root<MUI::Group>, public TabBase
    {
        MUI::Text mVendorText;
        MUI::Text mSystemText;
        MUI::Text mFullNameText;
        MUI::Text mRevisionText;
        MUI::Text mIntroductionDateText;
        MUI::Text mDiscontinuedDateText;
        MUI::Text mProcessorUpgradeText;
        MUI::Text mProcessorUpgradeDetailsText;
        MUI::Text mBatteryTypeText;
        MUI::Text mStorageDimensionsText;
        MUI::Text mStorageInterfaceText;
        MUI::Text mFirmwareTypeText;

        MUI::Group mComponent;

      public:
        MainboardTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}