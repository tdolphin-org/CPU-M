//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "CPUSpec.hpp"

// micro sign: \xB5
// use u instead

namespace DataInfo
{
    const std::map<std::string, CPUSpec> cpuPPC2spec {
        { "Unknown", { "??", "Unknown", "??", "??", "??", "??" } },
        { "602", { "Motorola/IBM", "602", "3.3 V", "0.5 um", "February 1995", "~1.2 W" } },
        { "603", { "Motorola/IBM", "603", "3.3 V", "0.5 um", "1994", "~2.2-3.5 W" } },
        { "603E", { "Motorola/IBM", "603e", "2.5 V, 3.3 V", "0.35-0.5 um", "April 1996", "~6 W" } },
        { "603P", { "Motorola/IBM", "603p", "2.5 V", "0.35 um", "?", "~4-5 W" } },
        { "604", { "Motorola/IBM", "604", " 3.3 V", "0.5 um", "April 1994", "~14-17 W" } },
        { "604E", { "Motorola/IBM", "604e", " 2.5 V", "0.35 um", "1996", "~16-18 W" } },
        { "620", { "Motorola", "620", "3.3 V", "0.35-0.5 um", "1997", "~30 W" } },
        { "7448", { "Freescale", "7448", "1.0-1.3 V", "90 nm", "2005", "~15-21 W" } },
        { "970FX", { "IBM", "970FX", "1.2 V", "90 nm", "2005", "~50 W" } },
    };
}
