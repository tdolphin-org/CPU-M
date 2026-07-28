//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Base.hpp"
#include "Components/Core/Root.hpp"
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
        explicit SolderedMemoryInfo(const DataInfo::SolderedRAMSpec &ramSpec);

      protected:
        MUI::Group &muiRoot() const override
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
