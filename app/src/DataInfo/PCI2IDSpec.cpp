//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "PCI2IDSpec.hpp"

namespace DataInfo
{
    const std::map<std::pair<uint16_t, uint16_t>, GfxBoardID> vendorAndDevice2gfxBoardId {
        { { 0x1002, 0x5046 }, GfxBoardID::ATI_Rage_128_Pro }, // ATI Rage 128 Pro
        { { 0x1002, 0x5962 }, GfxBoardID::ATI_Radeon_9200 }, // ATI Radeon 9200
        { { 0x1002, 0x4E56 }, GfxBoardID::ATI_Radeon_9550_Mobile }, // ATI Mobility Radeon 9550
        { { 0x1002, 0x4150 }, GfxBoardID::ATI_Radeon_9600_Pro }, // ATI Radeon 9600 Pro
        { { 0x1002, 0x4152 }, GfxBoardID::ATI_Radeon_9600_XT }, // ATI Radeon 9600XT/X1050
        { { 0x1002, 0x4E48 }, GfxBoardID::ATI_Radeon_9800 }, // ATI Radeon 9800
        { { 0x1002, 0x3E50 }, GfxBoardID::ATI_Radeon_X600_XT }, // ATI Radeon X600 XT
        { { 0x1002, 0x7280 }, GfxBoardID::ATI_Radeon_X1950_Pro }, // ATI Radeon X1950 Pro
        { { 0x1002, 0x9515 }, GfxBoardID::AMD_Radeon_HD_3850 }, // ATI Radeon HD 3850
    };
}