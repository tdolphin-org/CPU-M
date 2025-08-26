//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Tabs/TabsContainer.hpp"

namespace Components
{
    class Content : public Root<MUI::Group>
    {
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
