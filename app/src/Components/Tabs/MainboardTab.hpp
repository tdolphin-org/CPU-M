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
        MUI::Text mModelNumberText; // optional
        MUI::Text mTimelineText; // years range (from intoduction to discontinued)
        MUI::Text mProcessorSocketText;
        MUI::Text mFirmwareTypeText;
        MUI::Text mStorageInterfacesText;
        MUI::Group mPortsGroup;
        MUI::Text mNoteText;

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