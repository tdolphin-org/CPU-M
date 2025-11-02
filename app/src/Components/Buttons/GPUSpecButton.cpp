//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GPUSpecButton.hpp"

#include "WindowManager.hpp"

namespace Components
{
    GPUSpecButton::GPUSpecButton(const DataInfo::GPUID gpuId)
      : BasicImageButton(MUI::ImageOrBackground::PopUp, "")
      , mGpuId(gpuId)
    {
    }

    unsigned long GPUSpecButton::OnClick()
    {
        WindowManager::instance().getGPUSpecWindow().Open(mGpuId);
        return 0;
    }
}
