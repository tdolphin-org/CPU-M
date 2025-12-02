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
    // board or gpu interface types
    enum class BoardInterface
    {
        PCI,
        AGP_1x,
        AGP_2x,
        AGP_4x,
        AGP_8x,
        PCIe_x16, // 1.0 x16
        PCIe_2_x16, // 2.0 x16
        PCIe_3_x8, // 3.0 x8
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
        std::optional<GPUVariantID> gpuVariant; // GPU variant id
        unsigned int premiere; // year
        std::vector<BoardInterface> interfaces; // supported board interfaces like PCI, AGP, PCIe
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
    std::string to_string(const DataInfo::BoardInterface &interface);
}
