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
    /// @brief Graphics Chip Identifiers
    /// source: https://www.morphos-team.net/hardware
    enum class GPUID
    {
        
    };

    struct GPUSpec
    {
        std::string manufacturer;
        std::string modelName; // chip/model name
        std::string premiere;
        std::string interface; // interface/bus
        std::string technology;
        long coreClock; // Core Clock in MHz
        std::string memory; // memory spec bit@clock (speed MB/s)
    };

    extern const std::map<GPUID, GPUSpec> gpu2spec;
}
