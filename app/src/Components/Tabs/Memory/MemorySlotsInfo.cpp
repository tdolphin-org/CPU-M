//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "MemorySlotsInfo.hpp"

namespace Components
{
    MemorySlotsInfo::MemorySlotsInfo(const DataInfo::SlotRAMSpec &ramSpec)
      : mRAMTypeText(ValueText("RAM Type"))
      , mRAMClockText(ValueText("RAM Clock"))
      , mSlotsCountText(ValueText("Number of Slots"))
      , mRAMMaxSizeText(ValueText("Maximum supported RAM size (summary in all slots)"))
      , mComponent(MUI::GroupBuilder()
                       .tagColumns(8)
                       .tagChild(LabelText(MUIX_R "Type"))
                       .tagChild(mRAMTypeText)
                       .tagChild(LabelText(MUIX_R "Clock"))
                       .tagChild(mRAMClockText)
                       .tagChild(LabelText(MUIX_R "Slots"))
                       .tagChild(mSlotsCountText)
                       .tagChild(LabelText(MUIX_R "Max Size"))
                       .tagChild(mRAMMaxSizeText)
                       .object())
    {
        mRAMTypeText.setContents(ramSpec.type);
        mRAMClockText.setContents(ramSpec.clock);
        mSlotsCountText.setContents(std::to_string(ramSpec.slots));
        mRAMMaxSizeText.setContents(std::to_string(ramSpec.max) + " MB");
    }
}
