//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "GfxCardTypes.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>

namespace DataInfo
{
    std::optional<GfxCardID> StringToGfxCardID(const std::string &str)
    {
        static std::map<std::string, GfxCardID> map = {
            // 3dfx Voodoo series
            { "3dfx_voodoo3_2000", GfxCardID::_3dfx_Voodoo3_2000 },
            { "3dfx_voodoo3_3000", GfxCardID::_3dfx_Voodoo3_3000 },
            { "3dfx_voodoo3_3500", GfxCardID::_3dfx_Voodoo3_3500 },
            { "3dfx_voodoo4_4500", GfxCardID::_3dfx_Voodoo4_4500 },
            { "3dfx_voodoo5_5500", GfxCardID::_3dfx_Voodoo5_5500 },

            // 3D Labs Permedia series
            { "3dlabs_permedia_2", GfxCardID::_3DLabs_Permedia_2 },
            { "3dlabs_permedia_2v", GfxCardID::_3DLabs_Permedia_2V },

            // SiS series
            { "sis_6326", GfxCardID::SiS_6326 },
            { "sis_300", GfxCardID::SiS_300 },
            { "sis_305", GfxCardID::SiS_305 },
            { "sis_315", GfxCardID::SiS_315 },

            // XGI Volari series
            { "xgi_volari_v3xt", GfxCardID::XGI_Volari_V3XT },
            { "xgi_volari_v5", GfxCardID::XGI_Volari_V5 },
            { "xgi_volari_v8", GfxCardID::XGI_Volari_V8 },
            { "xgi_volari_v8_ultra", GfxCardID::XGI_Volari_V8_Ultra },

            // ATI/AMD Rage series
            { "ati_rage_128_pro", GfxCardID::ATI_Rage_128_Pro },

            // ATI/AMD Radeon R100 series (7xxx)
            { "ati_radeon_7000", GfxCardID::ATI_Radeon_7000 },
            { "ati_radeon_7200", GfxCardID::ATI_Radeon_7200 },
            { "ati_radeon_7500", GfxCardID::ATI_Radeon_7500 },
            { "ati_radeon_7500_le", GfxCardID::ATI_Radeon_7500_LE },

            // ATI/AMD Radeon R(V)2x0 series (8xxx-9xxx)
            { "ati_radeon_8500_le", GfxCardID::ATI_Radeon_8500_LE },
            { "ati_radeon_8500", GfxCardID::ATI_Radeon_8500 },
            { "ati_radeon_8500_dv", GfxCardID::ATI_Radeon_8500_DV },
            { "ati_radeon_9000", GfxCardID::ATI_Radeon_9000 },
            { "ati_radeon_9000_pro", GfxCardID::ATI_Radeon_9000_Pro },
            { "ati_radeon_9100", GfxCardID::ATI_Radeon_9100 },
            { "ati_radeon_9100_le", GfxCardID::ATI_Radeon_9100_LE },
            { "ati_radeon_9200", GfxCardID::ATI_Radeon_9200 },
            { "ati_radeon_9200_se", GfxCardID::ATI_Radeon_9200_SE },
            { "ati_radeon_9200_pro", GfxCardID::ATI_Radeon_9200_Pro },
            { "ati_radeon_9250", GfxCardID::ATI_Radeon_9250 },
            { "ati_radeon_9550", GfxCardID::ATI_Radeon_9550 },
            { "ati_radeon_9550_mobile", GfxCardID::ATI_Radeon_9550_Mobile },
            { "ati_radeon_9600_mobile", GfxCardID::ATI_Radeon_9600_Mobile },
            { "ati_radeon_9600", GfxCardID::ATI_Radeon_9600 },
            { "ati_radeon_9600_pro", GfxCardID::ATI_Radeon_9600_Pro },
            { "ati_radeon_9650", GfxCardID::ATI_Radeon_9650 },
            { "ati_radeon_9600_xt", GfxCardID::ATI_Radeon_9600_XT },
            { "ati_radeon_9600_se", GfxCardID::ATI_Radeon_9600_SE },
            { "ati_radeon_9700_pro", GfxCardID::ATI_Radeon_9700_Pro },
            { "ati_radeon_9700_mobile", GfxCardID::ATI_Radeon_9700_Mobile },
            { "ati_radeon_9800", GfxCardID::ATI_Radeon_9800 },
            { "ati_radeon_9800_xt", GfxCardID::ATI_Radeon_9800_XT },

            // ATI/AMD Radeon R300-R500 series (X series)
            { "ati_radeon_x600_xt", GfxCardID::ATI_Radeon_X600_XT },
            { "ati_radeon_x800_xt", GfxCardID::ATI_Radeon_X800_XT },
            { "ati_radeon_x1050", GfxCardID::ATI_Radeon_X1050 },
            { "ati_radeon_x1300", GfxCardID::ATI_Radeon_X1300 },
            { "ati_radeon_x1300_pro", GfxCardID::ATI_Radeon_X1300_Pro },
            { "ati_radeon_x1550", GfxCardID::ATI_Radeon_X1550 },
            { "ati_radeon_x1600", GfxCardID::ATI_Radeon_X1600 },
            { "ati_radeon_x1600_pro", GfxCardID::ATI_Radeon_X1600_Pro },
            { "ati_radeon_x1650_pro", GfxCardID::ATI_Radeon_X1650_Pro },
            { "ati_radeon_x1800", GfxCardID::ATI_Radeon_X1800 },
            { "ati_radeon_x1900_gt", GfxCardID::ATI_Radeon_X1900_GT },
            { "ati_radeon_x1900_xt", GfxCardID::ATI_Radeon_X1900_XT },
            { "ati_radeon_x1900_pro", GfxCardID::ATI_Radeon_X1900_Pro },
            { "ati_radeon_x1950_xt", GfxCardID::ATI_Radeon_X1950_XT },
            { "ati_radeon_x1950_xtx", GfxCardID::ATI_Radeon_X1950_XTX },
            { "ati_radeon_x1950_pro", GfxCardID::ATI_Radeon_X1950_Pro },
            { "ati_radeon_x1950_gt", GfxCardID::ATI_Radeon_X1950_GT },
            { "ati_firegl_x3", GfxCardID::ATI_FireGL_X3 },

            // AMD Radeon HD 2xxx series
            { "amd_radeon_hd_2350", GfxCardID::AMD_Radeon_HD_2350 },
            { "amd_radeon_hd_2400", GfxCardID::AMD_Radeon_HD_2400 },
            { "amd_radeon_hd_2400_pro", GfxCardID::AMD_Radeon_HD_2400_Pro },
            { "amd_radeon_hd_2400_xt", GfxCardID::AMD_Radeon_HD_2400_XT },
            { "amd_radeon_hd_2600", GfxCardID::AMD_Radeon_HD_2600 },
            { "amd_radeon_hd_2600_pro", GfxCardID::AMD_Radeon_HD_2600_Pro },
            { "amd_radeon_hd_2600_xt", GfxCardID::AMD_Radeon_HD_2600_XT },
            { "amd_radeon_hd_2900_gt", GfxCardID::AMD_Radeon_HD_2900_GT },
            { "amd_radeon_hd_2900_pro", GfxCardID::AMD_Radeon_HD_2900_Pro },
            { "amd_radeon_hd_2900_xt", GfxCardID::AMD_Radeon_HD_2900_XT },

            // AMD Radeon HD 3xxx series
            { "amd_radeon_hd_3450", GfxCardID::AMD_Radeon_HD_3450 },
            { "amd_radeon_hd_3470", GfxCardID::AMD_Radeon_HD_3470 },
            { "amd_radeon_hd_3550", GfxCardID::AMD_Radeon_HD_3550 },
            { "amd_radeon_hd_3570", GfxCardID::AMD_Radeon_HD_3570 },
            { "amd_radeon_hd_3610", GfxCardID::AMD_Radeon_HD_3610 },
            { "amd_radeon_hd_3650", GfxCardID::AMD_Radeon_HD_3650 },
            { "amd_radeon_hd_3730", GfxCardID::AMD_Radeon_HD_3730 },
            { "amd_radeon_hd_3750", GfxCardID::AMD_Radeon_HD_3750 },
            { "amd_radeon_hd_3830", GfxCardID::AMD_Radeon_HD_3830 },
            { "amd_radeon_hd_3850", GfxCardID::AMD_Radeon_HD_3850 },
            { "amd_radeon_hd_3870", GfxCardID::AMD_Radeon_HD_3870 },

            // AMD Radeon HD 4xxx series
            { "amd_radeon_hd_4350", GfxCardID::AMD_Radeon_HD_4350 },
            { "amd_radeon_hd_4550", GfxCardID::AMD_Radeon_HD_4550 },
            { "amd_radeon_hd_4570", GfxCardID::AMD_Radeon_HD_4570 },
            { "amd_radeon_hd_4580", GfxCardID::AMD_Radeon_HD_4580 },
            { "amd_radeon_hd_4670", GfxCardID::AMD_Radeon_HD_4670 },
            { "amd_radeon_hd_4750", GfxCardID::AMD_Radeon_HD_4750 },
            { "amd_radeon_hd_4770", GfxCardID::AMD_Radeon_HD_4770 },
            { "amd_radeon_hd_4810", GfxCardID::AMD_Radeon_HD_4810 },
            { "amd_radeon_hd_4830", GfxCardID::AMD_Radeon_HD_4830 },
            { "amd_radeon_hd_4850", GfxCardID::AMD_Radeon_HD_4850 },
            { "amd_radeon_hd_4860", GfxCardID::AMD_Radeon_HD_4860 },
            { "amd_radeon_hd_4870", GfxCardID::AMD_Radeon_HD_4870 },
            { "amd_radeon_hd_4890", GfxCardID::AMD_Radeon_HD_4890 },

            // AMD Radeon HD 5xxx series
            { "amd_radeon_hd_5450", GfxCardID::AMD_Radeon_HD_5450 },
            { "amd_radeon_hd_5550", GfxCardID::AMD_Radeon_HD_5550 },
            { "amd_radeon_hd_5570", GfxCardID::AMD_Radeon_HD_5570 },
            { "amd_radeon_hd_5610", GfxCardID::AMD_Radeon_HD_5610 },
            { "amd_radeon_hd_5670", GfxCardID::AMD_Radeon_HD_5670 },
            { "amd_radeon_hd_5750", GfxCardID::AMD_Radeon_HD_5750 },
            { "amd_radeon_hd_5770", GfxCardID::AMD_Radeon_HD_5770 },
            { "amd_radeon_hd_5830", GfxCardID::AMD_Radeon_HD_5830 },
            { "amd_radeon_hd_5850", GfxCardID::AMD_Radeon_HD_5850 },
            { "amd_radeon_hd_5870", GfxCardID::AMD_Radeon_HD_5870 },
            { "amd_radeon_hd_5870_eyefinity_edition", GfxCardID::AMD_Radeon_HD_5870_Eyefinity_Edition },

            // AMD Radeon HD 6xxx series
            { "amd_radeon_hd_6350", GfxCardID::AMD_Radeon_HD_6350 },
            { "amd_radeon_hd_6450", GfxCardID::AMD_Radeon_HD_6450 },
            { "amd_radeon_hd_6570", GfxCardID::AMD_Radeon_HD_6570 },
            { "amd_radeon_hd_6670", GfxCardID::AMD_Radeon_HD_6670 },
            { "amd_radeon_hd_6750", GfxCardID::AMD_Radeon_HD_6750 },
            { "amd_radeon_hd_6770", GfxCardID::AMD_Radeon_HD_6770 },
            { "amd_radeon_hd_6790", GfxCardID::AMD_Radeon_HD_6790 },
            { "amd_radeon_hd_6850", GfxCardID::AMD_Radeon_HD_6850 },
            { "amd_radeon_hd_6870", GfxCardID::AMD_Radeon_HD_6870 },

            // AMD Radeon HD 7xxx series
            { "amd_radeon_hd_7350", GfxCardID::AMD_Radeon_HD_7350 },
            { "amd_radeon_hd_7450", GfxCardID::AMD_Radeon_HD_7450 },
            { "amd_radeon_hd_7470", GfxCardID::AMD_Radeon_HD_7470 },
            { "amd_radeon_hd_7510", GfxCardID::AMD_Radeon_HD_7510 },
            { "amd_radeon_hd_7570", GfxCardID::AMD_Radeon_HD_7570 },
            { "amd_radeon_hd_7670", GfxCardID::AMD_Radeon_HD_7670 },

            // AMD Radeon HD 8xxx series
            { "amd_radeon_hd_8350", GfxCardID::AMD_Radeon_HD_8350 },
            { "amd_radeon_hd_8450", GfxCardID::AMD_Radeon_HD_8450 },
            { "amd_radeon_hd_8470", GfxCardID::AMD_Radeon_HD_8470 },
            { "amd_radeon_hd_8490", GfxCardID::AMD_Radeon_HD_8490 },
            { "amd_radeon_hd_8550", GfxCardID::AMD_Radeon_HD_8550 },

            // AMD Radeon R5 series
            { "amd_radeon_r5_210", GfxCardID::AMD_Radeon_R5_210 },
            { "amd_radeon_r5_220", GfxCardID::AMD_Radeon_R5_220 },
            { "amd_radeon_r5_230", GfxCardID::AMD_Radeon_R5_230 },
            { "amd_radeon_r5_235", GfxCardID::AMD_Radeon_R5_235 },
            { "amd_radeon_r5_235x", GfxCardID::AMD_Radeon_R5_235X },

            // AMD FirePro series
            { "amd_firepro_v3800", GfxCardID::AMD_FirePro_V3800 },
            { "amd_firepro_v4800", GfxCardID::AMD_FirePro_V4800 },

            // AMD Radeon RX series
            { "amd_radeon_rx_460", GfxCardID::AMD_Radeon_RX_460 },
            { "amd_radeon_rx_550", GfxCardID::AMD_Radeon_RX_550 },
            { "amd_radeon_rx_560", GfxCardID::AMD_Radeon_RX_560 },
            { "amd_radeon_rx_560x", GfxCardID::AMD_Radeon_RX_560X },
        };

        std::string lowerStr = str;
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) { return std::tolower(c); });

        auto it = map.find(lowerStr);
        if (it != map.end())
            return it->second;

        std::cerr << __PRETTY_FUNCTION__ << ": Unknown graphics card string: " << str << std::endl;

        return std::nullopt;
    }
}
