//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "AOS/PCIX/Library.hpp"
#include "Components/Core/Root.hpp"

#include "MUI/Group.hpp"
#include "MUI/List.hpp"

namespace Components
{
    class BoardsList : public Root<MUI::List>
    {
        MUI::List mComponent;

      public:
        BoardsList(const std::vector<AOS::PCIX::Board> &boards);

      protected:
        MUI::List &muiRoot() const
        {
            return const_cast<MUI::List &>(mComponent);
        }
    };
}