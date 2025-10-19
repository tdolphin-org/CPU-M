//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "MemoryTypes.hpp"

namespace std
{
    std::string to_string(const MemoryGeneration generation)
    {
        switch (generation)
        {
            case MemoryGeneration::SDR:
                return "SDR SDRAM";
            case MemoryGeneration::DDR:
                return "DDR SDRAM";
            case MemoryGeneration::DDR2:
                return "DDR2 SDRAM";
            case MemoryGeneration::DDR3:
                return "DDR3 SDRAM";
            default:
                return "Unknown";
        }
    }

    std::string to_string(const ModuleForm form)
    {
        switch (form)
        {
            case ModuleForm::DIMM:
                return "DIMM";
            case ModuleForm::SO_DIMM:
                return "SO-DIMM";
            case ModuleForm::MicroDIMM:
                return "MicroDIMM";
            default:
                return "Unknown";
        }
    }

    std::string to_string(const MemoryType type)
    {
        switch (type)
        {
            case MemoryType::PC66:
                return "PC66";
            case MemoryType::PC100:
                return "PC100";
            case MemoryType::PC133:
                return "PC133";
            case MemoryType::PC1600:
                return "PC1600";
            case MemoryType::PC2100:
                return "PC2100";
            case MemoryType::PC2700:
                return "PC2700";
            case MemoryType::PC3200:
                return "PC3200";
            case MemoryType::PC2_3200:
                return "PC2-3200";
            case MemoryType::PC2_4200:
                return "PC2-4200";
            case MemoryType::PC2_5300:
                return "PC2-5300";
            case MemoryType::PC2_6400:
                return "PC2-6400";
            case MemoryType::PC2_8500:
                return "PC2-8500";
            case MemoryType::PC2_9600:
                return "PC2-9600";
            case MemoryType::PC3_6400:
                return "PC3-6400";
            case MemoryType::PC3L_6400:
                return "PC3L_6400";
            case MemoryType::PC3_8500:
                return "PC3-8500";
            case MemoryType::PC3L_8500:
                return "PC3L_8500";
            case MemoryType::PC3_10600:
                return "PC3-10600";
            case MemoryType::PC3L_10600:
                return "PC3L_10600";
            case MemoryType::PC3_12800:
                return "PC3-12800";
            case MemoryType::PC3L_12800:
                return "PC3L_12800";
            case MemoryType::PC3_14900:
                return "PC3-14900";
            case MemoryType::PC3L_14900:
                return "PC3L_14900";
            case MemoryType::PC3_16000:
                return "PC3-16000";
            case MemoryType::PC3L_16000:
                return "PC3L_16000";
            case MemoryType::PC3_17000:
                return "PC3-17000";
            case MemoryType::PC3L_17000:
                return "PC3L_17000";
            case MemoryType::PC3_19200:
                return "PC3-19200";
            case MemoryType::PC3L_19200:
                return "PC3L_19200";
            case MemoryType::PC3U_19200:
                return "PC3U_19200";
            default:
                return "Unknown";
        }
    }
}
