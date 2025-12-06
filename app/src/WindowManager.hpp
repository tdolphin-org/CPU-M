//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Windows/BusInterfacesSpecWindow.hpp"
#include "Components/Windows/GPUSpecWindow.hpp"
#include "Components/Windows/MemoryModuleSpecWindow.hpp"
#include "Core/Singleton.hpp"
#include "MUI/Window.hpp"

#include <vector>

/// @brief holds windows (components)
class WindowManagerCore
{
    friend class td::Singleton<WindowManagerCore>;

    Components::GPUSpecWindow mGPUSpecWindow;
    Components::MemoryModuleSpecWindow mMemoryModuleSpecWindow;
    Components::BusInterfacesSpecWindow mBusInterfacesSpecWindow;

    std::vector<MUI::Window> mAllWindows;

    WindowManagerCore();
    ~WindowManagerCore();

  public:
    const std::vector<MUI::Window> &getAllWindows() const;

    Components::GPUSpecWindow &getGPUSpecWindow()
    {
        return mGPUSpecWindow;
    }

    Components::MemoryModuleSpecWindow &getMemoryModuleSpecWindow()
    {
        return mMemoryModuleSpecWindow;
    }

    Components::BusInterfacesSpecWindow &getBusInterfacesSpecWindow()
    {
        return mBusInterfacesSpecWindow;
    }
};

/// @brief main Window Manager (singleton) object
typedef class td::Singleton<WindowManagerCore> WindowManager;
