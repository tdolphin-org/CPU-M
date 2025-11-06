//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "PCI2IDSpec.hpp"

namespace DataInfo
{
    const std::map<std::pair<uint16_t, uint16_t>, std::vector<GfxBoardID>> vendorAndDevice2gfxBoardId {
        { { 0x1002, 0x3E50 }, { GfxBoardID::ATI_Radeon_X600_XT } }, // ATI Radeon X600 XT
        { { 0x1002, 0x4E56 }, { GfxBoardID::ATI_Radeon_9550_Mobile } }, // ATI Mobility Radeon 9550
        { { 0x1002, 0x4150 }, { GfxBoardID::ATI_Radeon_9600_Pro } }, // ATI Radeon 9600 Pro
        { { 0x1002, 0x4152 }, { GfxBoardID::ATI_Radeon_9600_XT, GfxBoardID::ATI_Radeon_X1050 } }, // ATI Radeon 9600XT/X1050
        { { 0x1002, 0x4E48 }, { GfxBoardID::ATI_Radeon_9800 } }, // ATI Radeon 9800
        { { 0x1002, 0x4E50 }, { GfxBoardID::ATI_Radeon_9600_Mobile, GfxBoardID::ATI_Radeon_9700_Mobile } }, // ATI Radeon 9600/9700 Mobile
        { { 0x1002, 0x5046 }, { GfxBoardID::ATI_Rage_128_Pro } }, // ATI Rage 128 Pro
        { { 0x1002, 0x5962 }, { GfxBoardID::ATI_Radeon_9200 } }, // ATI Radeon 9200
        { { 0x1002, 0x68F9 }, { GfxBoardID::AMD_Radeon_HD_7350, GfxBoardID::AMD_Radeon_HD_8350 } }, // ATI Radeon HD 5000/6000/7350/8350
        { { 0x1002, 0x7280 }, { GfxBoardID::ATI_Radeon_X1950_Pro } }, // ATI Radeon X1950 Pro
        { { 0x1002, 0x9515 }, { GfxBoardID::AMD_Radeon_HD_3850 } }, // ATI Radeon HD 3850
        { { 0x1039, 0x0200 }, { GfxBoardID::SiS_6326 } },
        { { 0x1039, 0x6326 }, { GfxBoardID::SiS_6326 } },
        { { 0x1039, 0x0300 }, { GfxBoardID::SiS_300, GfxBoardID::SiS_305 } },
        { { 0x1039, 0x0315 }, { GfxBoardID::SiS_315 } },
        { { 0x104C, 0x3D07 }, { GfxBoardID::_3DLabs_Permedia_2 } }, // Texas Instruments -> 3D Labs Permedia 2
        { { 0x121A, 0x0005 },
          { GfxBoardID::_3dfx_Voodoo3_2000, GfxBoardID::_3dfx_Voodoo3_3000, GfxBoardID::_3dfx_Voodoo3_3500 } }, // 3dfx Voodoo3 2000/3000/3500
        { { 0x121A, 0x0009 }, { GfxBoardID::_3dfx_Voodoo4_4500, GfxBoardID::_3dfx_Voodoo5_5500 } }, // 3dfx Voodoo4 4500/ Voodoo5 5500
        { { 0x18CA, 0x0040 },
          { GfxBoardID::XGI_Volari_V3XT, GfxBoardID::XGI_Volari_V5, GfxBoardID::XGI_Volari_V8,
            GfxBoardID::XGI_Volari_V8_Ultra } }, // XGI Volari V3XT, V5, V8, V8 Ultra
        { { 0x3D3D, 0x0009 }, { GfxBoardID::_3DLabs_Permedia_2 } },
        { { 0x3D3D, 0x0100 }, { GfxBoardID::_3DLabs_Permedia_2 } },
    };
}