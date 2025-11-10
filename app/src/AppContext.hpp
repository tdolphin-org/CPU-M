//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "AOS/Cybergraphics/CybergraphicsBaseScope.hpp"
#include "AOS/Intuition/IntuitionBaseScope.hpp"
#include "AOS/OpenURL/OpenURLBaseScope.hpp"
#include "AOS/PCIIDS/PCIIDSBaseScope.hpp"
#include "AOS/PCIX/PCIXBaseScope.hpp"
#include "AOS/Rexxsyslib/RexxsyslibBaseScope.hpp"
#include "Core/Singleton.hpp"

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
    PCIIDSBaseScope &getPCIIDSBase() const;
    IntuitionBaseScope &getIntuitionBase() const;
};

/// @brief main AppContext (singleton) object
typedef class td::Singleton<AppContextCore> AppContext;
