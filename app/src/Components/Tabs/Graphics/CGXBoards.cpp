//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "CGXBoards.hpp"
#include "AppContext.hpp"

#include "AOS/Cybergraphics/Library.hpp"
#include "DataInfo/GfxBoardSpec.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    CGXBoards::CGXBoards()
      : mComponent(MUI::GroupBuilder()
                       .tagFrame(MUI::Frame::Group)
                       .tagBackground(MUI::ImageOrBackground::WindowBack)
                       .tagFrameTitle("Cybergraphics Board(s)")
                       .vertical()
                       .object())
    {
    }

    CGXBoards::~CGXBoards()
    {
        for (const auto *pButton : mGPUSpecButtons)
            delete pButton;
    }
}
