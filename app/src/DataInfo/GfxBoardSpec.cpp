//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GfxBoardSpec.hpp"

#include "Core/ToString.hpp"

// data info resources:
// ...

namespace DataInfo
{
    const std::map<GfxBoardID, GfxBoardSpec> gfxBoard2spec {
        {
            GfxBoardID::ATI_Rage_128_Pro,
            { "Rage 128 Pro",
              ManufacturerID::ATI,
              { GPUID::ATI_Rage_128_Pro },
              1999,
              { GfxBoardInterface::AGP_4x },
              std::nullopt,
              std::nullopt },
        },
        {
            GfxBoardID::ATI_Radeon_7500,
            { "Radeon 7500",
              ManufacturerID::ATI,
              { GPUID::ATI_RV200_500 },
              2001,
              { GfxBoardInterface::AGP_4x },
              28,
              { { 580'000, 72'500, 1'740'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9550_Mobile,
            { "ATI Mobility Radeon 9550",
              ManufacturerID::ATI,
              { GPUID::ATI_M12 },
              2004,
              { GfxBoardInterface::PCIe_x16 },
              std::nullopt,
              { { 1'000'000, 125'000, 1'000'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9200,
            { "Radeon 9200",
              ManufacturerID::ATI,
              { GPUID::ATI_RV280 },
              2003,
              { GfxBoardInterface::AGP_8x },
              28,
              { { 1'000'000, 62'500, 1'000'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9250,
            { "Radeon 9250",
              ManufacturerID::ATI,
              { GPUID::ATI_RV280 },
              2004,
              { GfxBoardInterface::AGP_8x },
              28,
              { { 960'000, 60'000, 960'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9600_Mobile,
            { "ATI Mobility Radeon 9600",
              ManufacturerID::ATI,
              { GPUID::ATI_M10 },
              2004,
              { GfxBoardInterface::AGP_8x },
              std::nullopt,
              { { 1'200'000, 150'000, 1'200'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9700_Mobile,
            { "ATI Mobility Radeon 9700",
              ManufacturerID::ATI,
              { GPUID::ATI_M11 },
              2004,
              { GfxBoardInterface::AGP_8x },
              std::nullopt,
              { { 1'800'000, 225'000, 1'800'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_9800,
            { "Radeon 9800",
              ManufacturerID::ATI,
              { GPUID::ATI_RV350 },
              2003,
              { GfxBoardInterface::AGP_8x },
              37,
              { { 2'600'000, 325'000, 2'600'000 } } },
        },
        {
            GfxBoardID::ATI_Radeon_X1950_Pro,
            { "Radeon X1950 Pro",
              ManufacturerID::ATI,
              { GPUID::ATI_RV570 },
              2006,
              { GfxBoardInterface::AGP_8x, GfxBoardInterface::PCIe_x16 },
              66,
              { { 6'900'000, 1'150'000, 6'900'000 } } },
        },
        {
            GfxBoardID::AMD_Radeon_HD_3850,
            { "Radeon HD 3850",
              ManufacturerID::AMD,
              { GPUID::ATI_RV670_Pro },
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

    std::string to_string(const DataInfo::ManufacturerID &manufacturer, const bool fullName)
    {
        switch (manufacturer)
        {
            case DataInfo::ManufacturerID::ATI:
                return std::string("ATI") + (fullName ? " (ATI Technologies Inc.)" : "");
            case DataInfo::ManufacturerID::AMD:
                return std::string("AMD") + (fullName ? " (Advanced Micro Devices)" : "");
            case DataInfo::ManufacturerID::NVIDIA:
                return std::string("NVIDIA") + (fullName ? " (NVIDIA Corporation)" : "");
            case DataInfo::ManufacturerID::INTEL:
                return std::string("Intel") + (fullName ? " (Intel Corporation)" : "");
            case DataInfo::ManufacturerID::SIS:
                return std::string("SiS") + (fullName ? " (Silicon Integrated Systems)" : "");
            case DataInfo::ManufacturerID::XGI:
                return std::string("XGI") + (fullName ? " (XGI Technology)" : "");
            case DataInfo::ManufacturerID::THREE_D_LABS:
                return std::string("3D Labs") + (fullName ? " (3D Labs, Inc.)" : "");
            default:
                return "Unknown Manufacturer";
        }
    }
}