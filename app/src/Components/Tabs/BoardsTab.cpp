//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "BoardsTab.hpp"

#include "AOS/PCIX/Library.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    BoardsTab::BoardsTab()
      : mBoardsList(AOS::PCIX::Library::GetBoards())
      , mComponent(
            MUI::GroupBuilder()
                .vertical()
                .tagChild(mBoardsList)
                .tagChild(
                    MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents(MUIX_L "Double click on list item to view board attributes.").object())
                .object())
    {
    }

    BoardsTab::~BoardsTab() { }
}
