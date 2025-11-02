//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Tabs/Graphics/GPUName.hpp"

namespace Components
{
    class GraphicsBoards : public Root<MUI::Group>, public TabBase
    {
        std::vector<GPUName *> mGPUNameComponents;

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
