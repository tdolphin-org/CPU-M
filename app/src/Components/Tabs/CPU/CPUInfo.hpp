//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "Components/Tabs/TabBase.hpp"
#include "DataInfo/CPUSpec.hpp"

#include "AOS/Exec/Library.hpp"
#include "MUI/Group.hpp"
#include "MUI/Image.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class CPUInfo : public Root<MUI::Group>, public TabBase
    {
        static const char *mCPUs[];

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
        MUI::Text mCPUMultipler;
        MUI::Text mCPUBusSpeed;
        MUI::Text mCPUL1InstructionCache;
        MUI::Text mCPUL1DataCache;
        MUI::Text mCPUL2InstructionCache;
        MUI::Text mCPUL2DataCache;
        MUI::Text mCPUL3InstructionCache;
        MUI::Text mCPUL3DataCache;

        MUI::Group mComponent;

      public:
        CPUInfo(const AOS::Exec::CPUInfo &cpuInfo);

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }

        static std::string FromClockSpeed(unsigned long long clockSpeed);
        static std::string CalculateMultiplier(unsigned long long cpuClock, unsigned long long busClock);
    };
}
