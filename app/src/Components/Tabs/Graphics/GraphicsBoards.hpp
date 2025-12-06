//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "BusInterfaceNames.hpp"
#include "GPUName.hpp"

namespace Components
{
    class GraphicsBoards : public Root<MUI::Group>, public Base
    {
        std::vector<GPUName *> mGPUNameComponents;
        std::vector<BusInterfaceNames *> mBusInterfaceNamesComponents;

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
