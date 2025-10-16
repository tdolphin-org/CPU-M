//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Buttons/MemoryModuleSpecButton.hpp"
#include "Components/Core/Root.hpp"
#include "Components/Tabs/TabBase.hpp"
#include "DataInfo/HardwareSystemSpec.hpp"

#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class MemorySlotsInfo : public Root<MUI::Group>, public TabBase
    {
        MemoryModuleSpecButton mMemoryModuleSpecButton;

        MUI::Text mRAMTypeText;
        MUI::Text mSlotsCountText;
        MUI::Text mRAMMaxSizeText; // in all slots
        MUI::Group mComponent;

      public:
        MemorySlotsInfo(const DataInfo::SlotRAMSpec &ramSpec);
        virtual ~MemorySlotsInfo() = default;

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
