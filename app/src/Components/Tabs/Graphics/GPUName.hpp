//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Base.hpp"
#include "Components/Buttons/GPUSpecButton.hpp"
#include "DataInfo/GPUSpec.hpp"
#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class GPUName : public Root<MUI::Group>, public Base
    {
        MUI::Text mGpuNameText;
        GPUSpecButton mGPUSpecButton;

        MUI::Group mComponent;

      public:
        GPUName(const DataInfo::GPUID &gpuId);
        virtual ~GPUName() = default;

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
