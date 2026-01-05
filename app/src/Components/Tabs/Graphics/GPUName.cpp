//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "GPUName.hpp"

namespace Components
{
    GPUName::GPUName(const DataInfo::GPUID &gpuId)
      : mGpuNameText(MUI::TextBuilder().tagShortHelp("Graphics Processing Unit name").tagContents(std::to_string(gpuId)).object())
      , mGPUSpecButton(gpuId)
      , mComponent(MUI::GroupBuilder().horizontal().tagFrame(MUI::Frame::Text).tagChild(mGpuNameText).tagChild(mGPUSpecButton).object())
    {
        bool gpuSpecExists = DataInfo::gpu2spec.find(gpuId) != DataInfo::gpu2spec.end();
        if (gpuSpecExists)
        {
            mGPUSpecButton.Enable();
            mGPUSpecButton.muiRoot().setShortHelp("Click to view detailed specifications for this GPU");
        }
        else
        {
            mGPUSpecButton.Disable();
            mGPUSpecButton.muiRoot().setShortHelp("No detailed specifications available");
        }
    }
}
