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
        { { 0x1002, 0x4E56 }, GfxBoardID::ATI_Radeon_9550_Mobile }, // ATI Mobility Radeon 9550
    };
}