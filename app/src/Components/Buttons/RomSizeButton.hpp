//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#pragma once

#include "Components/Buttons/BasicImageButton.hpp"

namespace Components
{
    // save the ROM to file button
    class RomSizeButton : public BasicImageButton
    {
        unsigned char *mRomAddress;
        unsigned long mRomSize;

      public:
        RomSizeButton(const unsigned char *romAddress, const unsigned long romSize);
        virtual ~RomSizeButton() = default;

        void SetRomData(const unsigned char *romAddress, const unsigned long romSize);

      protected:
        unsigned long OnClick();
    };
}
