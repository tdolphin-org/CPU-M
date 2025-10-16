//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Buttons/BasicImageButton.hpp"
#include "DataInfo/MemorySpec.hpp"

#include <utility>

namespace Components
{
    class MemoryModuleSpecButton : public BasicImageButton
    {
        std::pair<MemoryType, ModuleForm> mMemoryTypeAndForm;

      public:
        MemoryModuleSpecButton(const std::pair<MemoryType, ModuleForm> &memoryTypeAndForm);
        virtual ~MemoryModuleSpecButton() = default;

      protected:
        unsigned long OnClick();
    };
}
