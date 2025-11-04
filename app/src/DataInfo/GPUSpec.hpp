//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include <map>
#include <optional>
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
        Permedia_2,
        Permedia_2V,

        // SiS series
        SiS_6326,
        SiS_300,
        SiS_305,
        SiS_Mirage_315,

        // XGI Volari series
        XGI_Volari_V3_XT,
        XGI_Volari_V5,
        XGI_Volari_V5_XT,
        XGI_Volari_V8,
        XGI_Volari_V8_Ultra,

        // ATI/AMD Rage series
        ATI_Rage_128_Pro, // Rage 128 Pro
        ATI_RV200, // RV200
        ATI_RV200_500,
        ATI_RV280, // RV280
        ATI_RV350, // RV350
        ATI_R350, // R350
        ATI_RV360, // RV360
        ATI_RV380_XT, // RV380 XT
        ATI_RV570, // RV570
        ATI_RV670_Pro, // RV670 Pro
        ATI_M10, // Mobility M10
        ATI_M11, // Mobility M11
        ATI_M12, // Mobility M12
    };

    enum class GPUVariantID
    {
    };

    struct RenderConfig
    {
        std::optional<unsigned int> shadingUnits = std::nullopt; // number of shading units
        std::optional<unsigned int> pixelShaders = std::nullopt; // number of pixel shaders
        std::optional<unsigned int> vertexShaders = std::nullopt; // number of vertex shaders
        unsigned int TMUs; // number of TMUs (texture mapping units)
        unsigned int ROPs; // number of ROPs (render/raster output units)
        std::optional<unsigned int> computeUnits = std::nullopt; // number of compute units
    };

    struct GPUSpec
    {
        ManufacturerID manufacturer; // manufacturer/vendor
        std::string name; // gpu name
        unsigned int premiere; // year
        std::optional<ArchitectureID> architecture; // architecture/generation
        std::string technology;
        RenderConfig renderConfig;
        std::optional<unsigned int> maxTDP; // in watts
    };

    extern const std::map<GPUID, GPUSpec> gpu2spec;
}

namespace std
{
    std::string to_string(const DataInfo::ManufacturerID &manufacturer, const bool fullName = false);
    std::string to_string(const DataInfo::ArchitectureID &architecture);
    std::string to_string(const DataInfo::GPUID &gpuID);
}
