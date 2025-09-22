//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "AppContext.hpp"

#include "App.hpp"

#ifdef TRACE
#include <iostream.hpp>
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
