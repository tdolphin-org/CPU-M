//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "MemorySpec.hpp"

#include <iomanip>
#include <numeric>

namespace DataInfo
{
    std::string MemoryInfo::name()
    {
        return std::to_string(generation) + " " + std::to_string(type);
    }

    std::string MemoryInfo::alias()
    {
        return std::to_string(generation) + "-" + std::to_string(bandwidthMBs);
    }

    const std::unordered_map<MemoryType, MemoryInfo> memorySpecs = {
        { MemoryType::PC66, { MemoryType::PC66, MemoryGeneration::SDR, 3300, 66, 528, 66, "Standard voltage" } },
        { MemoryType::PC100, { MemoryType::PC100, MemoryGeneration::SDR, 3300, 100, 800, 100, "Standard voltage" } },
        { MemoryType::PC133, { MemoryType::PC133, MemoryGeneration::SDR, 3300, 133, 1064, 133, "Standard voltage" } },

        { MemoryType::PC1600, { MemoryType::PC1600, MemoryGeneration::DDR, 2500, 200, 1600, 100, "Standard voltage" } },
        { MemoryType::PC2100, { MemoryType::PC2100, MemoryGeneration::DDR, 2500, 266, 2100, 133, "Standard voltage" } },
        { MemoryType::PC2700, { MemoryType::PC2700, MemoryGeneration::DDR, 2500, 333, 2700, 166, "Standard voltage" } },
        { MemoryType::PC3200, { MemoryType::PC3200, MemoryGeneration::DDR, 2500, 400, 3200, 200, "Standard voltage" } },
        { MemoryType::PC3500, { MemoryType::PC3500, MemoryGeneration::DDR, 2500, 433, 3500, 216, "Standard voltage" } },
        { MemoryType::PC3700, { MemoryType::PC3700, MemoryGeneration::DDR, 2500, 466, 3700, 233, "Standard voltage" } },
        { MemoryType::PC4000, { MemoryType::PC4000, MemoryGeneration::DDR, 2500, 500, 4000, 250, "Standard voltage" } },
        { MemoryType::PC4200, { MemoryType::PC4200, MemoryGeneration::DDR, 2500, 533, 4200, 266, "Standard voltage" } },
        { MemoryType::PC4400, { MemoryType::PC4400, MemoryGeneration::DDR, 2500, 566, 4400, 283, "Standard voltage" } },
        { MemoryType::PC4800, { MemoryType::PC4800, MemoryGeneration::DDR, 2500, 600, 4800, 300, "Standard voltage" } },

        { MemoryType::PC2_3200, { MemoryType::PC2_3200, MemoryGeneration::DDR2, 1800, 400, 3200, 200, "Standard voltage" } },
        { MemoryType::PC2_4200, { MemoryType::PC2_4200, MemoryGeneration::DDR2, 1800, 533, 4200, 266, "Standard voltage" } },
        { MemoryType::PC2_5300, { MemoryType::PC2_5300, MemoryGeneration::DDR2, 1800, 667, 5300, 333, "Standard voltage" } },
        { MemoryType::PC2_6400, { MemoryType::PC2_6400, MemoryGeneration::DDR2, 1800, 800, 6400, 400, "Standard voltage" } },
        { MemoryType::PC2_8500, { MemoryType::PC2_8500, MemoryGeneration::DDR2, 1800, 1066, 8500, 533, "Standard voltage" } },
        { MemoryType::PC2_9600, { MemoryType::PC2_9600, MemoryGeneration::DDR2, 1800, 1200, 9600, 600, "Standard voltage" } },

        { MemoryType::PC3_6400, { MemoryType::PC3_6400, MemoryGeneration::DDR3, 1500, 800, 6400, 400, "Standard voltage" } },
        { MemoryType::PC3L_6400, { MemoryType::PC3L_6400, MemoryGeneration::DDR3, 1350, 800, 6400, 400, "Low voltage" } },
        { MemoryType::PC3_8500, { MemoryType::PC3_8500, MemoryGeneration::DDR3, 1500, 1066, 8500, 533, "Standard voltage" } },
        { MemoryType::PC3L_8500, { MemoryType::PC3L_8500, MemoryGeneration::DDR3, 1350, 1066, 8500, 533, "Low voltage" } },
        { MemoryType::PC3_10600, { MemoryType::PC3_10600, MemoryGeneration::DDR3, 1500, 1333, 10600, 666, "Standard voltage" } },
        { MemoryType::PC3L_10600, { MemoryType::PC3L_10600, MemoryGeneration::DDR3, 1350, 1333, 10600, 666, "Low voltage" } },
        { MemoryType::PC3_12800, { MemoryType::PC3_12800, MemoryGeneration::DDR3, 1500, 1600, 12800, 800, "Standard voltage" } },
        { MemoryType::PC3L_12800, { MemoryType::PC3L_12800, MemoryGeneration::DDR3, 1350, 1600, 12800, 800, "Low voltage" } },
        { MemoryType::PC3_14900, { MemoryType::PC3_14900, MemoryGeneration::DDR3, 1500, 1866, 14900, 933, "Standard voltage" } },
        { MemoryType::PC3L_14900, { MemoryType::PC3L_14900, MemoryGeneration::DDR3, 1350, 1866, 14900, 933, "Low voltage" } },
        { MemoryType::PC3_16000, { MemoryType::PC3_16000, MemoryGeneration::DDR3, 1500, 2000, 16000, 1000, "Standard voltage" } },
        { MemoryType::PC3L_16000, { MemoryType::PC3L_16000, MemoryGeneration::DDR3, 1350, 2000, 16000, 1000, "Low voltage" } },
        { MemoryType::PC3_17000, { MemoryType::PC3_17000, MemoryGeneration::DDR3, 1500, 2133, 17000, 1066, "Standard voltage" } },
        { MemoryType::PC3L_17000, { MemoryType::PC3L_17000, MemoryGeneration::DDR3, 1350, 2133, 17000, 1066, "Low voltage" } },
        { MemoryType::PC3_19200, { MemoryType::PC3_19200, MemoryGeneration::DDR3, 1500, 2400, 19200, 1200, "Standard voltage" } },
        { MemoryType::PC3L_19200, { MemoryType::PC3L_19200, MemoryGeneration::DDR3, 1350, 2400, 19200, 1200, "Low voltage" } },
        { MemoryType::PC3U_19200, { MemoryType::PC3U_19200, MemoryGeneration::DDR3, 1250, 2400, 19200, 1200, "Ultra low voltage" } },
    };

    const std::unordered_map<MemoryGenerationAndForm, ModuleInfo> moduleSpecs = {
        { MemoryGenerationAndForm::SDR_DIMM, { MemoryGeneration::SDR, ModuleForm::DIMM, 168, 133, 1997 } },
        { MemoryGenerationAndForm::SDR_SO_DIMM, { MemoryGeneration::SDR, ModuleForm::SO_DIMM, 144, 67, 1997 } },
        { MemoryGenerationAndForm::SDR_MicroDIMM, { MemoryGeneration::SDR, ModuleForm::MicroDIMM, 172, 45, 1999 } },

        { MemoryGenerationAndForm::DDR_DIMM, { MemoryGeneration::DDR, ModuleForm::DIMM, 184, 133, 2000 } },
        { MemoryGenerationAndForm::DDR_SO_DIMM, { MemoryGeneration::DDR, ModuleForm::SO_DIMM, 200, 67, 2001 } },
        { MemoryGenerationAndForm::DDR_MicroDIMM, { MemoryGeneration::DDR, ModuleForm::MicroDIMM, 172, 45, 2002 } },

        { MemoryGenerationAndForm::DDR2_DIMM, { MemoryGeneration::DDR2, ModuleForm::DIMM, 240, 133, 2003 } },
        { MemoryGenerationAndForm::DDR2_SO_DIMM, { MemoryGeneration::DDR2, ModuleForm::SO_DIMM, 200, 67, 2004 } },

        { MemoryGenerationAndForm::DDR3_DIMM, { MemoryGeneration::DDR3, ModuleForm::DIMM, 240, 133, 2007 } },
        { MemoryGenerationAndForm::DDR3_SO_DIMM, { MemoryGeneration::DDR3, ModuleForm::SO_DIMM, 204, 67, 2008 } },
        { MemoryGenerationAndForm::DDR3_MicroDIMM, { MemoryGeneration::DDR3, ModuleForm::MicroDIMM, 214, 30, 2010 } },
    };

    std::string mVToVoltage(uint16_t mv)
    {
        if (mv % 1000 == 0)
            return std::to_string(mv / 1000) + " V";
        else
        {
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(1) << mv / 1000.0;
            return stream.str() + " V";
        }
    }
}
