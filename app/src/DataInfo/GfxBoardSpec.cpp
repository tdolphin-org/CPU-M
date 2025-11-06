//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GfxBoardSpec.hpp"

#include "Core/ToString.hpp"

// data info resources:
// https://vgamuseum.info
// https://www.techpowerup.com/gpu-specs/
// wikipedia
// product datasheets from manufacturers

namespace DataInfo
{
    const std::map<GfxBoardID, GfxBoardSpec> gfxBoard2spec {
        {
            GfxBoardID::_3dfx_Voodoo3_2000,
            { "Voodoo3 2000",
              ManufacturerID::_3DFX,
              GPUID::_3dfx_Avenger,
              1999,
              { GfxBoardInterface::AGP_2x, GfxBoardInterface::PCI },
              15,
              { { 143'000, std::nullopt, 286'000 } } },
        },
        {
            GfxBoardID::_3dfx_Voodoo3_3000,
            { "Voodoo3 2000",
              ManufacturerID::_3DFX,
              GPUID::_3dfx_Avenger,
              1999,
              { GfxBoardInterface::AGP_2x, GfxBoardInterface::PCI },
              15,
              { { 166'000, std::nullopt, 332'000 } } },
        },
        {
            GfxBoardID::_3dfx_Voodoo3_3500,
            { "Voodoo3 3500",
              ManufacturerID::_3DFX,
              GPUID::_3dfx_Avenger,
              1999,
              { GfxBoardInterface::AGP_2x },
              15,
              { { 183'000, std::nullopt, 366'000 } } },
        },
        {
            GfxBoardID::_3dfx_Voodoo4_4500,
            { "Voodoo4 4500",
              ManufacturerID::_3DFX,
              GPUID::_3dfx_VSA_100,
              2000,
              { GfxBoardInterface::AGP_4x, GfxBoardInterface::PCI },
              15,
              { { 332'000, std::nullopt, 332'000 } } },
        },
        {
            GfxBoardID::_3dfx_Voodoo5_5500,
            { "Voodoo5 5500",
              ManufacturerID::_3DFX,
              GPUID::_3dfx_VSA_100,
              2000,
              { GfxBoardInterface::AGP_2x, GfxBoardInterface::PCI },
              30,
              { { 332'000, std::nullopt, 332'000 } } },
        },
        {
            GfxBoardID::_3DLabs_Permedia_2,
            { "Permedia 2",
              ManufacturerID::_3DLABS,
              GPUID::_3DLabs_Permedia_2,
              1997,
              { GfxBoardInterface::PCI },
              std::nullopt,
              { { 83'000, std::nullopt, 83'000 } } },
        },
        {
            GfxBoardID::_3DLabs_Permedia_2V,
            { "Permedia 2V",
              ManufacturerID::_3DLABS,
              GPUID::_3DLabs_Permedia_2V,
              1998,
              { GfxBoardInterface::PCI, GfxBoardInterface::AGP_1x },
              std::nullopt,
              { { 83'000, std::nullopt, 83'000 } } },
        },
        {
            GfxBoardID::SiS_6326,
            { "6326",
              ManufacturerID::SIS,
              GPUID::SiS_6326,
              1997,
              { GfxBoardInterface::AGP_2x, GfxBoardInterface::PCI },
              std::nullopt,
              { { 90'000, std::nullopt, 90'000 } } },
        },
        {
            GfxBoardID::SiS_300,
            { "300",
              ManufacturerID::SIS,
              GPUID::SiS_300,
              1999,
              { GfxBoardInterface::AGP_4x },
              std::nullopt,
              { { 125'000, std::nullopt, 125'000 } } },
        },
        {
            GfxBoardID::SiS_305,
            { "305",
              ManufacturerID::SIS,
              GPUID::SiS_305,
              2000,
              { GfxBoardInterface::AGP_2x },
              std::nullopt,
              { { 125'000, std::nullopt, 125'000 } } },
        },
        {
            GfxBoardID::SiS_315,
            { "Mirage 315",
              ManufacturerID::SIS,
              GPUID::SiS_Mirage_315,
              2000,
              { GfxBoardInterface::AGP_4x, GfxBoardInterface::PCI },
              std::nullopt,
              { { 332'000, std::nullopt, 664'000 } } },
        },
        {
            GfxBoardID::XGI_Volari_V3XT,
            { "Volari V3XT",
              ManufacturerID::XGI,
              GPUID::XGI_XG42,
              2003,
              { GfxBoardInterface::AGP_8x },
              std::nullopt,
              { { 500'000, 62'500, 1'000'000 } } },
        },
        {
            GfxBoardID::XGI_Volari_V5,
            { "Volari V5",
              ManufacturerID::XGI,
              GPUID::XGI_XG41,
              2003,
              { GfxBoardInterface::AGP_8x },
              std::nullopt,
              { { 625'000, 162'500, 1'300'000 } } },
        },
        {
            GfxBoardID::XGI_Volari_V8,
            { "Volari V8",
              ManufacturerID::XGI,
              GPUID::XGI_XG40,
              2003,
              { GfxBoardInterface::AGP_8x },
              std::nullopt,
              { { 1'250'000, 156'250, 2'500'000 } } },
        },
        {
            GfxBoardID::XGI_Volari_V8_Ultra,
            { "Volari V8 Ultra",
              ManufacturerID::XGI,
              GPUID::XGI_XG40,
              2003,
              { GfxBoardInterface::AGP_8x },
              std::nullopt,
              { { 1'400'000, 175'000, 2'800'000 } } },
        },
        {
            GfxBoardID::ATI_Rage_128_Pro,
            { "Rage 128 Pro",
              ManufacturerID::ATI,
              GPUID::ATI_Rage_128_Pro,
              1999,
              { GfxBoardInterface::AGP_4x },
              std::nullopt,
              { { 260'000, 8'000, 260'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_7500,
            { "Radeon 7500",
              ManufacturerID::ATI,
              GPUID::ATI_RV200_500,
              2001,
              { GfxBoardInterface::AGP_4x },
              28,
              { { 580'000, 72'500, 1'740'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9550_Mobile,
            { "Mobility Radeon 9550",
              ManufacturerID::ATI,
              GPUID::ATI_M12,
              2004,
              { GfxBoardInterface::PCIe_x16 },
              std::nullopt,
              { { 1'000'000, 125'000, 1'000'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9200,
            { "Radeon 9200",
              ManufacturerID::ATI,
              GPUID::ATI_RV280,
              2003,
              { GfxBoardInterface::AGP_8x },
              28,
              { { 1'000'000, 62'500, 1'000'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9250,
            { "Radeon 9250",
              ManufacturerID::ATI,
              GPUID::ATI_RV280,
              2004,
              { GfxBoardInterface::AGP_8x },
              28,
              { { 960'000, 60'000, 960'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9600_Pro,
            { "Radeon 9600 Pro",
              ManufacturerID::ATI,
              GPUID::ATI_RV350,
              2003,
              { GfxBoardInterface::AGP_8x },
              18,
              { { 1'600'000, 200'000, 1'600'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9600_Mobile,
            { "Mobility Radeon 9600",
              ManufacturerID::ATI,
              GPUID::ATI_M10,
              2004,
              { GfxBoardInterface::AGP_8x },
              std::nullopt,
              { { 1'200'000, 150'000, 1'200'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9600_XT,
            { "Radeon 9600 XT",
              ManufacturerID::ATI,
              GPUID::ATI_RV360,
              2003,
              { GfxBoardInterface::AGP_8x },
              22,
              { { 2'000'000, 250'000, 2'000'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9700_Mobile,
            { "Mobility Radeon 9700",
              ManufacturerID::ATI,
              GPUID::ATI_M11,
              2004,
              { GfxBoardInterface::AGP_8x },
              std::nullopt,
              { { 1'800'000, 225'000, 1'800'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9800,
            { "Radeon 9800",
              ManufacturerID::ATI,
              GPUID::ATI_R350,
              2003,
              { GfxBoardInterface::AGP_8x },
              37,
              { { 2'600'000, 325'000, 2'600'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_X600_XT,
            { "Radeon X600 XT",
              ManufacturerID::ATI,
              GPUID::ATI_RV380_XT,
              2004,
              { GfxBoardInterface::PCIe_x16 },
              25,
              { { 2'000'000, 250'000, 2'000'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_X1050,
            { "Radeon X1050",
              ManufacturerID::ATI,
              GPUID::ATI_RV360,
              2007,
              { GfxBoardInterface::AGP_8x },
              24,
              { { 1'000'000, 125'000, 1'000'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_X1950_Pro,
            { "Radeon X1950 Pro",
              ManufacturerID::ATI,
              GPUID::ATI_RV570,
              2006,
              { GfxBoardInterface::AGP_8x, GfxBoardInterface::PCIe_x16 },
              66,
              { { 6'900'000, 1'150'000, 6'900'000 } } },
        },
        {
            GfxBoardID::AMD_Radeon_HD_3850,
            { "Radeon HD 3850",
              ManufacturerID::AMD,
              GPUID::ATI_RV670_Pro,
              2008,
              { GfxBoardInterface::AGP_8x, GfxBoardInterface::PCIe_x16 },
              75,
              { { 10'690'000, std::nullopt, 10'690'000, 427'500'000, 85'500'0000 } } },
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
    std::string to_string(const DataInfo::GfxBoardInterface &interface)
    {
        switch (interface)
        {
            case DataInfo::GfxBoardInterface::PCI:
                return "PCI";
            case DataInfo::GfxBoardInterface::AGP_1x:
                return "AGP 1x";
            case DataInfo::GfxBoardInterface::AGP_2x:
                return "AGP 2x";
            case DataInfo::GfxBoardInterface::AGP_4x:
                return "AGP 4x";
            case DataInfo::GfxBoardInterface::AGP_8x:
                return "AGP 8x";
            case DataInfo::GfxBoardInterface::PCIe_x16:
                return "PCIe x16";
            default:
                return "Unknown Interface";
        }
    }
}
