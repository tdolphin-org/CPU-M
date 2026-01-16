//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "GPUTypes.hpp"

#include <map>

namespace std
{
    std::string to_string(const DataInfo::ManufacturerID &manufacturer, const bool fullName)
    {
        using namespace DataInfo;

        static const std::map<ManufacturerID, std::pair<std::string, std::string>> manufacturerMap = {
            { ManufacturerID::ATI, { "ATI", "ATI Technologies Inc." } },
            { ManufacturerID::AMD, { "AMD", "Advanced Micro Devices" } },
            { ManufacturerID::NVIDIA, { "NVIDIA", "NVIDIA Corporation" } },
            { ManufacturerID::INTEL, { "Intel", "Intel Corporation" } },
            { ManufacturerID::SIS, { "SiS", "Silicon Integrated Systems" } },
            { ManufacturerID::XGI, { "XGI", "XGI Technology" } },
            { ManufacturerID::_3DLABS, { "3D Labs", "3D Labs, Inc." } },
            { ManufacturerID::_3DFX, { "3Dfx", "3Dfx Interactive, Inc." } },
            { ManufacturerID::MATROX, { "Matrox", "Matrox Graphics Inc." } },
        };

        auto it = manufacturerMap.find(manufacturer);
        if (it != manufacturerMap.end())
            return it->second.first + (fullName ? " (" + it->second.second + ")" : "");

        return "Unknown Manufacturer";
    }

    std::string to_string(const DataInfo::ArchitectureID &architecture)
    {
        using namespace DataInfo;

        static const std::map<ArchitectureID, std::string> architectureMap = {
            { ArchitectureID::SiS_1st_Gen, "SiS 1st Gen" },
            { ArchitectureID::SiS_2nd_Gen, "SiS 2nd Gen" },
            { ArchitectureID::XG4, "XG4" },
            { ArchitectureID::ATI_RAGE_4, "Rage 4" },
            { ArchitectureID::ATI_RAGE_5, "Rage 5" },
            { ArchitectureID::ATI_RAGE_6, "Rage 6" },
            { ArchitectureID::ATI_RAGE_7, "Rage 7" },
            { ArchitectureID::ATI_R300, "R300" },
            { ArchitectureID::ATI_R400, "R400" },
            { ArchitectureID::ATI_Ultra_Threaded_SE, "Ultra Threaded SE" },
            { ArchitectureID::AMD_TeraScale, "TeraScale" },
            { ArchitectureID::AMD_TeraScale_2, "TeraScale 2" },
            { ArchitectureID::AMD_TeraScale_3, "TeraScale 3" },
            { ArchitectureID::AMD_GCN_1_0, "GNC 1.0" },
            { ArchitectureID::AMD_GCN_2_0, "GNC 2.0" },
            { ArchitectureID::AMD_GCN_3_0, "GNC 3.0" },
            { ArchitectureID::AMD_GCN_4_0, "GNC 4.0" },
            { ArchitectureID::AMD_GCN_5_0, "GNC 5.0" },
            { ArchitectureID::AMD_GCN_5_1, "GNC 5.1" },
            { ArchitectureID::AMD_RDNA_1_0, "RDNA 1.0" },
            { ArchitectureID::AMD_RDNA_2_0, "RDNA 2.0" },
            { ArchitectureID::AMD_RDNA_3_0, "RDNA 3.0" },
        };

        auto it = architectureMap.find(architecture);
        if (it != architectureMap.end())
            return it->second;

        return "Unknown Architecture";
    }

    std::string to_string(const DataInfo::GPUID &gpuID)
    {
        using namespace DataInfo;

        static const std::map<GPUID, std::string> gpuIDMap = {
            { GPUID::_3dfx_Avenger, "Avenger" },
            { GPUID::_3dfx_VSA_100, "VSA-100" },
            { GPUID::_3DLabs_Permedia_2, "Permedia 2" },
            { GPUID::_3DLabs_Permedia_2V, "Permedia 2V" },
            { GPUID::SiS_6326, "6326" },
            { GPUID::SiS_300, "300" },
            { GPUID::SiS_305, "305" },
            { GPUID::SiS_Mirage_315, "Mirage 315" },
            { GPUID::XGI_XG40, "XG40" },
            { GPUID::XGI_XG41, "XG41" },
            { GPUID::XGI_XG42, "XG42" },
            { GPUID::ATI_Rage_128_Pro, "Rage 128 Pro" },
            { GPUID::ATI_R200, "R200" },
            { GPUID::ATI_RV200, "RV200" },
            { GPUID::ATI_RV280, "RV280" },
            { GPUID::ATI_R350, "R350" },
            { GPUID::ATI_RV350, "RV350" },
            { GPUID::ATI_RV360, "RV360" },
            { GPUID::ATI_RV380, "RV380" },
            { GPUID::ATI_RV535, "RV535" },
            { GPUID::ATI_RV570, "RV570" },
            { GPUID::ATI_R580_PLUS, "R580+" },
            { GPUID::ATI_RV620, "RV620" },
            { GPUID::ATI_RV670, "RV670" },
            { GPUID::ATI_RV730, "RV730" },
            { GPUID::AMD_BARTS, "Barts" },
            { GPUID::AMD_CAICOS, "Caicos" },
            { GPUID::AMD_TURKS, "Turks" },
            { GPUID::AMD_REDWOOD, "Redwood" },
            { GPUID::AMD_BAFFIN, "Baffin" },
            { GPUID::AMD_NAVI_24, "Navi 24" },
            { GPUID::ATI_M10, "M10" },
            { GPUID::ATI_M11, "M11" },
            { GPUID::ATI_M12, "M12" },
        };

        auto it = gpuIDMap.find(gpuID);
        if (it != gpuIDMap.end())
            return it->second;

        return "Unknown GPU ID";
    }

    std::string to_string(const DataInfo::GPUVariantID &gpuVariantID)
    {
        using namespace DataInfo;

        static const std::map<GPUVariantID, std::string> gpuVariantIDMap = {
            { GPUVariantID::ATI_RV200_7500, "RV200 7500" },       { GPUVariantID::ATI_RV200_7500_LE, "RV200 7500 LE" },
            { GPUVariantID::ATI_RV280_9200_SE, "RV280 9200 SE" }, { GPUVariantID::ATI_RV350_LX, "RV350 LX" },
            { GPUVariantID::ATI_RV350_LE, "RV350 LE" },           { GPUVariantID::ATI_RV350_SE, "RV350 SE" },
            { GPUVariantID::ATI_RV380_XT, "RV380 XT" },           { GPUVariantID::ATI_RV535_XT, "RV535 XT" },
            { GPUVariantID::ATI_RV570_XL, "RV570 XL" },           { GPUVariantID::ATI_R580_PLUS_XT, "R580+ XT" },
            { GPUVariantID::ATI_RV620_LE, "RV620 LE" },           { GPUVariantID::ATI_RV670_Pro, "RV670 Pro" },
            { GPUVariantID::ATI_RV730_XT, "RV730 XT" },           { GPUVariantID::AMD_BARTS_XT, "Barts XT" },
            { GPUVariantID::AMD_KHALIDSTER, "Khalidster" },       { GPUVariantID::AMD_CAICOS_XT, "Caicos XT" },
            { GPUVariantID::AMD_CAICOS_PRO, "Caicos Pro" },       { GPUVariantID::AMD_TURKS_LE, "Turks LE" },
            { GPUVariantID::AMD_TURKS_PRO, "Turks Pro" },         { GPUVariantID::AMD_TURKS_PRO_L, "Turks PRO-L" },
            { GPUVariantID::AMD_REDWOOD_PRO, "Redwood Pro" },     { GPUVariantID::AMD_BAFFIN_PRO, "Baffin Pro" },
            { GPUVariantID::AMD_NAVI_24_XL, "Navi 24 XL" },
        };

        auto it = gpuVariantIDMap.find(gpuVariantID);
        if (it != gpuVariantIDMap.end())
            return it->second;

        return "Unknown GPU Variant ID";
    }
}