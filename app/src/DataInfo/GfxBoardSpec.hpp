//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "AOS/Common/ValueTypes/BoardID.hpp"
#include "GPUSpec.hpp"
#include "GfxBoardTypes.hpp"

#include <map>
#include <string>
#include <vector>

namespace DataInfo
{
    enum class GfxBoardInterface
    {
        PCI,
        AGP_1x,
        AGP_2x,
        AGP_4x,
        AGP_8x,
        PCIe_x16,
    };

    struct TheoreticalPerformance
    {
        unsigned long long pixelRate; // fillrate in kPixels/s
        std::optional<unsigned long long> vertexRate = std::nullopt; // fillrate in kVertices/s
        unsigned long long textureRate; // fillrate in kTexels/s
        std::optional<unsigned long long> FP32 = std::nullopt; // FP32 (float) in kFLOPS
        std::optional<unsigned long long> FP64 = std::nullopt; // FP64 (double) in kFLOPS
    };

    struct GfxBoardSpec
    {
        std::string name;
        ManufacturerID manufacturer; // manufacturer/vendor id
        GPUID gpu; // GPU id
        unsigned int premiere; // year
        std::vector<GfxBoardInterface> interfaces; // board interface like PCI, AGP, PCIe
        std::optional<unsigned int> TDP; // thermal design power in watts
        std::optional<TheoreticalPerformance> theoreticalPerformance;
    };

    std::string PerformancePixelRateToString(const unsigned long long rate);
    std::string PerformanceVertexRateToString(const unsigned long long rate);
    std::string PerformanceTextureRateToString(const unsigned long long rate);
    std::string PerformanceFP32RateToString(const unsigned long long rate);
    std::string PerformanceFP64RateToString(const unsigned long long rate);

    extern const std::map<GfxBoardID, GfxBoardSpec> gfxBoard2spec;
}

namespace std
{
    std::string to_string(const DataInfo::GfxBoardInterface &interface);
}
