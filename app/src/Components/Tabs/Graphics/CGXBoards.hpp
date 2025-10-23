//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Buttons/GPUSpecButton.hpp"

#include "MUI/Group.hpp"

namespace Components
{
    class CGXBoards : public Root<MUI::Group>
    {
        std::vector<GPUSpecButton *> mGPUSpecButtons;

        MUI::Group mComponent;

      public:
        CGXBoards();
        ~CGXBoards();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
