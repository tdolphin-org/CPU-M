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

    /// @brief Graphics Chip Identifiers
    /// source: https://www.morphos-team.net/hardware
    enum class GPUID
    {
        // ATI/AMD Rage series
        ATI_Rage_128_Pro, // Rage 128 Pro
        ATI_M12, // Mobility M12
        ATI_RV280,
    };

    struct GPUSpec
    {
        ManufacturerID manufacturer;
        std::string name; // gpu name
        unsigned int premiere; // year
        std::optional<ArchitectureID> architecture; // architecture/generation
        std::string technology;
        struct
        {
            unsigned int pixelShaders; // number of pixel shaders
            unsigned int vertexShaders; // number of vertex shaders
            unsigned int MTUs; // number of TMUs
            unsigned int ROPs; // number of ROPs
        } renderConfig;
        std::optional<unsigned int> maxTDP; // in watts
    };

    extern const std::map<GPUID, GPUSpec> gpu2spec;
}
