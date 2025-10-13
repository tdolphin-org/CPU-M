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
        uint16_t dataRateMTs; // effective data rate MT/s
        uint32_t bandwidthMBs; // bandwidth
        uint32_t clockMHz; // real clock speed
        std::string notes; // notes / comments

        std::string name(); // e.g. "PC3-12800"
        std::string alias(); // e.g. "DDR3-1600"
    };

    struct ModuleInfo
    {
        MemoryGeneration generation; // memory generation
        ModuleForm form; // module type
        uint16_t pins; // number of pins
        uint16_t length_mm; // module length
        unsigned int introductionYear; // introduction year
    };

    extern const std::unordered_map<MemoryType, MemoryInfo> memorySpecs;
    extern const std::unordered_map<MemoryGenerationAndForm, ModuleInfo> moduleSpecs; // key is name()

    std::string mVToVoltage(uint16_t mv);
}
