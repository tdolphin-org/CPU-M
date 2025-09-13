//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include <map>
#include <optional>
#include <string>
#include <vector>

namespace DataInfo
{
    struct RAMSpec
    {
        std::string type; // PC2700 DDR SDRAM
        std::string speed; // 333 MHz
        unsigned int max; // 1024 (MB)
        unsigned int slots; // 1
    };

    struct PortSpec
    {
        std::string type; // USB 2.0, FireWire 400
        unsigned int count; // 2
    };

    struct HardwareSystemSpec
    {
        std::optional<std::string> modelNumber; // A1103
        std::string marketingName; // Apple Mac mini G4
        unsigned int introductionYear; // 2005
        unsigned int discontinuedYear; // 2005
        std::string cpuSocket; // Soldered
        std::string storageDimensions; // 2.5"
        std::string storageInterface; // Ultra ATA/100
        std::string firmwareType; // Open Firmware
        RAMSpec RAM;
        std::vector<PortSpec> ports;
        std::optional<std::string> notes; // any additional notes
    };

    extern const std::map<std::string, HardwareSystemSpec> hardwareSystem2spec;
}
