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
        std::string clock; // 333 MHz
        unsigned int max; // 1024 (MB) max RAM size supported with this type in all slots
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
        std::optional<unsigned int> discontinuedYear; // 2005
        std::string cpuSocket; // Soldered
        std::vector<std::string> storageInterfaces; // Ultra ATA/100 2.5", SATA 3.0, SD Card, MicroSD
        std::string firmwareType; // Open Firmware
        std::vector<RAMSpec> RAM; // options for RAM, for different models
        std::optional<unsigned int> maxRAMSize; // maximum RAM size supported (summary in all slots and soldered, MB), set if any RAM
                                                // soldered to mainboard and slots available
        std::vector<PortSpec> ports;
        std::optional<std::string> ramNotes; // additional notes regarding mainboard RAM
        std::optional<std::string> notes; // additional notes about system
    };

    extern const std::map<std::string, HardwareSystemSpec> hardwareSystem2spec;
}
