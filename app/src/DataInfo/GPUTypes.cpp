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
            case DataInfo::ArchitectureID::AMD_TeraScale:
                return "TeraScale";
            case DataInfo::ArchitectureID::AMD_TeraScale_2:
                return "TeraScale 2";
            case DataInfo::ArchitectureID::AMD_TeraScale_3:
                return "TeraScale 3";
            case DataInfo::ArchitectureID::AMD_GCN_1_0:
                return "GNC 1.0";
            case DataInfo::ArchitectureID::AMD_GCN_2_0:
                return "GNC 2.0";
            case DataInfo::ArchitectureID::AMD_GCN_3_0:
                return "GNC 3.0";
            case DataInfo::ArchitectureID::AMD_GCN_4_0:
                return "GNC 4.0";
            case DataInfo::ArchitectureID::AMD_GCN_5_0:
                return "GNC 5.0";
            case DataInfo::ArchitectureID::AMD_GCN_5_1:
                return "GNC 5.1";
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
            case GPUID::ATI_RV280:
                return "RV280";
            case GPUID::ATI_R350:
                return "R350";
            case GPUID::ATI_RV350:
                return "RV350";
            case GPUID::ATI_RV360:
                return "RV360";
            case GPUID::ATI_RV380:
                return "RV380";
            case GPUID::ATI_RV570:
                return "RV570";
            case GPUID::ATI_R580_PLUS:
                return "R580+";
            case GPUID::ATI_RV620:
                return "RV620";
            case GPUID::ATI_RV670:
                return "RV670";
            case GPUID::ATI_RV730:
                return "RV730";
            case GPUID::AMD_BARTS:
                return "Barts";
            case GPUID::AMD_CAICOS:
                return "Caicos";
            case GPUID::AMD_BAFFIN:
                return "Baffin";
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

    std::string to_string(const DataInfo::GPUVariantID &gpuVariantID)
    {
        using namespace DataInfo;

        switch (gpuVariantID)
        {
            case GPUVariantID::ATI_RV200_7500:
                return "RV200 7500";
            case GPUVariantID::ATI_RV200_7500_LE:
                return "RV200 7500 LE";
            case GPUVariantID::ATI_RV280_9200_SE:
                return "RV280 9200 SE";
            case GPUVariantID::ATI_RV380_XT:
                return "RV380 XT";
            case GPUVariantID::ATI_R580_PLUS_XT:
                return "R580+ XT";
            case GPUVariantID::ATI_RV620_LE:
                return "RV620 LE";
            case GPUVariantID::ATI_RV670_Pro:
                return "RV670 Pro";
            case GPUVariantID::ATI_RV730_XT:
                return "RV730 XT";
            case GPUVariantID::AMD_BARTS_XT:
                return "Barts XT";
            case GPUVariantID::AMD_CAICOS_PRO:
                return "Caicos Pro";
            case GPUVariantID::AMD_BAFFIN_PRO:
                return "Baffin Pro";
            default:
                return "Unknown GPU Variant ID";
        }
    }
}