//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "MemoryTypes.hpp"

#include <unordered_map>

namespace DataInfo
{
    struct MemoryInfo
    {
        MemoryType type; // memory type
        MemoryGeneration generation; // SDRAM / DDR / DDR2 / DDR3
        uint16_t voltage_mV; // voltage in mV
        uint16_t dataRateMTs; // effective clock speed
        uint32_t bandwidthMBs; // bandwidth
        ModuleForm form; // module type
        uint16_t pins; // number of pins
        uint16_t length_mm; // module length
        std::string notes; // notes / comments

        std::string name(); // e.g. "PC3-12800"
        std::string alias(); // e.g. "DDR3-1600"
    };

    extern const std::unordered_map<MemoryType, MemoryInfo> memorySpecs;
}
