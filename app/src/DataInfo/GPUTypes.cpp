//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GPUTypes.hpp"

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
            case ManufacturerID::_3DLABS:
                return std::string("3D Labs") + (fullName ? " (3D Labs, Inc.)" : "");
            case ManufacturerID::_3DFX:
                return std::string("3Dfx") + (fullName ? " (3Dfx Interactive, Inc.)" : "");
            case ManufacturerID::MATROX:
                return std::string("Matrox") + (fullName ? " (Matrox Graphics Inc.)" : "");
            default:
                return "Unknown Manufacturer";
        }
    }

    std::string to_string(const DataInfo::ArchitectureID &architecture)
    {
        switch (architecture)
        {
            case DataInfo::ArchitectureID::SiS_1st_Gen:
                return "SiS 1st Gen";
            case DataInfo::ArchitectureID::SiS_2nd_Gen:
                return "SiS 2nd Gen";
            case DataInfo::ArchitectureID::XG4:
                return "XG4";
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
            case GPUID::_3dfx_Avenger:
                return "Avenger";
            case GPUID::_3dfx_VSA_100:
                return "VSA-100";
            case GPUID::_3DLabs_Permedia_2:
                return "Permedia 2";
            case GPUID::_3DLabs_Permedia_2V:
                return "Permedia 2V";
            case GPUID::SiS_6326:
                return "6326";
            case GPUID::SiS_300:
                return "300";
            case GPUID::SiS_305:
                return "305";
            case GPUID::SiS_Mirage_315:
                return "Mirage 315";
            case GPUID::XGI_XG40:
                return "XG40";
            case GPUID::XGI_XG41:
                return "XG41";
            case GPUID::XGI_XG42:
                return "XG42";
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