//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "BoardAttributesWindow.hpp"

#include "Components/IDs.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Notifier/Notifier.hpp"
#include "Version.hpp"

namespace Components
{
    BoardAttributesWindow::BoardAttributesWindow()
      : mMainAttributesGroup(MUI::GroupBuilder()
                                 .horizontal()
                                 .tagColumns(4)
                                 .tagChild(LabelText(MUIX_R "Bus Number:"))
                                 .tagChild(ValueText("Bus number where board is located"))
                                 .tagChild(LabelText(MUIX_R "Bridge Name:"))
                                 .tagChild(ValueText("Bridge name where board is connected"))
                                 .object())
      , mBaseAttributesGroup(MUI::GroupBuilder().vertical().object())
      , mComponent(MUI::WindowBuilder()
                       .tagTitle("Board Attributes")
                       .tagScreenTitle(SCREEN_TITLE)
                       .tagID(WindowID::BoardAttributesWindow)
                       .tagWidth(400)
                       .tagHeight(500)
                       .tagAltWidth(600)
                       .tagAltHeight(600)
                       .tagRootObject(MUI::GroupBuilder().vertical().tagChild(mMainAttributesGroup).tagChild(mBaseAttributesGroup).object())
                       .object())
    {
        // window "X" button => close window
        MUI::Notifier::from(mComponent).onCloseRequest(true).notifySelf().setOpen(false);
    }

    void BoardAttributesWindow::Open()
    {
        if (mComponent.isOpen())
        {
            mComponent.ToFront();
            return;
        }

        mComponent.Open();
    }

    void BoardAttributesWindow::Close()
    {
        mComponent.Close();
    }
}
