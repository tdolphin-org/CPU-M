//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "TechnologyTypes.hpp"

namespace std
{
    std::string to_string(const DataInfo::TechnologyID &technology)
    {
        using namespace DataInfo;

        switch (technology)
        {
            case TechnologyID::Unknown:
                return "N/A";
            case TechnologyID::nm_350:
                return "350nm";
            case TechnologyID::nm_250:
                return "250nm";
            case TechnologyID::nm_180:
                return "180nm";
            case TechnologyID::nm_150:
                return "150nm";
            case TechnologyID::nm_130:
                return "130nm";
            case TechnologyID::nm_90:
                return "90nm";
            case TechnologyID::nm_80:
                return "80nm";
            case TechnologyID::nm_65:
                return "65nm";
            case TechnologyID::nm_55:
                return "55nm";
            case TechnologyID::nm_45:
                return "45nm";
            case TechnologyID::nm_40:
                return "40nm";
            case TechnologyID::nm_32:
                return "32nm";
            case TechnologyID::nm_28:
                return "28nm";
            case TechnologyID::nm_22:
                return "22nm";
            case TechnologyID::nm_16:
                return "16nm";
            case TechnologyID::nm_14:
                return "14nm";
            case TechnologyID::nm_12:
                return "12nm";
            case TechnologyID::nm_10:
                return "10nm";
            case TechnologyID::nm_7:
                return "7nm";
            case TechnologyID::nm_6:
                return "6nm";
            case TechnologyID::nm_5:
                return "5nm";
            case TechnologyID::nm_4:
                return "4nm";
            case TechnologyID::nm_3:
                return "3nm";
            case TechnologyID::um_0_5:
                return "0.5 um";
            case TechnologyID::um_0_35:
                return "0.35 um";
            case TechnologyID::um_0_18:
                return "0.18 um";
            default:
                return "Unknown Technology";
        }
    }

    std::string to_string(const DataInfo::TechnologySpec &technologySpec)
    {
        return std::visit([](const auto& tech) -> std::string {
            if constexpr (std::is_same_v<std::decay_t<decltype(tech)>, DataInfo::TechnologyID>) {
                return std::to_string(tech);
            } else if constexpr (std::is_same_v<std::decay_t<decltype(tech)>, DataInfo::TechnologyRange>) {
                return std::to_string(tech.min) + "-" + std::to_string(tech.max);
            }
            return "Unknown Technology Spec";
        }, technologySpec);
    }
}