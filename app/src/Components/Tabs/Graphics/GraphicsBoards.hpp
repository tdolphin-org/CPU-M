//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Buttons/GPUSpecButton.hpp"
#include "Components/Tabs/TabBase.hpp"

#include "MUI/Group.hpp"

namespace Components
{
    class GraphicsBoards : public Root<MUI::Group>, public TabBase
    {
        std::vector<GPUSpecButton *> mGPUSpecButtons;

        MUI::Group mComponent;

      public:
        GraphicsBoards();
        ~GraphicsBoards();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
