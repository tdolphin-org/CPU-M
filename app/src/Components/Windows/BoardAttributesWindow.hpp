//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "Components/Core/Root.hpp"

#include "Components/Base.hpp"
#include "DataInfo/BoardInfo.hpp"
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
        MUI::Text mVendor;
        MUI::Text mDevice;
        MUI::Text mClass;

        MUI::Text mBusNumber;
        MUI::Text mBridgeName;
        MUI::Text mDeviceNumber;
        MUI::Text mFunctionNumber;
        MUI::Text mRomAddress;
        MUI::Text mRomSize;
        MUI::Text mBaseAddress0;
        MUI::Text mBaseSize0;
        MUI::Text mBaseAddress1;
        MUI::Text mBaseSize1;
        MUI::Text mBaseAddress2;
        MUI::Text mBaseSize2;
        MUI::Text mBaseAddress3;
        MUI::Text mBaseSize3;
        MUI::Text mBaseAddress4;
        MUI::Text mBaseSize4;
        MUI::Text mBaseAddress5;
        MUI::Text mBaseSize5;

        MUI::Group mHeaderGroup;
        MUI::Group mMainAttributesGroup;
        MUI::Group mBaseAttributesGroup;

        MUI::Window mComponent;

      public:
        BoardAttributesWindow();

        void Open(const BoardInfo &boardInfo, const AOS::PCIX::BoardAttributes &attributes);
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
