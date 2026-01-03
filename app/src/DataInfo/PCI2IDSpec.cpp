//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "PCI2IDSpec.hpp"

namespace DataInfo
{
    const std::map<PCIDeviceKey, std::vector<PCIDeviceValue>> vendorAndDevice2gfxBoardId {
        { PCIDeviceKey(0x1002, 0x3E50), { { GfxCardID::ATI_Radeon_X600_XT } } }, // ATI Radeon X600 XT
        { PCIDeviceKey(0x1002, 0x4E56), { { GfxCardID::ATI_Radeon_9550_Mobile } } }, // ATI Mobility Radeon 9550
        { PCIDeviceKey(0x1002, 0x4150), { { GfxCardID::ATI_Radeon_9600_Pro } } }, // ATI Radeon 9600 Pro
        { PCIDeviceKey(0x1002, 0x4152), { { GfxCardID::ATI_Radeon_9600_XT }, { GfxCardID::ATI_Radeon_X1050 } } }, // ATI Radeon 9600XT/X1050
        { PCIDeviceKey(0x1002, 0x4E48), { { GfxCardID::ATI_Radeon_9800 } } }, // ATI Radeon 9800
        { PCIDeviceKey(0x1002, 0x4E50),
          { { GfxCardID::ATI_Radeon_9600_Mobile }, { GfxCardID::ATI_Radeon_9700_Mobile } } }, // ATI Radeon 9600/9700 Mobile
        { PCIDeviceKey(0x1002, 0x5046), { { GfxCardID::ATI_Rage_128_Pro } } }, // ATI Rage 128 Pro
        { PCIDeviceKey(0x1002, 0x5157), { { GfxCardID::ATI_Radeon_7500 }, { GfxCardID::ATI_Radeon_7500_LE } } }, // ATI Radeon 7500
        { PCIDeviceKey(0x1002, 0x5157, 0x17AF, 0x2002), { { GfxCardID::ATI_Radeon_7500 } } }, // ATI Radeon 7500
        { PCIDeviceKey(0x1002, 0x5960),
          { { GfxCardID::ATI_Radeon_9200_Pro }, { GfxCardID::ATI_Radeon_9250 } } }, // ATI Radeon 9200 PRO / 9250
        { PCIDeviceKey(0x1002, 0x5960, 0x1FD3, 0x5960), { { GfxCardID::ATI_Radeon_9250 } } }, // (Palit) ATI Radeon 9250
        { PCIDeviceKey(0x1002, 0x5960, 0x1458, 0x4054), { { GfxCardID::ATI_Radeon_9250 } } }, // (Gigabyte) ATI Radeon 9250
        { PCIDeviceKey(0x1002, 0x5962), { { GfxCardID::ATI_Radeon_9200 } } }, // ATI Radeon 9200
        { PCIDeviceKey(0x1002, 0x5964), { { GfxCardID::ATI_Radeon_9200_SE } } }, // ATI Radeon 9200 SE
        { PCIDeviceKey(0x1002, 0x6738), { { GfxCardID::AMD_Radeon_HD_6870 } } }, // ATI Radeon HD 6870
        { PCIDeviceKey(0x1002, 0x6778, 0x1019, 0x0024), { { GfxCardID::AMD_Radeon_HD_7470 } } }, // AMD Radeon HD 7470
        { PCIDeviceKey(0x1002, 0x6778, 0x1019, 0x0027), { { GfxCardID::AMD_Radeon_HD_8470 } } }, // AMD Radeon HD 8470
        { PCIDeviceKey(0x1002, 0x6779, 0x174B, 0xA004), { { GfxCardID::AMD_Radeon_R5_230 } } }, // (Saphire) AMD Radeon R5 230
        { PCIDeviceKey(0x1002, 0x6779, 0x1019, 0x0016), { { GfxCardID::AMD_Radeon_HD_6450 } } }, // AMD Radeon HD 6450
        { PCIDeviceKey(0x1002, 0x6779, 0x1019, 0x2120), { { GfxCardID::AMD_Radeon_HD_6450 } } }, // AMD Radeon HD 6450
        { PCIDeviceKey(0x1002, 0x67EF),
          { { GfxCardID::AMD_Radeon_RX_460 },
            { GfxCardID::AMD_Radeon_RX_560 },
            { GfxCardID::AMD_Radeon_RX_560X } } }, // Radeon RX 460/560/560X
        { PCIDeviceKey(0x1002, 0x67FF),
          { { GfxCardID::AMD_Radeon_RX_550 },
            { GfxCardID::AMD_Radeon_RX_560 },
            { GfxCardID::AMD_Radeon_RX_560X } } }, // Radeon RX 550/560/560X
        { PCIDeviceKey(0x1002, 0x68F9),
          { { GfxCardID::AMD_Radeon_HD_7350 }, { GfxCardID::AMD_Radeon_HD_8350 } } }, // ATI Radeon HD 5000/6000/7350/8350
        { PCIDeviceKey(0x1002, 0x7240), { { GfxCardID::ATI_Radeon_X1950_XT } } }, // ATI Radeon X1950 XT
        { PCIDeviceKey(0x1002, 0x7244), { { GfxCardID::ATI_Radeon_X1950_XT } } }, // ATI Radeon X1950 XT
        { PCIDeviceKey(0x1002, 0x7280), { { GfxCardID::ATI_Radeon_X1950_Pro } } }, // ATI Radeon X1950 Pro
        { PCIDeviceKey(0x1002, 0x7288), { { GfxCardID::ATI_Radeon_X1950_GT } } }, // ATI Radeon X1950 GT
        { PCIDeviceKey(0x1002, 0x9490), { { GfxCardID::AMD_Radeon_HD_4670 } } }, // AMD Radeon HD 4670
        { PCIDeviceKey(0x1002, 0x9515), { { GfxCardID::AMD_Radeon_HD_3850 } } }, // ATI Radeon HD 3850
        { PCIDeviceKey(0x1002, 0x95C6), { { GfxCardID::AMD_Radeon_HD_3450, BoardInterface::AGP_8x } } }, // ATI Radeon HD 3450 AGP
        { PCIDeviceKey(0x1039, 0x0200), { { GfxCardID::SiS_6326 } } },
        { PCIDeviceKey(0x1039, 0x6326), { { GfxCardID::SiS_6326 } } },
        { PCIDeviceKey(0x1039, 0x0300), { { GfxCardID::SiS_300 }, { GfxCardID::SiS_305 } } },
        { PCIDeviceKey(0x1039, 0x0315), { { GfxCardID::SiS_315 } } },
        { PCIDeviceKey(0x104C, 0x3D07), { { GfxCardID::_3DLabs_Permedia_2 } } }, // Texas Instruments -> 3D Labs Permedia 2
        { PCIDeviceKey(0x121A, 0x0005),
          { { GfxCardID::_3dfx_Voodoo3_2000 },
            { GfxCardID::_3dfx_Voodoo3_3000 },
            { GfxCardID::_3dfx_Voodoo3_3500 } } }, // 3dfx Voodoo3 2000/3000/3500
        { PCIDeviceKey(0x121A, 0x0009),
          { { GfxCardID::_3dfx_Voodoo4_4500 }, { GfxCardID::_3dfx_Voodoo5_5500 } } }, // 3dfx Voodoo4 4500/ Voodoo5 5500
        { PCIDeviceKey(0x18CA, 0x0040),
          { { GfxCardID::XGI_Volari_V3XT },
            { GfxCardID::XGI_Volari_V5 },
            { GfxCardID::XGI_Volari_V8 },
            { GfxCardID::XGI_Volari_V8_Ultra } } }, // XGI Volari V3XT, V5, V8, V8 Ultra
        { PCIDeviceKey(0x3D3D, 0x0009), { { GfxCardID::_3DLabs_Permedia_2 } } },
        { PCIDeviceKey(0x3D3D, 0x0100), { { GfxCardID::_3DLabs_Permedia_2 } } },
    };
}