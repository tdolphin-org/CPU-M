//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Buttons/BasicImageButton.hpp"

namespace Components
{
    class BusInterfaceSpecButton : public BasicImageButton
    {
      public:
        BusInterfaceSpecButton();
        virtual ~BusInterfaceSpecButton() = default;

      protected:
        unsigned long OnClick();
    };
}
