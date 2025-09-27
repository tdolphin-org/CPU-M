//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "AOS/Cybergraphics/CybergraphicsBaseScope.hpp"
#include "AOS/OpenURL/OpenURLBaseScope.hpp"
#include "AOS/Rexxsyslib/RexxsyslibBaseScope.hpp"
#include "AOS/PCIX/PCIXBaseScope.hpp"
#include "Core/Singleton.hpp"

#include <set>

class AppContextCore
{
    friend class td::Singleton<AppContextCore>;

    AppContextCore();
    ~AppContextCore();

  public:
    OpenURLBaseScope &getOpenURLBase() const;
    CybergraphicsBaseScope &getCybergraphicsBase() const;
    RexxsyslibBaseScope &getRexxsyslibBase() const;
    PCIXBaseScope &getPCIXBase() const;
};

/// @brief main AppContext (singleton) object
typedef class td::Singleton<AppContextCore> AppContext;
