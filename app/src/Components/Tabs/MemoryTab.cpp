//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "MemoryTab.hpp"

#include "AOS/Exec/Library.hpp"
#include "Core/ToString.hpp"
#include "DataInfo/HardwareSystemSpec.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "Memory/MemorySlotsInfo.hpp"
#include "Memory/SolderedMemoryInfo.hpp"

namespace Components
{
    MemoryTab::MemoryTab()
      : mTotalSystemMemoryText(ValueText("Total System Memory"))
      , mRAMSpecGroup(MUI::GroupBuilder().vertical().tagFrame(MUI::Frame::Group).tagFrameTitle("Mainboard RAM specification").object())
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::MakeObject::HVSpace())
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("System Memory")
                                     .tagColumns(2)
                                     .tagChild(LabelText(MUIX_R "Total Size:"))
                                     .tagChild(mTotalSystemMemoryText)
                                     .object())
                       .tagChild(mRAMSpecGroup)
                       .tagChild(MUI::MakeObject::HVSpace())
                       .object())
    {
        mTotalSystemMemoryText.setContents(ToString::FromBytesValue(
            AOS::Exec::Library::libAvailMem(AOS::Exec::MEMF_Type::ANY, AOS::Exec::MEMF_Avail::TOTAL), MemorySizeUnit::MegaBytes));

        auto systemKey = AOS::Exec::Library::libNewGetSystemAttrsAsString(AOS::Exec::SYSTEMINFOTYPE::SYSTEM);
        auto hardwareSpec = DataInfo::FindHardwareSystemSpecByID(systemKey);
        if (!hardwareSpec.has_value())
            return;

        const auto &spec = hardwareSpec.value();
        std::vector<std::string> totalPossibleRAM;

        if (spec.solderedRAM.has_value())
        {
            mRAMSpecGroup.AddTail(SolderedMemoryInfo(spec.solderedRAM.value()).muiObject());
            mRAMSpecGroup.AddTail(MUI::MakeObject::HBar(0));
            totalPossibleRAM.push_back(std::to_string(spec.solderedRAM->size));
        }

        if (!spec.RAM.empty()) // any RAM slots
        {
            mRAMSpecGroup.AddTail(MUI::MakeObject::CLabel(
                MUIX_B "Memory slots." + std::string(spec.RAM.size() > 1 ? MUIX_N "\nMay vary depending on system/mainboard model." : "")));
            if (spec.RAM.size() > 1)
                mRAMSpecGroup.AddTail(MUI::MakeObject::HBar(0));
        }

        bool first = true;
        for (const auto &ramType : spec.RAM)
        {
            if (!first)
                mRAMSpecGroup.AddTail(MUI::MakeObject::FreeCLabel1("or"));
            mMemorySlotsInfos.push_back(new MemorySlotsInfo(ramType));
            mRAMSpecGroup.AddTail(mMemorySlotsInfos.back()->muiObject());
            totalPossibleRAM.push_back(std::to_string(ramType.max + (spec.solderedRAM.has_value() ? spec.solderedRAM->size : 0)));
            first = false;
        }

        if (spec.solderedRAM.has_value())
        {
            mRAMSpecGroup.AddTail(MUI::MakeObject::HBar(0));
            mRAMSpecGroup.AddTail(MUI::MakeObject::FreeCLabel1("Up to " + ToString::Concatenate(totalPossibleRAM, " or ")
                                                               + " MB RAM supported (soldered and slots combined)"));
        }

        if (spec.ramNotes.has_value()) // Additional Notes regarding Mainboard RAM
        {
            mRAMSpecGroup.AddTail(MUI::MakeObject::HBar(0));
            mRAMSpecGroup.AddTail(MUI::TextBuilder()
                                      .tagFrame(MUI::Frame::Text)
                                      .tagHelpNode("Additional Notes regarding Mainboard RAM")
                                      .tagContents(spec.ramNotes.value())
                                      .object());
        }
    }

    MemoryTab::~MemoryTab()
    {
        for (auto *pButton : mMemorySlotsInfos)
            delete pButton;
    }
}
