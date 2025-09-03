//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "CPUTab.hpp"

#include "AOS/Exec/Library.hpp"
#include "DataInfo/CPUSpec.hpp"
#include "FileResources/CPUImages.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Image.hpp"

#include <numeric>

namespace Components
{
    const char *CPUTab::mSocket[] = { "CPU #1", "CPU #2", nullptr };

    CPUTab::CPUTab()
      : mCPUInfos(AOS::Exec::Library::GetAllCPUs())
      , mCPUInfo(mCPUInfos.at(0))
      , mCPUInfoGroup(MUI::GroupBuilder().tagPageMode().tagChild(mCPUInfo).object())
      , mSelectionCycle(MCC::ActionCycleBuilder().tagEntries(mSocket).tagWeight(0).object(*this))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(mCPUInfoGroup)
                       .tagChild(MUI::GroupBuilder()
                                     .horizontal()
                                     .tagColumns(3)
                                     .tagFrame(MUI::Frame::Group)
                                     .tagChild(LabelText(MUIX_R "Slot/CPU"))
                                     .tagChild(mSelectionCycle)
                                     .tagChild(MUI::MakeObject::HVSpace())
                                     .object())
                       .object())
    {
        ShowInfo();
    }

    void CPUTab::ShowInfo(const long cpuIndex)
    {
        auto selection = mSelectionCycle.getActive();
        auto &cpuInfo = mCPUInfos.at(cpuIndex);

        // todo
        // auto &cpuSpec = DataInfo::cpuPPC2spec.at(cpuInfo.model.ppc);
    }

    unsigned long CPUTab::OnCycle()
    {
        auto selection = mSelectionCycle.getActive();
        ShowInfo(selection);
        mCPUInfoGroup.setActivePage(selection);
        return 0;
    }
}
