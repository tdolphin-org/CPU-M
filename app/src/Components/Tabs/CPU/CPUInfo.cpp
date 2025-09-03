//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "CPUInfo.hpp"

#include "AOS/Expansion/ValueTypes/ManufacturerID.hpp"
#include "AppContext.hpp"
#include "FileResources/CPUImages.hpp"
#include "Core/ToString.hpp"

#include <numeric>

std::map<std::string, std::string> ppc_cpu2image = {
    { "Unknown", CPUImageFile::ppc },  { "602", CPUImageFile::ppc602 },   { "603", CPUImageFile::ppc603 },
    { "603E", CPUImageFile::ppc603e }, { "603P", CPUImageFile::ppc603p }, { "604", CPUImageFile::ppc604 },
    { "604E", CPUImageFile::ppc604e }, { "620", CPUImageFile::ppc620 },   { "7400", CPUImageFile::ppc },
    { "7447A", CPUImageFile::ppc },
};

namespace Components
{
    CPUInfo::CPUInfo(const AOS::Exec::CPUInfo &cpuInfo)
      : mCPUSpec(DataInfo::cpuPPC2spec.at([&]() {
          auto pos = DataInfo::cpuPPC2spec.find(cpuInfo.name);
          if (pos != DataInfo::cpuPPC2spec.end())
              return cpuInfo.name;
          return std::string("Unknown");
      }()))
      , mCPUVendorText(ValueText("Vendor of CPU", mCPUSpec.vendor))
      , mCPUFamilyText(ValueText("Family of CPU", cpuInfo.family))
      , mCPUNameText(ValueText("Model name of CPU", cpuInfo.name))
      , mCPUVersionText(ValueText("Version of CPU", std::to_string(cpuInfo.version)))
      , mCPURevisionText(ValueText("Revision of CPU", std::to_string(cpuInfo.revision)))
      , mCPUTDPText(ValueText("Maximal Thermal Design Power", mCPUSpec.tdp))
      , mCPUCoreVoltageText(ValueText("CPU/Core Voltage", mCPUSpec.coreVoltage))
      , mCPUTechnologyText(ValueText("Production Technology", mCPUSpec.technology))
      , mCPUPremiereYearText(ValueText("Year of Premiere", mCPUSpec.premiere))
      , mAdditionalUnits(ValueText("Additional Units like FPU, MMU"))
      , mCPUImage(MUI::ImageBuilder()
                      .tagSpecPicture(ppc_cpu2image.find(cpuInfo.name) != ppc_cpu2image.end() ? ppc_cpu2image.at(cpuInfo.name)
                                                                                              : CPUImageFile::ppc)
                      .tagFixWidth(80)
                      .tagFixHeight(80)
                      .tagFreeHoriz(true)
                      .tagFreeVert(true)
                      .object())
      , mCPUClockText(ValueText("CPU clock", ToString::FromClockHertzValue(cpuInfo.clock, true)))
      , mCPUMultipler(ValueText("Multiplier", CPUInfo::CalculateMultiplier(cpuInfo.clock, cpuInfo.busClock)))
      , mCPUBusSpeed(ValueText("Bus Speed", cpuInfo.busClock > 0 ? ToString::FromClockHertzValue(cpuInfo.busClock, true) : "--"))
      , mCPUL1InstructionCache(ValueText("Level 1 Instructions Cache size",
                                         cpuInfo.l1InstructionCache > 0 ? ToString::FromBytesValue(cpuInfo.l1InstructionCache) : "--"))
      , mCPUL1DataCache(
            ValueText("Level 1 Data Cache size", cpuInfo.l1DataCache > 0 ? ToString::FromBytesValue(cpuInfo.l1DataCache) : "--"))
      , mCPUL2InstructionCache(ValueText("Level 2 Instruction Cache size",
                                         cpuInfo.l2InstructionCache > 0 ? ToString::FromBytesValue(cpuInfo.l2InstructionCache) : "--"))
      , mCPUL2DataCache(
            ValueText("Level 2 Data Cache size", cpuInfo.l2DataCache > 0 ? ToString::FromBytesValue(cpuInfo.l2DataCache) : "--"))
      , mCPUL3InstructionCache(ValueText("Level 3 Instructions Cache size",
                                         cpuInfo.l3InstructionCache > 0 ? ToString::FromBytesValue(cpuInfo.l3InstructionCache) : "--"))
      , mCPUL3DataCache(
            ValueText("Level 3 Data Cache size", cpuInfo.l3DataCache > 0 ? ToString::FromBytesValue(cpuInfo.l3DataCache) : "--"))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagBackground(MUI::ImageOrBackground::WindowBack)
                                     .tagFrameTitle("Processor")
                                     .tagChild(MUI::GroupBuilder()
                                                   .horizontal()
                                                   .tagChild(MUI::GroupBuilder()
                                                                 .tagChild(MUI::GroupBuilder()
                                                                               .tagColumns(6)
                                                                               .tagChild(LabelText(MUIX_R "Vendor"))
                                                                               .tagChild(mCPUVendorText)
                                                                               .tagChild(LabelText(MUIX_R "Family"))
                                                                               .tagChild(mCPUFamilyText)
                                                                               .tagChild(LabelText(MUIX_R "Name"))
                                                                               .tagChild(mCPUNameText)
                                                                               .tagChild(LabelText(MUIX_R "Version"))
                                                                               .tagChild(mCPUVersionText)
                                                                               .tagChild(LabelText(MUIX_R "Revision"))
                                                                               .tagChild(mCPURevisionText)
                                                                               .tagChild(LabelText(MUIX_R "Core Voltage"))
                                                                               .tagChild(mCPUCoreVoltageText)
                                                                               .tagChild(LabelText(MUIX_R "Technology"))
                                                                               .tagChild(mCPUTechnologyText)
                                                                               .tagChild(LabelText(MUIX_R "Max TDP"))
                                                                               .tagChild(mCPUTDPText)
                                                                               .tagChild(LabelText(MUIX_R "Premiere"))
                                                                               .tagChild(mCPUPremiereYearText)
                                                                               .object())

                                                                 .object())
                                                   .tagChild(mCPUImage)
                                                   .object())
                                     .object())
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagBackground(MUI::ImageOrBackground::WindowBack)
                                     .tagFrameTitle("Additional/Integrated Units")
                                     .tagChild(mAdditionalUnits)
                                     .object())
                       .tagChild(MUI::GroupBuilder()
                                     .horizontal()
                                     .tagChild(MUI::GroupBuilder()
                                                   .tagFrame(MUI::Frame::Group)
                                                   .tagBackground(MUI::ImageOrBackground::WindowBack)
                                                   .tagFrameTitle("Clocks (Core #0)")
                                                   .tagColumns(4)
                                                   .tagChild(LabelText(MUIX_R "Core Speed"))
                                                   .tagChild(mCPUClockText)
                                                   .tagChild(LabelText(MUIX_R "Multiplier"))
                                                   .tagChild(mCPUMultipler)
                                                   .tagChild(LabelText(MUIX_R "Bus Speed"))
                                                   .tagChild(mCPUBusSpeed)
                                                   .object())
                                     .tagChild(MUI::GroupBuilder()
                                                   .tagFrame(MUI::Frame::Group)
                                                   .tagBackground(MUI::ImageOrBackground::WindowBack)
                                                   .tagFrameTitle("Cache")
                                                   .tagColumns(4)
                                                   .tagChild(LabelText(MUIX_R "L1 Inst."))
                                                   .tagChild(mCPUL1InstructionCache)
                                                   .tagChild(LabelText(MUIX_R "L1 Data"))
                                                   .tagChild(mCPUL1DataCache)
                                                   .tagChild(LabelText(MUIX_R "L2 Inst."))
                                                   .tagChild(mCPUL2InstructionCache)
                                                   .tagChild(LabelText(MUIX_R "L2 Data"))
                                                   .tagChild(mCPUL2DataCache)
                                                   .tagChild(LabelText(MUIX_R "L3 Inst."))
                                                   .tagChild(mCPUL3InstructionCache)
                                                   .tagChild(LabelText(MUIX_R "L3 Data"))
                                                   .tagChild(mCPUL3DataCache)
                                                   .object())
                                     .object())
                       .object())
    {
        std::vector<std::string> additionalUnits;
        if (cpuInfo.hasFPU)
            additionalUnits.push_back("FPU");
        if (cpuInfo.hasAltivec)
            additionalUnits.push_back("Altivec");

        mAdditionalUnits.setContents(
            std::accumulate(additionalUnits.begin(), additionalUnits.end(), std::string(""),
                            [](const std::string &a, const std::string &b) { return a + (a.empty() ? "" : ", ") + b; }));
    }

    std::string CPUInfo::CalculateMultiplier(unsigned long long cpuClock, unsigned long long busClock)
    {
        if (busClock == 0)
            return "--";

        unsigned long long multiplier = cpuClock / busClock;
        unsigned long long remainder = (cpuClock % busClock) / 10;
        return "x " + std::to_string(multiplier) + "." + std::to_string(remainder);
    }
}
