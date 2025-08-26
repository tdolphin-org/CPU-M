//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "WindowManager.hpp"

#ifdef TRACE_MANAGERS
#include <iostream>
#endif

WindowManagerCore::WindowManagerCore()
  : mAllWindows({})
{
#ifdef TRACE_MANAGERS
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
}

WindowManagerCore::~WindowManagerCore()
{
#ifdef TRACE_MANAGERS
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
}

const std::vector<MUI::Window> &WindowManagerCore::getAllWindows() const
{
#ifdef TRACE_MANAGERS
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

    return mAllWindows;
}
