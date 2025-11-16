//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "GPUTypes.hpp"
#include "TechnologyTypes.hpp"

#include <map>
#include <optional>

namespace DataInfo
{
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
        unsigned int premiere; // year
        std::optional<ArchitectureID> architecture; // architecture/generation
        TechnologyID technology;
        RenderConfig renderConfig;
        std::optional<unsigned int> maxTDP; // in watts
    };

    extern const std::map<GPUID, GPUSpec> gpu2spec;
}
