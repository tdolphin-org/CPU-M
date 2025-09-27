//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "Boards/BoardsList.hpp"
#include "TabBase.hpp"

#include "MUI/Group.hpp"

namespace Components
{
    class BoardsTab : public Root<MUI::Group>, public TabBase
    {
        BoardsList mBoardsList;

        MUI::Group mComponent;

      public:
        BoardsTab();
        ~BoardsTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
