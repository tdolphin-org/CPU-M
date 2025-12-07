//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "BoardsTab.hpp"

#include "AOS/PCIX/Library.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    BoardsTab::BoardsTab()
      : mBoardsList(AOS::PCIX::Library::GetBoards())
      , mComponent(MUI::GroupBuilder().vertical().tagChild(mBoardsList).object())
    {
    }

    BoardsTab::~BoardsTab() { }
}
