//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "GfxBoardTypes.hpp"
#include "MemoryTypes.hpp"

#include <optional>
#include <unordered_map>
#include <vector>

namespace DataInfo
{
    struct SlotRAMSpec
    {
        MemoryType type; // PC2700 DDR SDRAM
        ModuleForm form; // DIMM, SO_DIMM, MicroDIMM
        unsigned int max; // 1024 (MB) max RAM size supported with this type in all slots
        unsigned int slots; // 1
    };

    struct SolderedRAMSpec
    {
        MemoryType type; // PC2700 DDR SDRAM
        unsigned int size; // 256 (MB) size of soldered RAM
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
        std::optional<SolderedRAMSpec> solderedRAM; // if any RAM soldered to mainboard
        std::vector<SlotRAMSpec> RAM; // options for RAM, for different models
        std::vector<PortSpec> ports;
        std::optional<std::string> ramNotes; // additional notes regarding mainboard RAM
        std::optional<std::string> notes; // additional notes about system
        std::optional<GfxBoardID>
            integratedGraphicsBoard; // if any integrated graphics present (not required, used to determine supported graphics if pciid is ambiguous)
    };

    extern const std::unordered_map<std::string, HardwareSystemSpec> hardwareSystem2spec;
}
