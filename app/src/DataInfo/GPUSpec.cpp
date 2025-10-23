//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GPUSpec.hpp"

// data info resources:
// ...

namespace DataInfo
{
    const std::map<GPUID, GPUSpec> gpu2spec {
        { GPUID::ATI_Rage_128_Pro,
          { ManufacturerID::ATI, "Rage 128 Pro", 1999, ArchitectureID::ATI_RAGE_4, "250nm", { 2, 0, 2, 2 }, std::nullopt } },
        { GPUID::ATI_RV200, { ManufacturerID::ATI, "RV200", 2001, ArchitectureID::ATI_RAGE_7, "150nm", { 2, 1, 6, 2 }, 23 } },
        { GPUID::ATI_RV280, { ManufacturerID::ATI, "RV280", 2003, ArchitectureID::ATI_RAGE_7, "150nm", { 4, 1, 4, 4 }, 28 } },
        { GPUID::ATI_M10, { ManufacturerID::ATI, "M10", 2003, ArchitectureID::ATI_R300, "130nm", { 4, 2, 4, 4 }, std::nullopt } },
        { GPUID::ATI_M12, { ManufacturerID::ATI, "M12", 2004, ArchitectureID::ATI_R300, "130nm", { 4, 2, 4, 4 }, std::nullopt } },
    };
}
