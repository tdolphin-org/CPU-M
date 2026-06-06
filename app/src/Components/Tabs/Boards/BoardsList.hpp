//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#pragma once

#include "AOS/PCIX/Library.hpp"
#include "Components/Core/Root.hpp"
#include "Components/MCC/ActionList.hpp"
#include "DataInfo/BoardInfo.hpp"

#include "MUI/Group.hpp"
#include "MUI/List.hpp"

namespace Components
{
    class BoardsList : public Root<MUI::List>, public MCC::ActionListDispatcher
    {
        std::vector<std::pair<AOS::PCIX::Board, BoardInfo>> mBoards;

        MUI::List mComponent;

      public:
        BoardsList(const std::vector<AOS::PCIX::Board> &boards);

      protected:
        // implements pure virtual MCC::ActionListDispatcher
        unsigned long OnActiveEntry() override;
        unsigned long OnDoubleClickEntry() override;

      protected:
        MUI::List &muiRoot() const
        {
            return const_cast<MUI::List &>(mComponent);
        }

      private:
        void OpenBoardAttributes(const long activeEntry);
    };
}