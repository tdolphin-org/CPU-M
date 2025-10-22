//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Buttons/BasicButton.hpp"
#include "DataInfo/GPUSpec.hpp"

namespace Components
{
    class GPUSpecButton : public BasicButton
    {
        std::vector<DataInfo::GPUID> mChips;

      public:
        GPUSpecButton(const std::vector<DataInfo::GPUID> &chips);
        virtual ~GPUSpecButton() = default;

      protected:
        unsigned long OnClick();
    };
}
