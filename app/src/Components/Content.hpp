//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Tabs/TabsContainer.hpp"
#include "Tabs/AboutTab.hpp"

namespace Components
{
    class Content : public Root<MUI::Group>
    {
        AboutTab mAboutTab;

        TabsContainer mComponent;

      public:
        Content();

      protected:
        MUI::Group &muiRoot() const
        {
            return mComponent;
        }
    };
}
