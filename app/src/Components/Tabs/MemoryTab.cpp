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

namespace Components
{
    MemoryTab::MemoryTab()
      : mTotalSystemMemoryText(ValueText("Total System Memory"))
      , mRAMSpecText(ValueText("Mainboard RAM specification, can be multiple types if mainboard has multiple models"))
      , mRAMNoteText(ValueText("Additional Notes regarding Mainboard RAM"))
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
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Mainboard RAM")
                                     .tagColumns(2)
                                     .tagChild(LabelText(MUIX_R "Specification"))
                                     .tagChild(mRAMSpecText)
                                     .tagChild(LabelText(MUIX_R "Additional Notes"))
                                     .tagChild(mRAMNoteText)
                                     .object())
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
        if (!spec.RAM.empty())
        {
            auto content = ToString::Concatenate(
                [&]() -> std::vector<std::string> {
                    std::vector<std::string> lines;
                    for (const auto &ramType : spec.RAM)
                        lines.push_back(ramType.type + " " + ramType.speed + ", up to " + std::to_string(ramType.max) + " MB in "
                                        + std::to_string(ramType.slots) + " slot(s)");
                    return lines;
                }(),
                "\nor\n");

            mRAMSpecText.setContents(content);
        }

        if (spec.ramNotes.has_value())
            mRAMNoteText.setContents(spec.ramNotes.value());
    }
}
