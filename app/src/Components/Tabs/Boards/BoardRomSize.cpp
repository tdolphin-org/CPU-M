//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "BoardRomSize.hpp"

namespace Components
{
    BoardRomSize::BoardRomSize(const unsigned char *romAddress, const unsigned long romSize)
      : mBoardRomSizeText(MUI::TextBuilder().tagShortHelp("ROM size of the board").tagContents("N/A").object())
      , mBoardRomSizeButton(romAddress, romSize)
      , mComponent(
            MUI::GroupBuilder().horizontal().tagFrame(MUI::Frame::Text).tagChild(mBoardRomSizeText).tagChild(mBoardRomSizeButton).object())
    {
    }

    void BoardRomSize::SetRomData(const unsigned char *romAddress, const unsigned long romSize)
    {
        mBoardRomSizeText.setContents(romSize ? ToString::FromBytesValue(romSize) : "N/A");
        mBoardRomSizeButton.SetRomData(romAddress, romSize);
    }
}