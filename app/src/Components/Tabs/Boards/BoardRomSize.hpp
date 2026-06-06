//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#pragma once

#include "Components/Base.hpp"
#include "Components/Buttons/RomSizeButton.hpp"
#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class BoardRomSize : public Root<MUI::Group>, public Base
    {
        MUI::Text mBoardRomSizeText;
        RomSizeButton mBoardRomSizeButton;

        MUI::Group mComponent;

      public:
        BoardRomSize(const unsigned char *romAddress, const unsigned long romSize);
        virtual ~BoardRomSize() = default;

        void SetRomData(const unsigned char *romAddress, const unsigned long romSize);

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
