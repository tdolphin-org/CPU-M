//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "RomSizeButton.hpp"

namespace Components
{
    RomSizeButton::RomSizeButton(const unsigned char *romAddress, const unsigned long romSize)
      : BasicImageButton(MUI::ImageOrBackground::PopFile, "Save ROM to file")
      , mRomAddress(const_cast<unsigned char *>(romAddress))
      , mRomSize(romSize)
    {
    }

    void RomSizeButton::SetRomData(const unsigned char *romAddress, const unsigned long romSize)
    {
        mRomAddress = const_cast<unsigned char *>(romAddress);
        mRomSize = romSize;
        if (mRomSize)
            this->Enable();
        else
            this->Disable();
    }

    unsigned long RomSizeButton::OnClick()
    {
        if (!mRomAddress || !mRomSize)
            return 0;

        // TODO Implement the functionality for the ROM size button click event
        return 0;
    }
}
