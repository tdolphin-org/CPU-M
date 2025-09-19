//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "SolderedMemoryInfo.hpp"

#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    SolderedMemoryInfo::SolderedMemoryInfo(const DataInfo::SolderedRAMSpec &ramSpec)
      : mRAMTypeText(ValueText("RAM Type"))
      , mRAMClockText(ValueText("RAM Clock"))
      , mRAMSizeText(ValueText("Soldered RAM size"))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::MakeObject::CLabel(MUIX_B "Soldered RAM on Mainboard specification."))
                       .tagChild(MUI::GroupBuilder()
                                     .tagColumns(6)
                                     .tagChild(LabelText(MUIX_R "Type"))
                                     .tagChild(mRAMTypeText)
                                     .tagChild(LabelText(MUIX_R "Clock"))
                                     .tagChild(mRAMClockText)
                                     .tagChild(LabelText(MUIX_R "Size"))
                                     .tagChild(mRAMSizeText)
                                     .object())
                       .object())
    {
        mRAMTypeText.setContents(ramSpec.type);
        mRAMClockText.setContents(ramSpec.clock);
        mRAMSizeText.setContents(std::to_string(ramSpec.size) + " MB");
    }
}
