//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "Content.hpp"

#include "TextResources/Labels.hpp"

namespace Components
{
    Content::Content()
      : mComponent({
            { Label::CPUTab, mCPUTab },
            { Label::MainboardTab, mMainboardTab },
            { Label::MemoryTab, mMemoryTab },
            { Label::GraphicsTab, mGraphicsTab },
            { Label::OperatingSystemTab, mOSTab },
            { Label::AboutTab, mAboutTab },
        })
    {
    }
}
