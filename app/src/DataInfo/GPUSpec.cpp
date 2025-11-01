//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GPUSpec.hpp"

// data info resources:
// ...

namespace DataInfo
{
    const std::map<GPUID, GPUSpec> gpu2spec {
        { GPUID::ATI_Rage_128_Pro,
          { ManufacturerID::ATI, "Rage 128 Pro", 1999, ArchitectureID::ATI_RAGE_4, "250nm", { std::nullopt, 2, 0, 2, 2 }, std::nullopt } },
        { GPUID::ATI_RV200, { ManufacturerID::ATI, "RV200", 2001, ArchitectureID::ATI_RAGE_7, "150nm", { std::nullopt, 2, 1, 6, 2 }, 23 } },
        { GPUID::ATI_RV200_500,
          { ManufacturerID::ATI, "RV200 500", 2001, ArchitectureID::ATI_RAGE_7, "150nm", { std::nullopt, 2, 1, 6, 2 }, 23 } },
        { GPUID::ATI_RV280, { ManufacturerID::ATI, "RV280", 2003, ArchitectureID::ATI_RAGE_7, "150nm", { std::nullopt, 4, 1, 4, 4 }, 28 } },
        { GPUID::ATI_R350, { ManufacturerID::ATI, "RV350", 2003, ArchitectureID::ATI_R300, "150nm", { std::nullopt, 8, 4, 8, 8 }, 94 } },
        { GPUID::ATI_RV350, { ManufacturerID::ATI, "RV350", 2003, ArchitectureID::ATI_R300, "130nm", { std::nullopt, 4, 2, 4, 4 }, 24 } },
        { GPUID::ATI_RV360, { ManufacturerID::ATI, "RV360", 2003, ArchitectureID::ATI_R300, "130nm", { std::nullopt, 4, 2, 4, 4 }, 24 } },
        { GPUID::ATI_RV380_XT,
          { ManufacturerID::ATI, "RV380 XT", 2004, ArchitectureID::ATI_R300, "130nm", { std::nullopt, 4, 2, 4, 4 }, 46 } },
        { GPUID::ATI_RV570,
          { ManufacturerID::ATI, "RV570", 2006, ArchitectureID::ATI_Ultra_Threaded_SE, "80nm", { std::nullopt, 36, 8, 12, 12 }, 130 } },
        { GPUID::ATI_RV670_Pro,
          { ManufacturerID::ATI,
            "RV670 Pro",
            2008,
            ArchitectureID::ATI_TeraScale,
            "55nm",
            { 320, std::nullopt, std::nullopt, 16, 16, 4 },
            145 } },
        { GPUID::ATI_M10,
          { ManufacturerID::ATI, "M10", 2003, ArchitectureID::ATI_R300, "130nm", { std::nullopt, 4, 2, 4, 4 }, std::nullopt } },
        { GPUID::ATI_M11,
          { ManufacturerID::ATI, "M11", 2003, ArchitectureID::ATI_R300, "130nm", { std::nullopt, 4, 2, 4, 4 }, std::nullopt } },
        { GPUID::ATI_M12,
          { ManufacturerID::ATI, "M12", 2004, ArchitectureID::ATI_R300, "130nm", { std::nullopt, 4, 2, 4, 4 }, std::nullopt } },
    };
}

namespace std
{
    std::string to_string(const DataInfo::ManufacturerID &manufacturer, const bool fullName)
    {
        using namespace DataInfo;

        switch (manufacturer)
        {
            case ManufacturerID::ATI:
                return std::string("ATI") + (fullName ? " (ATI Technologies Inc.)" : "");
            case ManufacturerID::AMD:
                return std::string("AMD") + (fullName ? " (Advanced Micro Devices)" : "");
            case ManufacturerID::NVIDIA:
                return std::string("NVIDIA") + (fullName ? " (NVIDIA Corporation)" : "");
            case ManufacturerID::INTEL:
                return std::string("Intel") + (fullName ? " (Intel Corporation)" : "");
            case ManufacturerID::SIS:
                return std::string("SiS") + (fullName ? " (Silicon Integrated Systems)" : "");
            case ManufacturerID::XGI:
                return std::string("XGI") + (fullName ? " (XGI Technology)" : "");
            case ManufacturerID::THREE_D_LABS:
                return std::string("3D Labs") + (fullName ? " (3D Labs, Inc.)" : "");
            default:
                return "Unknown Manufacturer";
        }
    }

    std::string to_string(const DataInfo::ArchitectureID &architecture)
    {
        switch(architecture)
        {
            case DataInfo::ArchitectureID::ATI_RAGE_4:
                return "Rage 4";
            case DataInfo::ArchitectureID::ATI_RAGE_5:
                return "Rage 5";
            case DataInfo::ArchitectureID::ATI_RAGE_6:
                return "Rage 6";
            case DataInfo::ArchitectureID::ATI_RAGE_7:
                return "Rage 7";
            case DataInfo::ArchitectureID::ATI_R300:
                return "R300";
            case DataInfo::ArchitectureID::ATI_R400:
                return "R400";
            case DataInfo::ArchitectureID::ATI_Ultra_Threaded_SE:
                return "Ultra Threaded SE";
            case DataInfo::ArchitectureID::ATI_TeraScale:
                return "TeraScale";
            case DataInfo::ArchitectureID::ATI_TeraScale_2:
                return "TeraScale 2";
            case DataInfo::ArchitectureID::AMD_RDNA_1:
                return "RDNA 1";
            case DataInfo::ArchitectureID::AMD_RDNA_2:
                return "RDNA 2";
            case DataInfo::ArchitectureID::AMD_RDNA_3:
                return "RDNA 3";
            default:
                return "Unknown Architecture";
        }
    }

    std::string to_string(const DataInfo::GPUID &gpuID)
    {
        using namespace DataInfo;

        switch (gpuID)
        {
            case GPUID::ATI_Rage_128_Pro:
                return "Rage 128 Pro";
            case GPUID::ATI_RV200:
                return "RV200";
            case GPUID::ATI_RV200_500:
                return "RV200 500";
            case GPUID::ATI_RV280:
                return "RV280";
            case GPUID::ATI_R350:
                return "R350";
            case GPUID::ATI_RV350:
                return "RV350";
            case GPUID::ATI_RV360:
                return "RV360";
            case GPUID::ATI_RV380_XT:
                return "RV380 XT";
            case GPUID::ATI_RV570:
                return "RV570";
            case GPUID::ATI_RV670_Pro:
                return "RV670 Pro";
            case GPUID::ATI_M10:
                return "M10";
            case GPUID::ATI_M11:
                return "M11";
            case GPUID::ATI_M12:
                return "M12";
            default:
                return "Unknown GPU ID";
        }
    }
}
