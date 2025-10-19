//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "TabBase.hpp"

#include "MUI/Group.hpp"

namespace Components
{
    class GraphicsTab : public Root<MUI::Group>, public TabBase
    {
        MUI::Text mGfxSystemText;
        MUI::Group mMountedMonitors;
        MUI::Group mGraphicsCards;

        MUI::Group mComponent;

      public:
        GraphicsTab();
        ~GraphicsTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
