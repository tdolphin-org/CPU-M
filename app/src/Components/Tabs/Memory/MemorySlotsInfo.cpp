//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "MemorySlotsInfo.hpp"

#include "DataInfo/MemorySpec.hpp"

namespace Components
{
    MemorySlotsInfo::MemorySlotsInfo(const DataInfo::SlotRAMSpec &ramSpec)
      : mRAMTypeText(ValueText("RAM Type"))
      , mRAMClockText(ValueText("RAM Clock"))
      , mRAMTransferRateText(ValueText("RAM Transfer Rate"))
      , mSlotsCountText(ValueText("Number of Slots"))
      , mRAMMaxSizeText(ValueText("Maximum supported RAM size (summary in all slots)"))
      , mComponent(MUI::GroupBuilder()
                       .tagColumns(10)
                       .tagChild(LabelText(MUIX_R "Type:"))
                       .tagChild(mRAMTypeText)
                       .tagChild(LabelText(MUIX_R "Clock:"))
                       .tagChild(mRAMClockText)
                       .tagChild(LabelText(MUIX_R "Transfer Rate:"))
                       .tagChild(mRAMTransferRateText)
                       .tagChild(LabelText(MUIX_R "Slots:"))
                       .tagChild(mSlotsCountText)
                       .tagChild(LabelText(MUIX_R "Max Size:"))
                       .tagChild(mRAMMaxSizeText)
                       .object())
    {
        auto memorySpec = DataInfo::memorySpecs.find(ramSpec.type);
        if (memorySpec != DataInfo::memorySpecs.end())
        {
            mRAMTypeText.setContents(std::to_string(ramSpec.type) + " " + std::to_string(memorySpec->second.generation) + " "
                                     + std::to_string(ramSpec.form));
            mRAMClockText.setContents(std::to_string(memorySpec->second.clockMHz) + " MHz");
            mRAMTransferRateText.setContents(std::to_string(memorySpec->second.effectiveMTs) + " MT/s");
        }
        else
        {
            mRAMTypeText.setContents(std::to_string(ramSpec.type) + " " + std::to_string(ramSpec.form));
            mRAMClockText.setContents("--");
            mRAMTransferRateText.setContents("--");
        }
        mSlotsCountText.setContents(std::to_string(ramSpec.slots));
        mRAMMaxSizeText.setContents(std::to_string(ramSpec.max) + " MB");
    }
}
