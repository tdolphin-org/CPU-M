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
    class MemoryTab : public Root<MUI::Group>, public TabBase
    {
        MUI::Text mTotalSystemMemoryText;
        MUI::Text mRAMSpecText;
        MUI::Text mRAMNoteText;

        MUI::Group mComponent;

      public:
        MemoryTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}