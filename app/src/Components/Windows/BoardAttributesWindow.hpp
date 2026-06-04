//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "Components/Core/Root.hpp"

#include "Components/Base.hpp"
#include "MUI/Group.hpp"
#include "MUI/Window.hpp"

// forward declarations
namespace AOS::PCIX
{
    struct BoardAttributes;
}

namespace Components
{
    class BoardAttributesWindow : public Root<MUI::Window>, public Base
    {
        MUI::Text mBusNumber;
        MUI::Text mBridgeName;
        MUI::Text mDeviceNumber;
        MUI::Text mFunctionNumber;
        MUI::Text mRomAddress;
        MUI::Text mRomSize;

        MUI::Group mMainAttributesGroup;
        MUI::Group mBaseAttributesGroup;

        MUI::Window mComponent;

      public:
        BoardAttributesWindow();

        void Open(const AOS::PCIX::BoardAttributes &attributes);
        void Close();

        bool isOpen() const
        {
            return mComponent.isOpen();
        }

      protected:
        MUI::Window &muiRoot() const
        {
            return const_cast<MUI::Window &>(mComponent);
        }
    };
}
