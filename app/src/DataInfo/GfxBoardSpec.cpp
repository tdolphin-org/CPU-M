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
            GfxBoardID::ATI_Radeon_7500,
            { "Radeon 7500",
              ManufacturerID::ATI,
              { GPUID::ATI_RV200 },
              2001,
              GfxBoardInterface::AGP_4x,
              28,
              { { 580'000, 72'500, 1'740'000 } } },
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
        {
            GfxBoardID::ATI_Radeon_9250,
            { "Radeon 9250",
              ManufacturerID::ATI,
              { GPUID::ATI_RV280 },
              2004,
              GfxBoardInterface::AGP_8x,
              28,
              { { 960'000, 60'000, 960'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9600_Mobile,
            { "ATI Mobility Radeon 9600",
              ManufacturerID::ATI,
              { GPUID::ATI_M10 },
              2004,
              GfxBoardInterface::AGP_8x,
              std::nullopt,
              { { 1'200'000, 150'000, 1'200'000 } } },
        },
    };
}