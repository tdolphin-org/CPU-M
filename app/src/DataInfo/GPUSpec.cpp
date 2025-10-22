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
        { GPUID::ATI_Rage_128_Pro, { ManufacturerID::ATI, "Rage 128 Pro", 1999, "Rage 4", "250nm", 2, 0, 2, 2 } },
    };
}
