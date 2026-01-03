//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

namespace DataInfo
{
    /// @brief Graphics Cards Identifiers supported by CPU-M and MorphOS
    /// source: https://www.morphos-team.net/hardware
    enum class GfxCardID
    {
        // 3dfx Voodoo series (limited support)
        _3dfx_Voodoo3_2000,
        _3dfx_Voodoo3_3000,
        _3dfx_Voodoo3_3500,
        _3dfx_Voodoo4_4500,
        _3dfx_Voodoo5_5500,

        // 3D Labs Permedia series
        _3DLabs_Permedia_2,
        _3DLabs_Permedia_2V,

        // SiS series
        SiS_6326,
        SiS_300,
        SiS_305,
        SiS_315,

        // XGI Volari series
        XGI_Volari_V3XT,
        XGI_Volari_V5,
        XGI_Volari_V8,
        XGI_Volari_V8_Ultra,

        // ATI/AMD Rage series
        ATI_Rage_128_Pro,

        // ATI/AMD Radeon R100/RV200 series (7xxx)
        ATI_Radeon_7000, // rebranded Radeon VE
        ATI_Radeon_7200,
        ATI_Radeon_7500,
        ATI_Radeon_7500_LE,

        // ATI/AMD Radeon R200 series (8xxx-9xxx)
        ATI_Radeon_8500_LE,
        ATI_Radeon_8500,
        ATI_Radeon_9000,
        ATI_Radeon_9000_Pro,
        ATI_Radeon_9100,
        ATI_Radeon_9100_LE,
        ATI_Radeon_9200,
        ATI_Radeon_9200_SE,
        ATI_Radeon_9200_Pro,
        ATI_Radeon_9250,
        ATI_Radeon_9550_Mobile,
        ATI_Radeon_9600_Mobile,
        ATI_Radeon_9600_Pro,
        ATI_Radeon_9650,
        ATI_Radeon_9600_XT,
        ATI_Radeon_9700_Pro,
        ATI_Radeon_9700_Mobile,
        ATI_Radeon_9800,
        ATI_Radeon_9800_XT,

        // ATI/AMD Radeon R300-R500 series (X series)
        ATI_Radeon_X600_XT,
        ATI_Radeon_X800_XT,
        ATI_Radeon_X1050,
        ATI_Radeon_X1300,
        ATI_Radeon_X1300_Pro,
        ATI_Radeon_X1550,
        ATI_Radeon_X1600,
        ATI_Radeon_X1600_Pro,
        ATI_Radeon_X1800,
        ATI_Radeon_X1900_GT,
        ATI_Radeon_X1900_XT,
        ATI_Radeon_X1900_Pro,
        ATI_Radeon_X1950_XT,
        ATI_Radeon_X1950_XTX,
        ATI_Radeon_X1950_Pro,
        ATI_Radeon_X1950_GT,
        ATI_FireGL_X3,

        // AMD Radeon HD 2xxx series
        AMD_Radeon_HD_2350,
        AMD_Radeon_HD_2400,
        AMD_Radeon_HD_2400_Pro,
        AMD_Radeon_HD_2400_XT,
        AMD_Radeon_HD_2600,
        AMD_Radeon_HD_2600_Pro,
        AMD_Radeon_HD_2600_XT,
        AMD_Radeon_HD_2900_GT,
        AMD_Radeon_HD_2900_Pro,
        AMD_Radeon_HD_2900_XT,

        // AMD Radeon HD 3xxx series
        AMD_Radeon_HD_3450,
        AMD_Radeon_HD_3470,
        AMD_Radeon_HD_3550,
        AMD_Radeon_HD_3570,
        AMD_Radeon_HD_3610,
        AMD_Radeon_HD_3650,
        AMD_Radeon_HD_3730,
        AMD_Radeon_HD_3750,
        AMD_Radeon_HD_3830,
        AMD_Radeon_HD_3850,
        AMD_Radeon_HD_3870,

        // AMD Radeon HD 4xxx series
        AMD_Radeon_HD_4350,
        AMD_Radeon_HD_4550,
        AMD_Radeon_HD_4570,
        AMD_Radeon_HD_4580,
        AMD_Radeon_HD_4670,
        AMD_Radeon_HD_4750,
        AMD_Radeon_HD_4770,
        AMD_Radeon_HD_4810,
        AMD_Radeon_HD_4830,
        AMD_Radeon_HD_4850,
        AMD_Radeon_HD_4860,
        AMD_Radeon_HD_4870,
        AMD_Radeon_HD_4890,

        // AMD Radeon HD 5xxx series
        AMD_Radeon_HD_5450,
        AMD_Radeon_HD_5550,
        AMD_Radeon_HD_5570,
        AMD_Radeon_HD_5610,
        AMD_Radeon_HD_5670,
        AMD_Radeon_HD_5750,
        AMD_Radeon_HD_5770,
        AMD_Radeon_HD_5830,
        AMD_Radeon_HD_5850,
        AMD_Radeon_HD_5870,
        AMD_Radeon_HD_5870_Eyefinity_Edition,

        // AMD Radeon HD 6xxx series
        AMD_Radeon_HD_6350,
        AMD_Radeon_HD_6450,
        AMD_Radeon_HD_6570,
        AMD_Radeon_HD_6670,
        AMD_Radeon_HD_6750,
        AMD_Radeon_HD_6770,
        AMD_Radeon_HD_6790,
        AMD_Radeon_HD_6850,
        AMD_Radeon_HD_6870,

        // AMD Radeon HD 7xxx series
        AMD_Radeon_HD_7350,
        AMD_Radeon_HD_7450,
        AMD_Radeon_HD_7470,
        AMD_Radeon_HD_7510,
        AMD_Radeon_HD_7570,
        AMD_Radeon_HD_7670,

        // AMD Radeon HD 8xxx series
        AMD_Radeon_HD_8350,
        AMD_Radeon_HD_8450,
        AMD_Radeon_HD_8470,
        AMD_Radeon_HD_8490,

        // AMD Radeon R5 series
        AMD_Radeon_R5_210,
        AMD_Radeon_R5_220,
        AMD_Radeon_R5_230,
        AMD_Radeon_R5_235,
        AMD_Radeon_R5_235X,

        // AMD FirePro series
        AMD_FirePro_V3800,
        AMD_FirePro_V4800,

        // AMD Radeon RX series
        AMD_Radeon_RX_460,
        AMD_Radeon_RX_550,
        AMD_Radeon_RX_560,
        AMD_Radeon_RX_560X,
    };
}
