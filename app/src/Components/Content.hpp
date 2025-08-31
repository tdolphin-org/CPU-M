//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Tabs/TabsContainer.hpp"
#include "Tabs/AboutTab.hpp"
#include "Tabs/CPUTab.hpp"

namespace Components
{
    class Content : public Root<MUI::Group>
    {
        CPUTab mCPUTab;
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
