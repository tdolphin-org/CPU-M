//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "Components/Core/Root.hpp"

#include "Components/Base.hpp"
#include "MUI/Group.hpp"
#include "MUI/Window.hpp"

namespace Components
{
    class BusInterfacesSpecWindow : public Root<MUI::Window>, public Base
    {
        MUI::Group mPciInterfacesGroup;
        MUI::Group mAgpInterfacesGroup;
        MUI::Group mPcieInterfacesGroup;
        MUI::Group mBusInterfacesGroup;

        MUI::Window mComponent;

      public:
        BusInterfacesSpecWindow();

        void Open();
        void Close();

      protected:
        MUI::Window &muiRoot() const
        {
            return const_cast<MUI::Window &>(mComponent);
        }
    };
}
