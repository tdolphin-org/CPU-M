//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Boards/BoardsList.hpp"
#include "Components/Base.hpp"
#include "Components/Core/Root.hpp"

#include "MUI/Group.hpp"

namespace Components
{
    class BoardsTab : public Root<MUI::Group>, public Base
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
