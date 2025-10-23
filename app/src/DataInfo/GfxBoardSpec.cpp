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
            { "Rage 128 Pro",
              ManufacturerID::ATI,
              { GPUID::ATI_Rage_128_Pro },
              1999,
              GfxBoardInterface::AGP_4x,
              std::nullopt,
              std::nullopt },
        },
        {
            GfxBoardID::ATI_Radeon_9550_Mobile,
            { "ATI Mobility Radeon 9550",
              ManufacturerID::ATI,
              { GPUID::ATI_M12 },
              2004,
              GfxBoardInterface::PCIe_x16,
              std::nullopt,
              { { 1'000'000, 125'000, 1'000'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9200,
            { "Radeon 9200",
              ManufacturerID::ATI,
              { GPUID::ATI_RV280 },
              2003,
              GfxBoardInterface::AGP_8x,
              28,
              { { 1'000'000, 62'500, 1'000'000 } } },
        },
    };
}