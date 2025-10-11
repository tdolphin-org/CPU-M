//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "SolderedMemoryInfo.hpp"

#include "DataInfo/MemorySpec.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    SolderedMemoryInfo::SolderedMemoryInfo(const DataInfo::SolderedRAMSpec &ramSpec)
      : mRAMTypeText(ValueText("RAM Type"))
      , mRAMClockText(ValueText("RAM Clock"))
      , mRAMTransferRateText(ValueText("RAM Transfer Rate"))
      , mRAMSizeText(ValueText("Soldered RAM size"))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::MakeObject::CLabel(MUIX_B "Soldered memory."))
                       .tagChild(MUI::GroupBuilder()
                                     .tagColumns(8)
                                     .tagChild(LabelText(MUIX_R "Type"))
                                     .tagChild(mRAMTypeText)
                                     .tagChild(LabelText(MUIX_R "Clock"))
                                     .tagChild(mRAMClockText)
                                     .tagChild(LabelText(MUIX_R "Transfer Rate"))
                                     .tagChild(mRAMTransferRateText)
                                     .tagChild(LabelText(MUIX_R "Size"))
                                     .tagChild(mRAMSizeText)
                                     .object())
                       .object())
    {
        mRAMTypeText.setContents(std::to_string(ramSpec.type));
        auto memorySpec = DataInfo::memorySpecs.find(ramSpec.type);
        if (memorySpec != DataInfo::memorySpecs.end())
        {
            mRAMClockText.setContents(std::to_string(memorySpec->second.clockMHz) + " MHz");
            mRAMTransferRateText.setContents(std::to_string(memorySpec->second.effectiveMTs) + " MT/s");
        }
        else
        {
            mRAMClockText.setContents("--");
            mRAMTransferRateText.setContents("--");
        }
        mRAMSizeText.setContents(std::to_string(ramSpec.size) + " MB");
    }
}
