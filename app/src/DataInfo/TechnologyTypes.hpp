//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include <string>
#include <variant>

namespace DataInfo
{
    enum class TechnologyID
    {
        Unknown, // N/A or unknown technology
        nm_350, // 350nm
        nm_250, // 250nm
        nm_180, // 180nm (0.18um)
        nm_150, // 150nm
        nm_130, // 130nm
        nm_90,  // 90nm
        nm_80,  // 80nm
        nm_65,  // 65nm
        nm_55,  // 55nm
        nm_45,  // 45nm
        nm_40,  // 40nm
        nm_32,  // 32nm
        nm_28,  // 28nm
        nm_22,  // 22nm
        nm_16,  // 16nm
        nm_14,  // 14nm
        nm_12,  // 12nm
        nm_10,  // 10nm
        nm_7,   // 7nm
        nm_6,   // 6nm
        nm_5,   // 5nm
        nm_4,   // 4nm
        nm_3,   // 3nm
        // Legacy micron sizes
        um_0_5, // 0.5 um (500nm)
        um_0_35, // 0.35 um (350nm)
        um_0_18, // 0.18 um (180nm)
    };

    struct TechnologyRange
    {
        TechnologyID min; // smaller/more advanced technology
        TechnologyID max; // larger/less advanced technology
    };

    using TechnologySpec = std::variant<TechnologyID, TechnologyRange>;
}

namespace std
{
    std::string to_string(const DataInfo::TechnologyID &technology);
    std::string to_string(const DataInfo::TechnologySpec &technologySpec);
}