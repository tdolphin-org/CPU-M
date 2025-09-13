//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "HardwareSystemSpec.hpp"

// sources:
// https://support.apple.com
// https://everymac.com
// https://en.wikipedia.org/wiki/Mac_Mini
// https://en.wikipedia.org/wiki/IBook#iBook_G4
// https://en.wikipedia.org/wiki/Power_Mac_G4

namespace DataInfo
{
    const std::map<std::string, HardwareSystemSpec> hardwareSystem2spec {
        {
            "Efika5200B",
            {
                std::nullopt,
                "Genesi Efika 5200B",
                2006,
                2007,
                "Soldered",
                "2.5\"",
                "PATA",
                "Smart Firmware",
                { "DDR SDRAM", "266 MHz", 128, 0 },
                { { "USB 1.1", 2 }, { "S/PDIF", 1 }, { "Ethernet 10/100 Mbps", 1 }, { "Audio In/Out", 1 }, { "RS-232", 1 } },
                "Memory is soldered to the motherboard",
            },
        },
        {
            "PowerMac3,1",
            {
                "M5183",
                "Apple Power Mac G4",
                1999,
                2000,
                "custom 300-pin daughtercard",
                "3.5\"",
                "Ultra ATA/66",
                "Open Firmware",
                { "PC100 SDRAM", "333 MHz", 2048, 4 },
                { { "USB 1.1", 2 }, { "FireWire 400", 3 }, { "Ethernet 10/100 Mbps", 1 } },
                std::nullopt,
            },
        },
        {
            "PowerMac10,1",
            {
                "A1103",
                "Apple Mac mini G4",
                2005,
                2006,
                "Soldered",
                "2.5\"",
                "Ultra ATA/100",
                "Open Firmware",
                { "PC2700 DDR SDRAM", "333 MHz", 1024, 1 },
                { { "USB 2.0", 2 }, { "FireWire 400", 1 }, { "Ethernet 10/100 Mbps", 1 } },
                std::nullopt,
            },
        },
        {
            "PowerMac10,2",
            {
                "A1103",
                "Apple Mac mini G4",
                2005,
                2006,
                "Soldered",
                "2.5\"",
                "Ultra ATA/100",
                "Open Firmware",
                { "PC2700 DDR SDRAM", "333 MHz", 1024, 1 },
                { { "USB 2.0", 2 }, { "FireWire 400", 1 }, { "Ethernet 10/100 Mbps", 1 } },
                std::nullopt,
            },
        },
        {
            "PowerBook6,7",
            {
                "A1133 (12\") or A1134 (14\")",
                "Apple iBook G4 (12\" or 14\")",
                2005,
                2006,
                "Soldered",
                "2.5\"",
                "Ultra ATA/100",
                "Open Firmware",
                { "PC2700 DDR SDRAM", "333 MHz", 1536, 1 }, // 1.5 GB RAM max, 1 slot
                { { "USB 2.0", 2 }, { "FireWire 400", 1 }, { "Ethernet 10/100 Mbps", 1 } },
                "512 MB of 333 MHz PC2700 DDR SDRAM (soldered to logic board)",
            },
        },
    };
}
