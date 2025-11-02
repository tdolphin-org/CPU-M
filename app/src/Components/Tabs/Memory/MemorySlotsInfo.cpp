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
      : mRAMTypeText(MUI::TextBuilder().tagContents("RAM Type").object())
      , mMemoryModuleSpecButton({ ramSpec.type, ramSpec.form })
      , mSlotsCountText(ValueText("Number of Slots"))
      , mRAMMaxSizeText(ValueText("Maximum supported RAM size (summary in all slots)"))
      , mComponent(MUI::GroupBuilder()
                       .tagColumns(6)
                       .tagChild(LabelText(MUIX_R "Type:"))
                       .tagChild(MUI::GroupBuilder().horizontal().tagFrame(MUI::Frame::String).tagChild(mRAMTypeText).tagChild(mMemoryModuleSpecButton).object())
                       .tagChild(LabelText(MUIX_R "Slots:"))
                       .tagChild(mSlotsCountText)
                       .tagChild(LabelText(MUIX_R "Max Size:"))
                       .tagChild(mRAMMaxSizeText)
                       .object())
    {
        auto memorySpec = DataInfo::memorySpecs.find(ramSpec.type);
        if (memorySpec != DataInfo::memorySpecs.end())
        {
            mMemoryModuleSpecButton.Enable();
            mMemoryModuleSpecButton.muiRoot().setShortHelp("Click to view detailed specifications for this memory module type.");
            mRAMTypeText.setContents(std::to_string(memorySpec->second.generation) + " " + std::to_string(ramSpec.type) + " "
                                     + std::to_string(ramSpec.form));
        }
        else
        {
            mMemoryModuleSpecButton.Disable();
            mMemoryModuleSpecButton.muiRoot().setShortHelp("No detailed specifications available");
            mRAMTypeText.setContents(std::to_string(ramSpec.type) + " " + std::to_string(ramSpec.form));
            mSlotsCountText.setContents("--");
        }
        mSlotsCountText.setContents(std::to_string(ramSpec.slots));
        mRAMMaxSizeText.setContents(std::to_string(ramSpec.max) + " MB");
    }
}
