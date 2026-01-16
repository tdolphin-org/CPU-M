//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#pragma once

#include <string>

namespace DataInfo
{
    enum class ManufacturerID
    {
        ATI,
        AMD,
        NVIDIA,
        INTEL,
        SIS,
        XGI,
        _3DLABS, // 3Dlabs
        _3DFX, // 3dfx
        MATROX, // Matrox
    };

    enum class ArchitectureID
    {
        // SIS
        SiS_1st_Gen,
        SiS_2nd_Gen,

        // XGI
        XG4,

        // ATI/AMD Architectures
        ATI_RAGE_4,
        ATI_RAGE_5,
        ATI_RAGE_6,
        ATI_RAGE_7,
        ATI_R300,
        ATI_R400,
        ATI_Ultra_Threaded_SE,
        AMD_TeraScale, // ATI/AMD TeraScale
        AMD_TeraScale_2,
        AMD_TeraScale_3,
        AMD_GCN_1_0,
        AMD_GCN_2_0,
        AMD_GCN_3_0,
        AMD_GCN_4_0,
        AMD_GCN_5_0,
        AMD_GCN_5_1,
        AMD_RDNA_1_0,
        AMD_RDNA_2_0,
        AMD_RDNA_3_0,
        // ... add more architectures as needed
    };

    /// @brief Graphics Chip Identifiers (or Variants) supported by CPU-M and MorphOS
    enum class GPUID
    {
        // 3dfx Voodoo series
        _3dfx_Avenger,
        _3dfx_VSA_100,

        // 3D Labs Permedia series
        _3DLabs_Permedia_2,
        _3DLabs_Permedia_2V,

        // SiS series
        SiS_6326,
        SiS_300,
        SiS_305,
        SiS_Mirage_315,

        // XGI Volari series
        XGI_XG40,
        XGI_XG41,
        XGI_XG42,

        // ATI/AMD series
        ATI_Rage_128_Pro, // Rage 128 Pro
        ATI_R200, // R200
        ATI_RV200, // RV200
        ATI_RV280, // RV280
        ATI_RV350, // RV350
        ATI_R350, // R350
        ATI_RV360, // RV360
        ATI_RV380, // RV380
        ATI_RV535, // RV535
        ATI_RV570, // RV570
        ATI_R580_PLUS, // R580+
        ATI_RV620, // RV620
        ATI_RV670, // RV670
        ATI_RV730, // RV730
        AMD_BARTS, // Barts
        AMD_CAICOS, // Caicos
        AMD_TURKS, // Turks
        AMD_REDWOOD, // Redwood
        AMD_BAFFIN, // Baffin
        AMD_NAVI_24, // Navi 24
        ATI_M10, // Mobility M10
        ATI_M11, // Mobility M11
        ATI_M12, // Mobility M12
    };

    enum class GPUVariantID
    {
        ATI_RV200_7500, // RV200 7500 (variant of RV200) used by Radeon 7500
        ATI_RV200_7500_LE, // RV200 7500 LE (variant of RV200) used by Radeon 7500 LE
        ATI_RV280_9200_SE, // RV280 9200 SE (variant of RV280) used by Radeon 9200 SE
        ATI_RV350_LX, // RV350 LX (variant of RV350) used by Radeon 9550
        ATI_RV350_LE, // RV350 LE (variant of RV350) used by Radeon 9600
        ATI_RV350_SE, // RV350 SE (variant of RV350) used by Radeon 9600 SE
        ATI_RV380_XT, // RV380 XT (variant of RV380)
        ATI_RV535_XT, // RV535 XT (variant of RV535) used by Radeon X1650 Pro
        ATI_RV570_XL, // RV570 XL (variant of RV570)
        ATI_R580_PLUS_XT, // R580+ XT (variant of R580+)
        ATI_RV620_LE, // RV620 LE (variant of RV620)
        ATI_RV670_Pro, // RV670 Pro (variant of RV670)
        ATI_RV730_XT, // RV730 XT (variant of RV730)
        AMD_BARTS_XT, // Barts XT (variant of Barts)
        AMD_KHALIDSTER, // Khalidster (variant of Caicos)
        AMD_CAICOS_XT, // Caicos XT (variant of Caicos)
        AMD_CAICOS_PRO, // Caicos Pro (variant of Caicos)
        AMD_TURKS_LE, // Turks LE (variant of Turks)
        AMD_TURKS_PRO, // Turks Pro (variant of Turks)
        AMD_TURKS_PRO_L, // Turks Pro L (variant of Turks)
        AMD_REDWOOD_PRO, // Redwood Pro (variant of Redwood)
        AMD_BAFFIN_PRO, // Baffin Pro (variant of Baffin)
        AMD_NAVI_24_XL, // Navi 24 XL (variant of Navi 24)
    };
}

namespace std
{
    std::string to_string(const DataInfo::ManufacturerID &manufacturer, const bool fullName = false);
    std::string to_string(const DataInfo::ArchitectureID &architecture);
    std::string to_string(const DataInfo::GPUID &gpuID);
    std::string to_string(const DataInfo::GPUVariantID &gpuVariantID);
}
