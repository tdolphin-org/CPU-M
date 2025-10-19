//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include <string>

enum class MemoryGeneration
{
    SDR, // Single Data Rate SDRAM
    DDR, // Double Data Rate SDRAM
    DDR2, // Double Data Rate 2 SDRAM
    DDR3 // Double Data Rate 3 SDRAM
};

enum class ModuleForm
{
    DIMM, // desktop form
    SO_DIMM, // laptop form
    MicroDIMM // rare mobile form
};

// memory types (PC-xxxx, PC2-xxxx, PC3-xxxx)
// xxxL - low voltage
enum class MemoryType
{
    // --- SDR ---
    PC66,
    PC100,
    PC133,

    // --- DDR ---
    PC1600,
    PC2100,
    PC2700,
    PC3200,

    // --- DDR2 ---
    PC2_3200,
    PC2_4200,
    PC2_5300,
    PC2_6400,
    PC2_8500,
    PC2_9600,

    // --- DDR3 ---
    PC3_6400,
    PC3L_6400,
    PC3_8500,
    PC3L_8500,
    PC3_10600,
    PC3L_10600,
    PC3_12800,
    PC3L_12800,
    PC3_14900,
    PC3L_14900,
    PC3_16000,
    PC3L_16000,
    PC3_17000,
    PC3L_17000,
    PC3_19200,
    PC3L_19200,
    PC3U_19200
};

namespace std
{
    std::string to_string(const MemoryGeneration generation);
    std::string to_string(const ModuleForm form);
    std::string to_string(const MemoryType type);
}
