//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

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
};

/// @brief main Window Manager (singleton) object
typedef class td::Singleton<WindowManagerCore> WindowManager;
