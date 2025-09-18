//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "MemoryTab.hpp"

#include "AOS/Exec/Library.hpp"
#include "Core/ToString.hpp"
#include "DataInfo/HardwareSystemSpec.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "Memory/MemorySlotsInfo.hpp"

namespace Components
{
    MemoryTab::MemoryTab()
      : mTotalSystemMemoryText(ValueText("Total System Memory"))
      , mRAMSpecGroup(MUI::GroupBuilder()
                          .vertical()
                          .tagFrame(MUI::Frame::Group)
                          .tagFrameTitle("Mainboard RAM")
                          .tagChild(MUI::MakeObject::CLabel(
                              "Mainboard RAM specification. Can be multiple types if system/mainboard has multiple models."))
                          .tagChild(MUI::MakeObject::HBar(0))
                          .object())
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::MakeObject::HVSpace())
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("System Memory")
                                     .tagColumns(2)
                                     .tagChild(LabelText(MUIX_R "Total Size"))
                                     .tagChild(mTotalSystemMemoryText)
                                     .object())
                       .tagChild(mRAMSpecGroup)
                       .tagChild(MUI::MakeObject::HVSpace())
                       .object())
    {
        mTotalSystemMemoryText.setContents(ToString::FromBytesValue(
            AOS::Exec::Library::libAvailMem(AOS::Exec::MEMF_Type::ANY, AOS::Exec::MEMF_Avail::TOTAL), MemorySizeUnit::MegaBytes));

        auto systemKey = AOS::Exec::Library::libNewGetSystemAttrsAsString(AOS::Exec::SYSTEMINFOTYPE::SYSTEM);
        auto hardwareSpec = DataInfo::hardwareSystem2spec.find(systemKey);
        if (hardwareSpec == DataInfo::hardwareSystem2spec.end())
            return;
        const auto &spec = hardwareSpec->second;
        bool first = true;
        for (const auto &ramType : spec.RAM)
        {
            if (!first)
                mRAMSpecGroup.AddTail(MUI::MakeObject::FreeCLabel1("or"));
            mRAMSpecGroup.AddTail(MemorySlotsInfo(ramType).muiObject());
            first = false;
        }

        if (spec.maxRAMSize.has_value())
        {
            mRAMSpecGroup.AddTail(MUI::MakeObject::HBar(0));
            mRAMSpecGroup.AddTail(MUI::MakeObject::FreeCLabel1(std::to_string(spec.maxRAMSize.value())
                                                               + " MB maximum RAM size supported in all slots with soldered RAM"));
        }

        if (spec.ramNotes.has_value()) // Additional Notes regarding Mainboard RAM
        {
            mRAMSpecGroup.AddTail(MUI::MakeObject::HBar(0));
            mRAMSpecGroup.AddTail(MUI::TextBuilder()
                                      .tagFrame(MUI::Frame::String)
                                      .tagHelpNode("Add Notes regarding Mainboard RAM")
                                      .tagContents(spec.ramNotes.value())
                                      .object());
        }
    }
}
