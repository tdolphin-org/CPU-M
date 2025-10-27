//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GfxBoardSpec.hpp"

#include <cstdint>
#include <map>
#include <vector>

namespace DataInfo
{
    // map { vendor pci id, device pci id } to GfxBoardID
    extern const std::map<std::pair<uint16_t, uint16_t>, std::vector<GfxBoardID>> vendorAndDevice2gfxBoardId;
}
