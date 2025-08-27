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
    struct CPUSpec
    {
        std::string vendor;
        std::string modelName;
        std::string coreVoltage;
        std::string technology;
        std::string premiere;
        std::string tdp;
    };

    extern const std::map<std::string, CPUSpec> cpuPPC2spec;
}