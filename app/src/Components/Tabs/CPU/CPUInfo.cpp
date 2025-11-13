//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "CPUInfo.hpp"

#include "AOS/Expansion/ValueTypes/ManufacturerID.hpp"
#include "AppContext.hpp"
#include "Core/ToString.hpp"
#include "FileResources/CPUImages.hpp"
#include "MUI/Core/MakeObject.hpp"

#include <cmath>
#include <iomanip>
#include <numeric>

static std::map<std::string, std::string> ppc_family2image = {
    { "G2", CPUImageFile::ppcG2 },
    { "G3", CPUImageFile::ppcG3 },
    { "G4", CPUImageFile::ppcG4 },
    { "G5", CPUImageFile::ppcG5 },
};

static std::string GetImageForCPU(const std::string &cpuFamily)
{
    if (ppc_family2image.find(cpuFamily) != ppc_family2image.end())
        return ppc_family2image.at(cpuFamily);
    return CPUImageFile::ppc;
}

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
      , mAdditionalUnits(ValueText("Additional/Integrated Units like FPU, Altivec, ...", "--", true))
      , mCPUImage(MUI::ImageBuilder()
                      .tagSpecPicture(GetImageForCPU(cpuInfo.family))
                      .tagFixWidth(128)
                      .tagFixHeight(128)
                      .tagFreeHoriz(true)
                      .tagFreeVert(true)
                      .object())
      , mCPUClockText(ValueText("CPU clock", ToString::FromClockHertzValue(cpuInfo.clock, true)))
      , mCPUMultiplerText(ValueText("Multiplier", CPUInfo::CalculateMultiplier(cpuInfo.clock, cpuInfo.busClock)))
      , mCPUBusSpeedText(ValueText("Bus Speed", cpuInfo.busClock > 0 ? ToString::FromClockHertzValue(cpuInfo.busClock, true) : "--"))
      , mCPUL1InstructionCacheText(ValueText("Level 1 Instructions Cache size",
                                             cpuInfo.l1InstructionCache > 0 ? ToString::FromBytesValue(cpuInfo.l1InstructionCache) : "--"))
      , mCPUL1DataCacheText(
            ValueText("Level 1 Data Cache size", cpuInfo.l1DataCache > 0 ? ToString::FromBytesValue(cpuInfo.l1DataCache) : "--"))
      , mCPUL2InstructionCacheText(ValueText("Level 2 Instruction Cache size",
                                             cpuInfo.l2InstructionCache > 0 ? ToString::FromBytesValue(cpuInfo.l2InstructionCache) : "--"))
      , mCPUL2DataCacheText(
            ValueText("Level 2 Data Cache size", cpuInfo.l2DataCache > 0 ? ToString::FromBytesValue(cpuInfo.l2DataCache) : "--"))
      , mCPUL3InstructionCacheText(ValueText("Level 3 Instructions Cache size",
                                             cpuInfo.l3InstructionCache > 0 ? ToString::FromBytesValue(cpuInfo.l3InstructionCache) : "--"))
      , mCPUL3DataCacheText(
            ValueText("Level 3 Data Cache size", cpuInfo.l3DataCache > 0 ? ToString::FromBytesValue(cpuInfo.l3DataCache) : "--"))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Processor")
                                     .tagChild(MUI::GroupBuilder()
                                                   .horizontal()
                                                   .tagChild(MUI::GroupBuilder()
                                                                 .tagChild(MUI::GroupBuilder()
                                                                               .tagColumns(6)
                                                                               .tagChild(LabelText(MUIX_R "Vendor:"))
                                                                               .tagChild(mCPUVendorText)
                                                                               .tagChild(LabelText(MUIX_R "Family:"))
                                                                               .tagChild(mCPUFamilyText)
                                                                               .tagChild(LabelText(MUIX_R "Name:"))
                                                                               .tagChild(mCPUNameText)
                                                                               .tagChild(LabelText(MUIX_R "Version:"))
                                                                               .tagChild(mCPUVersionText)
                                                                               .tagChild(LabelText(MUIX_R "Revision:"))
                                                                               .tagChild(mCPURevisionText)
                                                                               .tagChild(LabelText(MUIX_R "Core Voltage:"))
                                                                               .tagChild(mCPUCoreVoltageText)
                                                                               .tagChild(LabelText(MUIX_R "Technology:"))
                                                                               .tagChild(mCPUTechnologyText)
                                                                               .tagChild(LabelText(MUIX_R "Max TDP:"))
                                                                               .tagChild(mCPUTDPText)
                                                                               .tagChild(LabelText(MUIX_R "Premiere:"))
                                                                               .tagChild(mCPUPremiereYearText)
                                                                               .object())
                                                                 .tagChild(MUI::MakeObject::HBar(0))
                                                                 .tagChild(MUI::GroupBuilder()
                                                                               .horizontal()
                                                                               .tagChild(LabelText(MUIX_R "Additional Units:"))
                                                                               .tagChild(mAdditionalUnits)
                                                                               .object())
                                                                 .object())
                                                   .tagChild(mCPUImage)
                                                   .object())
                                     .object())
                       .tagChild(MUI::GroupBuilder()
                                     .horizontal()
                                     .tagChild(MUI::GroupBuilder()
                                                   .tagFrame(MUI::Frame::Group)
                                                   .tagFrameTitle("Clocks")
                                                   .tagColumns(4)
                                                   .tagChild(LabelText(MUIX_R "Core Speed:"))
                                                   .tagChild(mCPUClockText)
                                                   .tagChild(LabelText(MUIX_R "Multiplier:"))
                                                   .tagChild(mCPUMultiplerText)
                                                   .tagChild(LabelText(MUIX_R "Bus Speed:"))
                                                   .tagChild(mCPUBusSpeedText)
                                                   .object())
                                     .tagChild(MUI::GroupBuilder()
                                                   .tagFrame(MUI::Frame::Group)
                                                   .tagFrameTitle("Cache")
                                                   .tagColumns(4)
                                                   .tagChild(LabelText(MUIX_R "L1 Inst.:"))
                                                   .tagChild(mCPUL1InstructionCacheText)
                                                   .tagChild(LabelText(MUIX_R "L1 Data:"))
                                                   .tagChild(mCPUL1DataCacheText)
                                                   .tagChild(LabelText(MUIX_R "L2 Inst.:"))
                                                   .tagChild(mCPUL2InstructionCacheText)
                                                   .tagChild(LabelText(MUIX_R "L2 Data:"))
                                                   .tagChild(mCPUL2DataCacheText)
                                                   .tagChild(LabelText(MUIX_R "L3 Inst.:"))
                                                   .tagChild(mCPUL3InstructionCacheText)
                                                   .tagChild(LabelText(MUIX_R "L3 Data:"))
                                                   .tagChild(mCPUL3DataCacheText)
                                                   .object())
                                     .object())
                       .object())
    {
        std::vector<std::string> additionalUnits;
        if (cpuInfo.hasFPU)
            additionalUnits.push_back("FPU");
        if (cpuInfo.hasAltivec)
            additionalUnits.push_back("Altivec");
        if (cpuInfo.hasPerformanceMeasurement)
            additionalUnits.push_back("Performance Measurement");
        if (cpuInfo.hasDataStream)
            additionalUnits.push_back("DataStream");

        mAdditionalUnits.setContents(
            std::accumulate(additionalUnits.begin(), additionalUnits.end(), std::string(""),
                            [](const std::string &a, const std::string &b) { return a + (a.empty() ? "" : ", ") + b; }));
    }

    std::string CPUInfo::CalculateMultiplier(unsigned long long cpuClock, unsigned long long busClock)
    {
        if (busClock == 0)
            return "--";

        double multiplier = static_cast<double>(cpuClock) / static_cast<double>(busClock);
        double rounded = std::round(multiplier * 2.0) / 2.0;

        std::ostringstream stream;
        stream << std::fixed << std::setprecision(rounded == std::floor(rounded) ? 0 : 1) << rounded;

        return stream.str() + " x";
    }
}
