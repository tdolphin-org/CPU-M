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
    class MemorySlotsInfo; // forward declaration

    class MemoryTab : public Root<MUI::Group>, public TabBase
    {
        std::vector<MemorySlotsInfo *> mMemorySlotsInfos;

        MUI::Text mTotalSystemMemoryText;
        MUI::Group mRAMSpecGroup;

        MUI::Group mComponent;

      public:
        MemoryTab();
        virtual ~MemoryTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}