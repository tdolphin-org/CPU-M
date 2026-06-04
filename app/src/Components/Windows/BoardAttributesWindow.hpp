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
    class BoardAttributesWindow : public Root<MUI::Window>, public Base
    {
        MUI::Group mMainAttributesGroup;
        MUI::Group mBaseAttributesGroup;

        MUI::Window mComponent;

      public:
        BoardAttributesWindow();

        void Open();
        void Close();

      protected:
        MUI::Window &muiRoot() const
        {
            return const_cast<MUI::Window &>(mComponent);
        }
    };
}
