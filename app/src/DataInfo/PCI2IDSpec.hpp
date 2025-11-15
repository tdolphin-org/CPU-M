//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GfxBoardSpec.hpp"

#include <cstdint>
#include <map>
#include <optional>
#include <vector>

namespace DataInfo
{
    struct PCIDeviceKey
    {
        std::pair<uint16_t, uint16_t> vendorDevice; // vendor ID, device ID
        std::optional<std::pair<uint16_t, uint16_t>> subsystemVendorDevice; // optional subsystem vendor ID, subsystem device ID

        bool operator<(const PCIDeviceKey &other) const
        {
            if (vendorDevice != other.vendorDevice)
                return vendorDevice < other.vendorDevice;
            return subsystemVendorDevice < other.subsystemVendorDevice;
        }

        PCIDeviceKey(uint16_t vendorId, uint16_t deviceId)
          : vendorDevice(vendorId, deviceId)
        {
        }

        PCIDeviceKey(uint16_t vendorId, uint16_t deviceId, uint16_t subsystemVendorId, uint16_t subsystemDeviceId)
          : vendorDevice(vendorId, deviceId)
          , subsystemVendorDevice(std::make_pair(subsystemVendorId, subsystemDeviceId))
        {
        }
    };

    struct PCIDeviceValue
    {
        GfxBoardID gfxBoardId;
        std::optional<BoardInterface> interface; // optional interface if known (and different than supported)
    };

    // map PCIDeviceKey to GfxBoardID
    extern const std::map<PCIDeviceKey, std::vector<PCIDeviceValue>> vendorAndDevice2gfxBoardId;
}
