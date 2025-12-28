//
//  CPU-M
//
//  (c) 2025 TDolphin
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
        ATI_TeraScale,
        ATI_TeraScale_2,
        ATI_TeraScale_3,
        AMD_GCN_1_0,
        AMD_GCN_2_0,
        AMD_GCN_3_0,
        AMD_GCN_4_0,
        AMD_GCN_5_0,
        AMD_GCN_5_1,
        AMD_RDNA_1,
        AMD_RDNA_2,
        AMD_RDNA_3,
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
        ATI_RV200, // RV200
        ATI_RV280, // RV280
        ATI_RV350, // RV350
        ATI_R350, // R350
        ATI_RV360, // RV360
        ATI_RV380, // RV380
        ATI_RV570, // RV570
        ATI_R580_PLUS, // R580+
        ATI_RV620, // RV620
        ATI_RV670, // RV670
        ATI_RV730, // RV730
        AMD_BARTS, // Barts
        AMD_BAFFIN, // Baffin
        ATI_M10, // Mobility M10
        ATI_M11, // Mobility M11
        ATI_M12, // Mobility M12
    };

    enum class GPUVariantID
    {
        ATI_RV200_7500, // RV200 7500 (variant of RV200) used by Radeon 7500
        ATI_RV200_7500_LE, // RV200 7500 LE (variant of RV200) used by Radeon 7500 LE
        ATI_RV280_9200_SE, // RV280 9200 SE (variant of RV280) used by Radeon 9200 SE
        ATI_RV380_XT, // RV380 XT (variant of RV380)
        ATI_R580_PLUS_XT, // R580+ XT (variant of R580+)
        ATI_RV620_LE, // RV620 LE (variant of RV620)
        ATI_RV670_Pro, // RV670 Pro (variant of RV670)
        ATI_RV730_XT, // RV730 XT (variant of RV730)
        AMD_BARTS_XT, // Barts XT (variant of Barts)
        AMD_BAFFIN_PRO, // Baffin Pro (variant of Baffin)
    };
}

namespace std
{
    std::string to_string(const DataInfo::ManufacturerID &manufacturer, const bool fullName = false);
    std::string to_string(const DataInfo::ArchitectureID &architecture);
    std::string to_string(const DataInfo::GPUID &gpuID);
    std::string to_string(const DataInfo::GPUVariantID &gpuVariantID);
}
