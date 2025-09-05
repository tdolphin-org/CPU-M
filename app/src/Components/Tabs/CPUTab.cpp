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
#include <stdexcept>

namespace Components
{
    CPUTab::CPUTab()
      : mCPUInfos(AOS::Exec::Library::GetAllCPUs())
      , mCPUInfo(mCPUInfos.at(0))
      , mCPUInfoGroup(MUI::GroupBuilder().tagPageMode().tagChild(mCPUInfo).object())
      , mSelectionCycle(MCC::ActionCycleBuilder()
                            .tagEntries([&] -> std::vector<std::string> {
                                std::vector<std::string> entries;
                                for (size_t i = 0; i < mCPUInfos.size(); i++)
                                    entries.push_back("CPU #" + std::to_string(i + 1));
                                if (!entries.empty())
                                    return entries;
                                throw std::runtime_error("No CPUs found!");
                            }())
                            .tagWeight(0)
                            .object(*this))
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
