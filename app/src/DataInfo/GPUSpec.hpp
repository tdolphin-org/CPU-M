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
        THREE_D_LABS,
    };

    enum class ArchitectureID
    {
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
        unsigned int MTUs; // number of TMUs
        unsigned int ROPs; // number of ROPs
        std::optional<unsigned int> computeUnits = std::nullopt; // number of compute units
    };

    struct GPUSpec
    {
        ManufacturerID manufacturer;
        std::string name; // gpu name
        unsigned int premiere; // year
        std::optional<ArchitectureID> architecture; // architecture/generation
        std::string technology;
        RenderConfig renderConfig;
        std::optional<unsigned int> maxTDP; // in watts
    };

    extern const std::map<GPUID, GPUSpec> gpu2spec;
}
