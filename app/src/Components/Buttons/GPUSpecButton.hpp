//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Buttons/BasicImageButton.hpp"
#include "DataInfo/GPUSpec.hpp"

namespace Components
{
    class GPUSpecButton : public BasicImageButton
    {
        DataInfo::GPUID mGpuId;

      public:
        GPUSpecButton(const DataInfo::GPUID gpuId);
        virtual ~GPUSpecButton() = default;

      protected:
        unsigned long OnClick();
    };
}
