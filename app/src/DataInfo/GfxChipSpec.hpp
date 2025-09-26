//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include <map>
#include <string>

namespace DataInfo
{
    enum class GfxChipID
    {
    };

    struct GfxChipSpec
    {
        std::string manufacturer;
        std::string modelName; // chip/model name
        std::string premiere;
        std::string interface; // interface/bus
        std::string technology;
        long coreClock; // Core Clock in MHz
        std::string videoAcceleration;
        std::string memory; // memory spec bit@clock (speed MB/s)
    };

    extern const std::map<GfxChipID, GfxChipSpec> gfxChip2spec;
}
