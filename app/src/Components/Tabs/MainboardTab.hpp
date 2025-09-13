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
        MUI::Text mFullNameText; // marketing name
        MUI::Text mIntroductionYearText;
        MUI::Text mDiscontinuedYearText;
        MUI::Text mProcessorSocketText;
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