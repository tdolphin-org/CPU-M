//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "AOS/Cybergraphics/CybergraphicsBaseScope.hpp"
#include "AOS/Graphics/GraphicsBaseScope.hpp"
#include "AOS/Intuition/IntuitionBaseScope.hpp"
#include "AOS/OpenURL/OpenURLBaseScope.hpp"
#include "AOS/PCIIDS/PCIIDSBaseScope.hpp"
#include "AOS/PCIX/PCIXBaseScope.hpp"
#include "AOS/Rexxsyslib/RexxsyslibBaseScope.hpp"
#include "Core/Singleton.hpp"
#include "MUI/Core/MuiMasterBaseScope.hpp"

class AppContextCore;

class AppCore
{
    friend class td::Singleton<AppCore>;
    friend class AppContextCore;

    // open libraries, close on destructor
    MuiMasterBaseScope muiBaseScope;
    OpenURLBaseScope openUrlBaseScope;
    CybergraphicsBaseScope cybergraphicsBaseScope;
    GraphicsBaseScope graphicsBaseScope;
    RexxsyslibBaseScope rexxsyslibBaseScope;
    PCIXBaseScope pcixBaseScope;
    PCIIDSBaseScope pciidsBaseScope;
    IntuitionBaseScope intuitionBaseScope;

    AppCore();

  public:
    void Run();
};

/// @brief main Application (singleton) object
typedef class td::Singleton<AppCore> App;
