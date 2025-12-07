//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GfxCardSpec.hpp"

#include "Core/ToString.hpp"

// data info resources:
// https://vgamuseum.info
// https://www.techpowerup.com/gpu-specs/
// wikipedia
// product datasheets from manufacturers

namespace DataInfo
{
    const std::map<GfxCardID, GfxCardSpec> gfxCard2spec {
        {
            GfxCardID::_3dfx_Voodoo3_2000,
            { "Voodoo3 2000",
              ManufacturerID::_3DFX,
              GPUID::_3dfx_Avenger,
              std::nullopt,
              1999,
              { BoardInterface::AGP_2x, BoardInterface::PCI },
              15,
              { { 143'000, std::nullopt, 286'000 } } },
        },
        {
            GfxCardID::_3dfx_Voodoo3_3000,
            { "Voodoo3 2000",
              ManufacturerID::_3DFX,
              GPUID::_3dfx_Avenger,
              std::nullopt,
              1999,
              { BoardInterface::AGP_2x, BoardInterface::PCI },
              15,
              { { 166'000, std::nullopt, 332'000 } } },
        },
        {
            GfxCardID::_3dfx_Voodoo3_3500,
            { "Voodoo3 3500",
              ManufacturerID::_3DFX,
              GPUID::_3dfx_Avenger,
              std::nullopt,
              1999,
              { BoardInterface::AGP_2x },
              15,
              { { 183'000, std::nullopt, 366'000 } } },
        },
        {
            GfxCardID::_3dfx_Voodoo4_4500,
            { "Voodoo4 4500",
              ManufacturerID::_3DFX,
              GPUID::_3dfx_VSA_100,
              std::nullopt,
              2000,
              { BoardInterface::AGP_4x, BoardInterface::PCI },
              15,
              { { 332'000, std::nullopt, 332'000 } } },
        },
        {
            GfxCardID::_3dfx_Voodoo5_5500,
            { "Voodoo5 5500",
              ManufacturerID::_3DFX,
              GPUID::_3dfx_VSA_100,
              std::nullopt,
              2000,
              { BoardInterface::AGP_2x, BoardInterface::PCI },
              30,
              { { 332'000, std::nullopt, 332'000 } } },
        },
        {
            GfxCardID::_3DLabs_Permedia_2,
            { "Permedia 2",
              ManufacturerID::_3DLABS,
              GPUID::_3DLabs_Permedia_2,
              std::nullopt,
              1997,
              { BoardInterface::PCI },
              std::nullopt,
              { { 83'000, std::nullopt, 83'000 } } },
        },
        {
            GfxCardID::_3DLabs_Permedia_2V,
            { "Permedia 2V",
              ManufacturerID::_3DLABS,
              GPUID::_3DLabs_Permedia_2V,
              std::nullopt,
              1998,
              { BoardInterface::PCI, BoardInterface::AGP_1x },
              std::nullopt,
              { { 83'000, std::nullopt, 83'000 } } },
        },
        {
            GfxCardID::SiS_6326,
            { "6326",
              ManufacturerID::SIS,
              GPUID::SiS_6326,
              std::nullopt,
              1997,
              { BoardInterface::AGP_2x, BoardInterface::PCI },
              std::nullopt,
              { { 90'000, std::nullopt, 90'000 } } },
        },
        {
            GfxCardID::SiS_300,
            { "300",
              ManufacturerID::SIS,
              GPUID::SiS_300,
              std::nullopt,
              1999,
              { BoardInterface::AGP_4x },
              std::nullopt,
              { { 125'000, std::nullopt, 125'000 } } },
        },
        {
            GfxCardID::SiS_305,
            { "305",
              ManufacturerID::SIS,
              GPUID::SiS_305,
              std::nullopt,
              2000,
              { BoardInterface::AGP_2x },
              std::nullopt,
              { { 125'000, std::nullopt, 125'000 } } },
        },
        {
            GfxCardID::SiS_315,
            { "Mirage 315",
              ManufacturerID::SIS,
              GPUID::SiS_Mirage_315,
              std::nullopt,
              2000,
              { BoardInterface::AGP_4x, BoardInterface::PCI },
              std::nullopt,
              { { 332'000, std::nullopt, 664'000 } } },
        },
        {
            GfxCardID::XGI_Volari_V3XT,
            { "Volari V3XT",
              ManufacturerID::XGI,
              GPUID::XGI_XG42,
              std::nullopt,
              2003,
              { BoardInterface::AGP_8x },
              std::nullopt,
              { { 500'000, 62'500, 1'000'000 } } },
        },
        {
            GfxCardID::XGI_Volari_V5,
            { "Volari V5",
              ManufacturerID::XGI,
              GPUID::XGI_XG41,
              std::nullopt,
              2003,
              { BoardInterface::AGP_8x },
              std::nullopt,
              { { 625'000, 162'500, 1'300'000 } } },
        },
        {
            GfxCardID::XGI_Volari_V8,
            { "Volari V8",
              ManufacturerID::XGI,
              GPUID::XGI_XG40,
              std::nullopt,
              2003,
              { BoardInterface::AGP_8x },
              std::nullopt,
              { { 1'250'000, 156'250, 2'500'000 } } },
        },
        {
            GfxCardID::XGI_Volari_V8_Ultra,
            { "Volari V8 Ultra",
              ManufacturerID::XGI,
              GPUID::XGI_XG40,
              std::nullopt,
              2003,
              { BoardInterface::AGP_8x },
              std::nullopt,
              { { 1'400'000, 175'000, 2'800'000 } } },
        },
        {
            GfxCardID::ATI_Rage_128_Pro,
            { "Rage 128 Pro",
              ManufacturerID::ATI,
              GPUID::ATI_Rage_128_Pro,
              std::nullopt,
              1999,
              { BoardInterface::AGP_4x },
              std::nullopt,
              { { 260'000, 8'000, 260'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_7500,
            { "Radeon 7500",
              ManufacturerID::ATI,
              GPUID::ATI_RV200,
              GPUVariantID::ATI_RV200_500,
              2001,
              { BoardInterface::AGP_4x },
              28,
              { { 580'000, 72'500, 1'740'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_9550_Mobile,
            { "Mobility Radeon 9550",
              ManufacturerID::ATI,
              GPUID::ATI_M12,
              std::nullopt,
              2004,
              { BoardInterface::AGP_4x },
              std::nullopt,
              { { 1'000'000, 125'000, 1'000'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_9200,
            { "Radeon 9200",
              ManufacturerID::ATI,
              GPUID::ATI_RV280,
              std::nullopt,
              2003,
              { BoardInterface::AGP_8x },
              28,
              { { 1'000'000, 62'500, 1'000'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_9200_Pro,
            { "Radeon 9200 Pro",
              ManufacturerID::ATI,
              GPUID::ATI_RV280,
              std::nullopt,
              2003,
              { BoardInterface::AGP_8x },
              28,
              { { 960'000, 60'000, 960'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_9250,
            { "Radeon 9250",
              ManufacturerID::ATI,
              GPUID::ATI_RV280,
              std::nullopt,
              2004,
              { BoardInterface::AGP_8x },
              28,
              { { 960'000, 60'000, 960'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_9600_Pro,
            { "Radeon 9600 Pro",
              ManufacturerID::ATI,
              GPUID::ATI_RV350,
              std::nullopt,
              2003,
              { BoardInterface::AGP_8x },
              18,
              { { 1'600'000, 200'000, 1'600'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_9600_Mobile,
            { "Mobility Radeon 9600",
              ManufacturerID::ATI,
              GPUID::ATI_M10,
              std::nullopt,
              2004,
              { BoardInterface::AGP_8x },
              std::nullopt,
              { { 1'200'000, 150'000, 1'200'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_9600_XT,
            { "Radeon 9600 XT",
              ManufacturerID::ATI,
              GPUID::ATI_RV360,
              std::nullopt,
              2003,
              { BoardInterface::AGP_8x },
              22,
              { { 2'000'000, 250'000, 2'000'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_9700_Mobile,
            { "Mobility Radeon 9700",
              ManufacturerID::ATI,
              GPUID::ATI_M11,
              std::nullopt,
              2004,
              { BoardInterface::AGP_8x },
              std::nullopt,
              { { 1'800'000, 225'000, 1'800'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_9800,
            { "Radeon 9800",
              ManufacturerID::ATI,
              GPUID::ATI_R350,
              std::nullopt,
              2003,
              { BoardInterface::AGP_8x },
              37,
              { { 2'600'000, 325'000, 2'600'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_X600_XT,
            { "Radeon X600 XT",
              ManufacturerID::ATI,
              GPUID::ATI_RV380,
              GPUVariantID::ATI_RV380_XT,
              2004,
              { BoardInterface::PCIe_x16 },
              25,
              { { 2'000'000, 250'000, 2'000'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_X1050,
            { "Radeon X1050",
              ManufacturerID::ATI,
              GPUID::ATI_RV360,
              std::nullopt,
              2007,
              { BoardInterface::AGP_8x },
              24,
              { { 1'000'000, 125'000, 1'000'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_X1950_XTX,
            { "Radeon X1950 XTX",
              ManufacturerID::ATI,
              GPUID::ATI_R580_PLUS,
              GPUVariantID::ATI_R580_PLUS_XT,
              2006,
              { BoardInterface::PCIe_x16 },
              125,
              { { 10'400'000, 1'300'000, 10'400'000 } } },
        },
        {
            GfxCardID::ATI_Radeon_X1950_Pro,
            { "Radeon X1950 Pro",
              ManufacturerID::ATI,
              GPUID::ATI_RV570,
              std::nullopt,
              2006,
              { BoardInterface::AGP_8x, BoardInterface::PCIe_x16 },
              66,
              { { 6'900'000, 1'150'000, 6'900'000 } } },
        },
        {
            GfxCardID::AMD_Radeon_HD_3450,
            { "Radeon HD 3450",
              ManufacturerID::AMD,
              GPUID::ATI_RV620,
              GPUVariantID::ATI_RV620_LE,
              2008,
              { BoardInterface::PCIe_2_x16 },
              25,
              { { 2'400'000, std::nullopt, 2'400'000, 48'000'000, std::nullopt } } },
        },
        {
            GfxCardID::AMD_Radeon_HD_3850,
            { "Radeon HD 3850",
              ManufacturerID::AMD,
              GPUID::ATI_RV670,
              GPUVariantID::ATI_RV670_Pro,
              2008,
              { BoardInterface::AGP_8x, BoardInterface::PCIe_2_x16 },
              75,
              { { 10'690'000, std::nullopt, 10'690'000, 427'500'000, 85'500'0000 } } },
        },
        {
            GfxCardID::AMD_Radeon_HD_4670,
            { "Radeon HD 4670",
              ManufacturerID::AMD,
              GPUID::ATI_RV730,
              GPUVariantID::ATI_RV730_XT,
              2008,
              { BoardInterface::AGP_8x, BoardInterface::PCIe_2_x16 },
              59,
              { { 6'000'000, std::nullopt, 24'000'000, 480'000'000, std::nullopt } } },
        },
        {
            GfxCardID::AMD_Radeon_HD_6870,
            { "Radeon HD 6870",
              ManufacturerID::AMD,
              GPUID::AMD_BARTS,
              GPUVariantID::AMD_BARTS_XT,
              2010,
              { BoardInterface::PCIe_2_x16 },
              151,
              { { 28'800'000, std::nullopt, 50'400'000, 2'016'000'000, std::nullopt } } },
        },
        {
            GfxCardID::AMD_Radeon_RX_460,
            { "Radeon RX 460",
              ManufacturerID::AMD,
              GPUID::AMD_BAFFIN,
              GPUVariantID::AMD_BAFFIN_PRO,
              2016,
              { BoardInterface::PCIe_3_x8 },
              75,
              { { 19'200'000, std::nullopt, 67'200'000, 2'150'000'000, 134'400'000 } } },
        },
    };

    std::string PerformancePixelRateToString(const unsigned long long rate)
    {
        return ToString::FromSIValue(rate * 1000, "Pixels/s");
    }

    std::string PerformanceVertexRateToString(const unsigned long long rate)
    {
        return ToString::FromSIValue(rate * 1000, "Vertices/s");
    }

    std::string PerformanceTextureRateToString(const unsigned long long rate)
    {
        return ToString::FromSIValue(rate * 1000, "Texels/s");
    }

    std::string PerformanceFP32RateToString(const unsigned long long rate)
    {
        return ToString::FromSIValue(rate * 1000, "FLOPS");
    }

    std::string PerformanceFP64RateToString(const unsigned long long rate)
    {
        return ToString::FromSIValue(rate * 1000, "FLOPS");
    }
}

namespace std
{
    std::string to_string(const DataInfo::BoardInterface &interface)
    {
        switch (interface)
        {
            case DataInfo::BoardInterface::PCI:
                return "PCI";
            case DataInfo::BoardInterface::AGP_1x:
                return "AGP 1x";
            case DataInfo::BoardInterface::AGP_2x:
                return "AGP 2x";
            case DataInfo::BoardInterface::AGP_4x:
                return "AGP 4x";
            case DataInfo::BoardInterface::AGP_8x:
                return "AGP 8x";
            case DataInfo::BoardInterface::PCIe_x16:
                return "PCIe x16";
            case DataInfo::BoardInterface::PCIe_2_x16:
                return "PCIe 2.0 x16";
            case DataInfo::BoardInterface::PCIe_3_x8:
                return "PCIe 3.0 x8";
            default:
                return "Unknown Interface";
        }
    }
}
