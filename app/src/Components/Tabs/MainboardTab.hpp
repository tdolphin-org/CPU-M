//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "Components/Base.hpp"

#include "MUI/Floattext.hpp"
#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class MainboardTab : public Root<MUI::Group>, public Base
    {
        MUI::Text mVendorText;
        MUI::Text mSystemText;
        MUI::Text mFullNameText; // marketing name
        MUI::Text mModelNumberText; // optional
        MUI::Text mTimelineText; // years range (from intoduction to discontinued)
        MUI::Text mProcessorSocketText;
        MUI::Text mFirmwareTypeText;
        MUI::Text mStorageInterfacesText;
        MUI::Floattext mPortsGroup;
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