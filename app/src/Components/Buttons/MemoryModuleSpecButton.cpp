//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "MemoryModuleSpecButton.hpp"

#include "WindowManager.hpp"

#include <iostream>

namespace Components
{
    MemoryModuleSpecButton::MemoryModuleSpecButton(const std::pair<MemoryType, ModuleForm> &memoryTypeAndForm)
      : BasicImageButton(MUI::ImageOrBackground::PopUp, "Show more info about this memory module", 50)
      , mMemoryTypeAndForm(memoryTypeAndForm)
    {
    }

    unsigned long MemoryModuleSpecButton::OnClick()
    {
        WindowManager::instance().getMemoryModuleSpecWindow().Open(mMemoryTypeAndForm);
        return 0;
    }
}
