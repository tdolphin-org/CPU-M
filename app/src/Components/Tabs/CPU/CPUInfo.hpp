//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Base.hpp"
#include "Components/Core/Root.hpp"
#include "DataInfo/CPUSpec.hpp"

#include "AOS/Exec/Library.hpp"
#include "MUI/Group.hpp"
#include "MUI/Image.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class CPUInfo : public Root<MUI::Group>, public Base
    {
        DataInfo::CPUSpec mCPUSpec;

        MUI::Text mCPUVendorText;
        MUI::Text mCPUFamilyText;
        MUI::Text mCPUNameText;
        MUI::Text mCPUVersionText;
        MUI::Text mCPURevisionText;
        MUI::Text mCPUTDPText;
        MUI::Text mCPUCoreVoltageText;
        MUI::Text mCPUTechnologyText;
        MUI::Text mCPUPremiereYearText;
        MUI::Text mAdditionalUnits; // like FPU, Altivec
        MUI::Image mCPUImage;
        MUI::Text mCPUClockText;
        MUI::Text mCPUMultiplerText;
        MUI::Text mCPUBusSpeedText;
        MUI::Text mCPUL1InstructionCacheText;
        MUI::Text mCPUL1DataCacheText;
        MUI::Text mCPUL2InstructionCacheText;
        MUI::Text mCPUL2DataCacheText;
        MUI::Text mCPUL3InstructionCacheText;
        MUI::Text mCPUL3DataCacheText;

        MUI::Group mComponent;

      public:
        CPUInfo(const AOS::Exec::CPUInfo &cpuInfo);

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }

        static std::string CalculateMultiplier(unsigned long long cpuClock, unsigned long long busClock);
    };
}
