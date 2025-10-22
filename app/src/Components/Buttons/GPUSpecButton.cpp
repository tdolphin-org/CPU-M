//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GPUSpecButton.hpp"

#include "WindowManager.hpp"

namespace Components
{
    GPUSpecButton::GPUSpecButton(const std::vector<DataInfo::GPUID> &chips)
      : BasicButton("?", "Show more info about this GPU(s)", 0)
      , mChips(chips)
    {
    }

    unsigned long GPUSpecButton::OnClick()
    {
        WindowManager::instance().getGPUSpecWindow().Open(mChips);
        return 0;
    }
}
