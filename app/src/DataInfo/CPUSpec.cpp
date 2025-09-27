//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "CPUSpec.hpp"

// micro sign: \xB5
// use u instead

// sources:
// https://en.wikipedia.org/wiki/PowerPC_600
// https://web.archive.org/web/20051210132546/http://www.geek.com/procspec/apple/g4.htm
// https://datasheets.chipdb.org/IBM/PowerPC/750/PowerPC-750CX.pdf
// https://datasheets.chipdb.org/IBM/PowerPC/970/PowerPC-970MP.pdf
// https://www.nxp.com/docs/en/data-sheet/MPC5200BDS.pdf
// https://community.nxp.com/pwmxy87654/attachments/pwmxy87654/t-series/4648/1/T1042.pdf
// https://datasheet.octopart.com/PPC460EX-SUB800T-AMCC-datasheet-11553412.pdf
// https://www.mouser.com/datasheet/2/302/MPC7410ECS03AD-1154434.pdf
// https://www.nxp.com/docs/en/data-sheet/MPC7450RXQXPNS.pdf
// https://www.nxp.com/docs/en/data-sheet/MPC7455EC.pdf

namespace DataInfo
{
    const std::map<std::string, CPUSpec> cpuPPC2spec {
        { "Unknown", { "??", "Unknown", "", "??", "??", "??", "??" } },
        { "602", { "Motorola/IBM", "602", "", "3.3 V", "0.5 um", "February 1995", "~1.2 W" } },
        { "603", { "Motorola/IBM", "603", "", "3.3 V", "0.5 um", "1994", "~2.2-3.5 W" } },
        { "603E", { "Motorola/IBM", "603e", "", "2.5 V, 3.3 V", "0.35-0.5 um", "April 1996", "~6 W" } },
        { "603P", { "Motorola/IBM", "603p", "", "2.5 V", "0.35 um", "?", "~4-5 W" } },
        { "604", { "Motorola/IBM", "604", "", "3.3 V", "0.5 um", "April 1994", "~14-17 W" } },
        { "604E", { "Motorola/IBM", "604e", "", "2.5 V", "0.35 um", "1996", "~16-18 W" } },
        { "620", { "Motorola", "620", "", "3.3 V", "0.35-0.5 um", "1997", "~30 W" } },
        { "750CX", { "Motorola/IBM", "750CX", "Sidewinder", "1.8 V", "0.18 um", "2000", "~3.6-10 W" } }, // pegasos I/II
        { "7400", { "Motorola/IBM", "MPC7400", "Max", "1.8 V", "0.18 um", "1999/2000", "~10-13 W" } }, // apple G4
        { "7410", { "Motorola/Freescale", "MPC7410", "", "2 V", "0.18 um", "2001", "~6-14 W" } }, // apple G4
        { "7450", { "Motorola/Freescale", "MPC7450", "", "1.9 V", "0.18 um", "2001", "~22-39 W" } }, // apple G4
        { "7455", { "Motorola/Freescale", "MPC7455", "", "1.3 V", "0.18 um", "2002", "~11-22 W" } }, // apple G4
        { "7447", { "Motorola/Freescale", "MPC7447", "Apollo 7", "1.1-1.3 V", "130 nm", "2005", "~8-20 W" } }, // pegasos II
        { "7447A", { "Motorola/Freescale", "MPC7447A", "", "1.1-1.3 V", "130 nm", "2005", "~8-20 W" } }, // apple G4
        { "7448", { "Motorola/Freescale", "MPC7448", "", "1.0-1.3 V", "90 nm", "2005", "~15-21 W" } }, // apple G4
        { "970FX", { "IBM", "970FX", "", "1.2 V", "90 nm", "2005", "~50 W" } }, // apple G5
        { "970MP", { "IBM", "970MP", "Antares", "0.9-1.3 V", "90 nm", "2005", "~25-100 W" } }, // apple G5 dual core
        { "MPC5200B", { "Freescale", "MPC5200B", "", "1.8 V", "0.18 um", "2005", "~1-2 W" } }, // efika
        { "460ex", { "AMCC", "460ex", "", "1.0 V", "90 nm", "2007", "~4-5 W" } }, // sam460
        { "P3041", { "Freescale/NXP", "QorIQ P3041", "", "1.0 V", "45 nm", "2010", "~12 W" } }, // amigaone x5000
        { "P5020", { "Freescale/NXP", "QorIQ P5020", "", "1.0-1.1 V", "45 nm", "2011", "~13-16 W" } }, // amigaone x5000
        { "P5040", { "Freescale/NXP", "QorIQ P5040", "", "1.1-1.2 V", "45 nm", "2012", "~27-33 W" } }, // amigaone x5000
        { "T1022", { "Freescale/NXP", "T1022", "", "1.0-1.1 V", "28 nm", "2012", "~5-8 W" } }, // mirari
        { "T1042", { "Freescale/NXP", "T1042", "", "1.0-1.1 V", "28 nm", "2012", "~7-10 W" } }, // mirari
        { "T2080", { "NXP", "T2080", "", "1.0-1.1 V", "28 nm", "2015", "??" } }, // mirari
    };
}
