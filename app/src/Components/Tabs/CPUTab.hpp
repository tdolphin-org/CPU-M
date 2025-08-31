//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "AOS/Exec/Library.hpp"
#include "Components/Core/Root.hpp"
#include "Components/MCC/ActionCycle.hpp"
#include "Components/Tabs/CPU/CPUInfo.hpp"
#include "Components/Tabs/TabBase.hpp"
#include "MUI/Cycle.hpp"
#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class CPUTab : public Root<MUI::Group>, public TabBase, public MCC::ActionCycleDispatcher
    {
        static const char *mSocket[];

        std::vector<AOS::Exec::CPUInfo> mCPUInfos;

        CPUInfo mCPUInfo;
        MUI::Group mCPUInfoGroup;
        MUI::Cycle mSelectionCycle;
        MUI::Text mCPUCores;
        MUI::Text mCPUThreads;

        MUI::Group mComponent;

      public:
        CPUTab();

        void ShowInfo(const long cpuIndex = 0);

      protected:
        // implements pure virtual MCC::ActionCycleDispatcher
        unsigned long OnCycle();

      private:
        void Clear();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
