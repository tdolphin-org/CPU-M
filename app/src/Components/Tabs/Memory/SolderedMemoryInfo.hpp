//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "Components/Base.hpp"
#include "DataInfo/HardwareSystemSpec.hpp"

#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class SolderedMemoryInfo : public Root<MUI::Group>, public Base
    {
        MUI::Text mRAMTypeText;
        MUI::Text mRAMClockText;
        MUI::Text mRAMTransferRateText;
        MUI::Text mRAMSizeText;

        MUI::Group mComponent;

      public:
        SolderedMemoryInfo(const DataInfo::SolderedRAMSpec &ramSpec);

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
