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

    /// @brief Graphics Chip Identifiers
    /// source: https://www.morphos-team.net/hardware
    enum class GPUID
    {
        // ATI/AMD Rage series
        ATI_Rage_128_Pro, // Rage 128 Pro
    };

    struct GPUSpec
    {
        ManufacturerID manufacturer;
        std::string name; // gpu name
        unsigned int premiere; // year
        std::optional<std::string> architecture; // architecture/generation
        std::string technology;
        unsigned int pixelShaders; // number of pixel shaders
        unsigned int vertexShaders; // number of vertex shaders
        unsigned int MTUs; // number of TMUs
        unsigned int ROPs; // number of ROPs
    };

    extern const std::map<GPUID, GPUSpec> gpu2spec;
}
