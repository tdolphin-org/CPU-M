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
    const std::string &CPUTab = "CPU";
    const std::string &MainboardTab = "Mainboard";
    const std::string &MemoryTab = "Memory";
    const std::string &GraphicsTab = "Graphics";
    const std::string &BoardsTab = "Boards";
    const std::string &OperatingSystemTab = "OS";
    const std::string &BenchTab = "Bench";
    const std::string &AboutTab = "About";

    // menu items
    const std::string &MenuCPUM = "CPU-M";
    const std::string &MenuAbout = "About";
    const std::string &MenuQuit = "Quit";
    const std::string &MenuSettings = "Settings";
    const std::string &MenuMUISettings = "MUI...";

    const std::string &AboutContent
        = MUIX_C MUIX_N APP_DESCRIPTION "\n\n"
                                        "Version " APP_VERSION " " APP_DATE "\n" APP_TDOLPHIN_COPYRIGHTS "\nAuthor: " AUTHORS "\n";
}
