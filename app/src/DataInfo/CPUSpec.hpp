//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "TechnologyTypes.hpp"

#include <map>
#include <string>

namespace DataInfo
{
    struct CPUSpec
    {
        std::string vendor;
        std::string modelName;
        std::string codeName;
        std::string coreVoltage;
        TechnologySpec technology;
        std::string premiere;
        std::string tdp;
    };

    extern const std::map<std::string, CPUSpec> cpuPPC2spec;
}