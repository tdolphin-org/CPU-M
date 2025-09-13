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
//

namespace DataInfo
{
    const std::map<std::string, HardwareSystemSpec> hardwareSystem2spec {
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
                { { "USB 2.0", 2 }, { "FireWire 400", 1 } },
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
                { { "USB 2.0", 2 }, { "FireWire 400", 1 } },
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
                { { "USB 2.0", 2 }, { "FireWire 400", 1 } },
                "512 MB of 333 MHz PC2700 DDR SDRAM (soldered to logic board)",
            },
        },
    };
}
