//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Base.hpp"
#include "Components/Buttons/BusInterfaceSpecButton.hpp"
#include "MUI/Group.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class BusInterfaceNames : public Root<MUI::Group>, public Base
    {
        MUI::Text mBusInterfaceNamesText;
        BusInterfaceSpecButton mBusInterfaceSpecButton;

        MUI::Group mComponent;

      public:
        BusInterfaceNames(const std::string &interfaces);
        virtual ~BusInterfaceNames() = default;

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
