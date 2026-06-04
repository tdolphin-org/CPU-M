//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "BoardAttributesWindow.hpp"

#include "AOS/PCIX/Library.hpp"
#include "Components/IDs.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Notifier/Notifier.hpp"
#include "Version.hpp"

namespace Components
{
    BoardAttributesWindow::BoardAttributesWindow()
      : mBusNumber(ValueText("Bus number where board is located"))
      , mBridgeName(ValueText("Bridge name where board is connected"))
      , mDeviceNumber(ValueText("Device number where board is located"))
      , mFunctionNumber(ValueText("Function number where board is located"))
      , mRomAddress(ValueText("ROM address of the board"))
      , mRomSize(ValueText("ROM size of the board"))
      , mMainAttributesGroup(MUI::GroupBuilder()
                                 .horizontal()
                                 .tagColumns(4)
                                 .tagChild(LabelText(MUIX_R "Bus Number:"))
                                 .tagChild(mBusNumber)
                                 .tagChild(LabelText(MUIX_R "Bridge Name:"))
                                 .tagChild(mBridgeName)
                                 .tagChild(LabelText(MUIX_R "Device Number:"))
                                 .tagChild(mDeviceNumber)
                                 .tagChild(LabelText(MUIX_R "Function Number:"))
                                 .tagChild(mFunctionNumber)
                                 .tagChild(LabelText(MUIX_R "ROM Address:"))
                                 .tagChild(mRomAddress)
                                 .tagChild(LabelText(MUIX_R "ROM Size:"))
                                 .tagChild(mRomSize)
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
                       .tagRootObject(MUI::GroupBuilder()
                                          .vertical()
                                          .tagChild(MUI::MakeObject::HVSpace())
                                          .tagChild(mMainAttributesGroup)
                                          .tagChild(mBaseAttributesGroup)
                                          .tagChild(MUI::MakeObject::HVSpace())
                                          .object())
                       .object())
    {
        // window "X" button => close window
        MUI::Notifier::from(mComponent).onCloseRequest(true).notifySelf().setOpen(false);
    }

    void BoardAttributesWindow::Open(const AOS::PCIX::BoardAttributes &attributes)
    {
        mBusNumber.setContents(std::to_string(attributes.busNumber));
        mBridgeName.setContents(attributes.bridgeName);
        mDeviceNumber.setContents(std::to_string(attributes.deviceNumber));
        mFunctionNumber.setContents(std::to_string(attributes.functionNumber));
        mRomAddress.setContents(ToString::FromDataPointer(attributes.romAddress));
        mRomSize.setContents(ToString::FromBytesValue(attributes.romSize));

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
