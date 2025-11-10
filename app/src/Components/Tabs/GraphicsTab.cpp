//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GraphicsTab.hpp"

namespace Components
{
    GraphicsTab::GraphicsTab()
      : mGfxSystemText(ValueText("Graphic OS"))
      , mGraphicsBoards()
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Graphic System")
                                     .tagColumns(2)
                                     .tagChild(LabelText(MUIX_R "Name:"))
                                     .tagChild(mGfxSystemText)
                                     .object())
                       .tagChild(mGraphicsBoards)
                       .object())
    {
        mGfxSystemText.setContents("CyberGraphX");
    }

    GraphicsTab::~GraphicsTab() { }
}
