//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Buttons/GPUSpecButton.hpp"
#include "Components/Tabs/TabBase.hpp"
#include "DataInfo/GPUSpec.hpp"
#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class GPUName : public Root<MUI::Group>, public TabBase
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
