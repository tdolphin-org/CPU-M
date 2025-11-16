//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GPUSpec.hpp"

// data info resources:
// https://vgamuseum.info
// https://www.techpowerup.com/gpu-specs/
// wikipedia
// product datasheets from manufacturers

namespace DataInfo
{
    const std::map<GPUID, GPUSpec> gpu2spec {
        { GPUID::_3dfx_Avenger, { ManufacturerID::_3DFX, "Avenger", 1999, std::nullopt, "250nm", { std::nullopt, 1, 0, 2, 1 }, 15 } },
        { GPUID::_3dfx_VSA_100, { ManufacturerID::_3DFX, "VSA-100", 2000, std::nullopt, "250nm", { std::nullopt, 2, 0, 2, 2 }, 60 } },
        { GPUID::_3DLabs_Permedia_2,
          { ManufacturerID::_3DLABS,
            "Permedia 2",
            1997,
            std::nullopt,
            "350n",
            { std::nullopt, std::nullopt, std::nullopt, 1, 1 },
            std::nullopt } },
        { GPUID::_3DLabs_Permedia_2V,
          { ManufacturerID::_3DLABS,
            "Permedia 2V",
            1998,
            std::nullopt,
            "N/A",
            { std::nullopt, std::nullopt, std::nullopt, 1, 1 },
            std::nullopt } },
        { GPUID::SiS_6326,
          { ManufacturerID::SIS, "6326", 1997, ArchitectureID::SiS_1st_Gen, "350nm", { std::nullopt, 1, 0, 1, 1 }, std::nullopt } },
        { GPUID::SiS_300,
          { ManufacturerID::SIS, "300", 1999, ArchitectureID::SiS_2nd_Gen, "250nm", { std::nullopt, 1, 0, 1, 1 }, std::nullopt } },
        { GPUID::SiS_305,
          { ManufacturerID::SIS, "305", 2000, ArchitectureID::SiS_2nd_Gen, "150nm", { std::nullopt, 1, 0, 1, 1 }, std::nullopt } },
        { GPUID::SiS_Mirage_315,
          { ManufacturerID::SIS, "Mirage 315", 2000, ArchitectureID::SiS_2nd_Gen, "150nm", { std::nullopt, 2, 0, 4, 2 }, std::nullopt } },
        { GPUID::XGI_XG40,
          { ManufacturerID::XGI, "XG40", 2003, ArchitectureID::XG4, "130nm", { std::nullopt, 4, 2, 8, 4 }, std::nullopt } },
        { GPUID::XGI_XG41,
          { ManufacturerID::XGI, "XG41", 2003, ArchitectureID::XG4, "130nm", { std::nullopt, 2, 2, 4, 2 }, std::nullopt } },
        { GPUID::XGI_XG42,
          { ManufacturerID::XGI, "XG42", 2003, ArchitectureID::XG4, "130nm", { std::nullopt, 2, 1, 4, 2 }, std::nullopt } },
        { GPUID::ATI_Rage_128_Pro,
          { ManufacturerID::ATI, "Rage 128 Pro", 1999, ArchitectureID::ATI_RAGE_4, "250nm", { std::nullopt, 2, 0, 2, 2 }, std::nullopt } },
        { GPUID::ATI_RV200, { ManufacturerID::ATI, "RV200", 2001, ArchitectureID::ATI_RAGE_7, "150nm", { std::nullopt, 2, 1, 6, 2 }, 23 } },
        { GPUID::ATI_RV280, { ManufacturerID::ATI, "RV280", 2003, ArchitectureID::ATI_RAGE_7, "150nm", { std::nullopt, 4, 1, 4, 4 }, 28 } },
        { GPUID::ATI_R350, { ManufacturerID::ATI, "RV350", 2003, ArchitectureID::ATI_R300, "150nm", { std::nullopt, 8, 4, 8, 8 }, 94 } },
        { GPUID::ATI_RV350, { ManufacturerID::ATI, "RV350", 2003, ArchitectureID::ATI_R300, "130nm", { std::nullopt, 4, 2, 4, 4 }, 24 } },
        { GPUID::ATI_RV360, { ManufacturerID::ATI, "RV360", 2003, ArchitectureID::ATI_R300, "130nm", { std::nullopt, 4, 2, 4, 4 }, 24 } },
        { GPUID::ATI_RV380,
          { ManufacturerID::ATI, "RV380", 2004, ArchitectureID::ATI_R300, "130nm", { std::nullopt, 4, 2, 4, 4 }, 46 } },
        { GPUID::ATI_RV570,
          { ManufacturerID::ATI, "RV570", 2006, ArchitectureID::ATI_Ultra_Threaded_SE, "80nm", { std::nullopt, 36, 8, 12, 12 }, 130 } },
        { GPUID::ATI_RV620,
          { ManufacturerID::ATI,
            "RV620",
            2007,
            ArchitectureID::ATI_TeraScale,
            "55nm",
            { 40, std::nullopt, std::nullopt, 4, 4, 2 },
            50 } },
        { GPUID::ATI_RV670,
          { ManufacturerID::ATI,
            "RV670",
            2008,
            ArchitectureID::ATI_TeraScale,
            "55nm",
            { 320, std::nullopt, std::nullopt, 16, 16, 4 },
            145 } },
        { GPUID::ATI_RV730,
          { ManufacturerID::ATI,
            "RV730",
            2008,
            ArchitectureID::ATI_TeraScale,
            "55nm",
            { 320, std::nullopt, std::nullopt, 32, 8, 4 },
            118 } },
        { GPUID::ATI_M10,
          { ManufacturerID::ATI, "M10", 2003, ArchitectureID::ATI_R300, "130nm", { std::nullopt, 4, 2, 4, 4 }, std::nullopt } },
        { GPUID::ATI_M11,
          { ManufacturerID::ATI, "M11", 2003, ArchitectureID::ATI_R300, "130nm", { std::nullopt, 4, 2, 4, 4 }, std::nullopt } },
        { GPUID::ATI_M12,
          { ManufacturerID::ATI, "M12", 2004, ArchitectureID::ATI_R300, "130nm", { std::nullopt, 4, 2, 4, 4 }, std::nullopt } },
    };
}
