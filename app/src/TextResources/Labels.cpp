//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "Labels.hpp"

#include "ProgDefines.hpp"
#include "Version.hpp"

#include <libraries/mui.h>

namespace Label
{
    const char *CPUTab = "CPU";
    const char *MainboardTab = "Mainboard";
    const char *MemoryTab = "Memory";
    const char *GraphicsTab = "Graphics";
    const char *ExpansionsTab = "Expansions";
    const char *OperatingSystemTab = "OS";
    const char *BenchTab = "Bench";
    const char *AboutTab = "About";

    const char *AboutContent = MUIX_C MUIX_B APP_NAME "\n\n" MUIX_N "Version " APP_VERSION " " APP_DATE "\n\n" APP_DESCRIPTION
                                                      "\n\n" MUIX_B APP_TDOLPHIN_COPYRIGHTS MUIX_N "\n\nAuthor: " AUTHORS "\n";
}
