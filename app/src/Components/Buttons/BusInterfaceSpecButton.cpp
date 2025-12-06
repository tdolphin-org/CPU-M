//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "BusInterfaceSpecButton.hpp"

#include "WindowManager.hpp"

namespace Components
{
    BusInterfaceSpecButton::BusInterfaceSpecButton()
      : BasicImageButton(MUI::ImageOrBackground::PopUp, "")
    {
    }

    unsigned long BusInterfaceSpecButton::OnClick()
    {
        WindowManager::instance().getBusInterfacesSpecWindow().Open();
        return 0;
    }
}
