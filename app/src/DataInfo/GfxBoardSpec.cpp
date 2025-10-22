//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GfxBoardSpec.hpp"

// data info resources:
// ...

namespace DataInfo
{
    const std::map<GfxBoardID, GfxBoardSpec> gfxBoard2spec {
        {
            GfxBoardID::ATI_Rage_128_Pro,
            { "Rage 128 Pro", ManufacturerID::ATI, { GPUID::ATI_Rage_128_Pro }, 1999, GfxBoardInterface::AGP_4x, std::nullopt },
        },
    };
}