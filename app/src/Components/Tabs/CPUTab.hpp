//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "AOS/Exec/Library.hpp"
#include "Components/Base.hpp"
#include "Components/Core/Root.hpp"
#include "Components/MCC/ActionCycle.hpp"
#include "Components/Tabs/CPU/CPUInfo.hpp"
#include "MUI/Cycle.hpp"
#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class CPUTab : public Root<MUI::Group>, public Base, public MCC::ActionCycleDispatcher
    {
        std::vector<AOS::Exec::CPUInfo> mCPUInfos;

        MUI::Group mCPUInfoGroup;
        MUI::Cycle mCPUOrCoreCycle;
        MUI::Text mCPUCountText;

        MUI::Group mComponent;

      public:
        CPUTab();

      protected:
        // implements pure virtual MCC::ActionCycleDispatcher
        unsigned long OnCycle();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
