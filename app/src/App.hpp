//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "AOS/Cybergraphics/CybergraphicsBaseScope.hpp"
#include "AOS/Graphics/GraphicsBaseScope.hpp"
#include "AOS/OpenURL/OpenURLBaseScope.hpp"
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

    AppCore();

  public:
    void Run();
};

/// @brief main Application (singleton) object
typedef class td::Singleton<AppCore> App;
