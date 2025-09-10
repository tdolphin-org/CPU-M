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
      , mCPUInfoGroup(MUI::GroupBuilder().tagPageMode().object())
      , mCPUOrCoreCycle(MCC::ActionCycleBuilder()
                            .tagEntries([&] {
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
                       .tagChild(MUI::MakeObject::HVSpace())
                       .tagChild(mCPUInfoGroup)
                       .tagChild(MUI::GroupBuilder()
                                     .horizontal()
                                     .tagColumns(3)
                                     .tagFrame(MUI::Frame::Group)
                                     .tagChild(LabelText(MUIX_R "CPU/Core"))
                                     .tagChild(mCPUOrCoreCycle)
                                     .tagChild(MUI::MakeObject::HVSpace())
                                     .object())
                       .tagChild(MUI::MakeObject::HVSpace())
                       .object())
    {
        for (auto &cpuInfo : mCPUInfos)
            mCPUInfoGroup.AddTail(CPUInfo(cpuInfo));
        mCPUInfoGroup.setActivePage(MUI::Group_ActivePage::First);
    }

    unsigned long CPUTab::OnCycle()
    {
        auto selection = mCPUOrCoreCycle.getActive();
        mCPUInfoGroup.setActivePage(selection);
        return 0;
    }
}
