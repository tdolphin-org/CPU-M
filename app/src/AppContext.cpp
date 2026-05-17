//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "AppContext.hpp"

#include "App.hpp"

#ifdef TRACE
#include "amiga_std_light/iostream.hpp"
#endif

AppContextCore::AppContextCore()
{
#ifdef TRACE
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
}

AppContextCore::~AppContextCore()
{
#ifdef TRACE
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
}

OpenURLBaseScope &AppContextCore::getOpenURLBase() const
{
    return App::instance().openUrlBaseScope;
}

CybergraphicsBaseScope &AppContextCore::getCybergraphicsBase() const
{
    return App::instance().cybergraphicsBaseScope;
}

RexxsyslibBaseScope &AppContextCore::getRexxsyslibBase() const
{
    return App::instance().rexxsyslibBaseScope;
}

PCIXBaseScope &AppContextCore::getPCIXBase() const
{
    return App::instance().pcixBaseScope;
}

PCIIDSBaseScope &AppContextCore::getPCIIDSBase() const
{
    return App::instance().pciidsBaseScope;
}

IntuitionBaseScope &AppContextCore::getIntuitionBase() const
{
    return App::instance().intuitionBaseScope;
}
