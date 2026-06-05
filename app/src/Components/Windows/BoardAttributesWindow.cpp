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
      : mVendor(ValueText("Vendor name"))
      , mDevice(ValueText("Device name"))
      , mClass(ValueText("Class name"))
      , mBusNumber(ValueText("Bus number where board is located"))
      , mBridgeName(ValueText("Bridge name where board is connected"))
      , mDeviceNumber(ValueText("Device number where board is located"))
      , mFunctionNumber(ValueText("Function number where board is located"))
      , mRomAddress(ValueText("ROM address of the board"))
      , mRomSize(ValueText("ROM size of the board"))
      , mBaseAddress0(ValueText("Base address 0 of the board (this is a virtual address is not guranteed to be equal the physical)"))
      , mBaseSize0(ValueText("Base size 0 of the board"))
      , mBaseAddress1(ValueText("Base address 1 of the board (this is a virtual address is not guranteed to be equal the physical)"))
      , mBaseSize1(ValueText("Base size 1 of the board"))
      , mBaseAddress2(ValueText("Base address 2 of the board (this is a virtual address is not guranteed to be equal the physical)"))
      , mBaseSize2(ValueText("Base size 2 of the board"))
      , mBaseAddress3(ValueText("Base address 3 of the board (this is a virtual address is not guranteed to be equal the physical)"))
      , mBaseSize3(ValueText("Base size 3 of the board"))
      , mBaseAddress4(ValueText("Base address 4 of the board (this is a virtual address is not guranteed to be equal the physical)"))
      , mBaseSize4(ValueText("Base size 4 of the board"))
      , mBaseAddress5(ValueText("Base address 5 of the board (this is a virtual address is not guranteed to be equal the physical)"))
      , mBaseSize5(ValueText("Base size 5 of the board"))
      , mHeaderGroup(MUI::GroupBuilder()
                         .horizontal()
                         .tagColumns(2)
                         .tagChild(LabelText(MUIX_R "Vendor:"))
                         .tagChild(mVendor)
                         .tagChild(LabelText(MUIX_R "Device:"))
                         .tagChild(mDevice)
                         .tagChild(LabelText(MUIX_R "Class:"))
                         .tagChild(mClass)
                         .object())
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
                                 .tagChild(MUI::MakeObject::HVSpace())
                                 .object())
      , mBaseAttributesGroup(MUI::GroupBuilder()
                                 .vertical()
                                 .tagColumns(4)
                                 .tagChild(LabelText(MUIX_R "Base Address 0:"))
                                 .tagChild(mBaseAddress0)
                                 .tagChild(LabelText(MUIX_R "Base Size 0:"))
                                 .tagChild(mBaseSize0)
                                 .tagChild(LabelText(MUIX_R "Base Address 1:"))
                                 .tagChild(mBaseAddress1)
                                 .tagChild(LabelText(MUIX_R "Base Size 1:"))
                                 .tagChild(mBaseSize1)
                                 .tagChild(LabelText(MUIX_R "Base Address 2:"))
                                 .tagChild(mBaseAddress2)
                                 .tagChild(LabelText(MUIX_R "Base Size 2:"))
                                 .tagChild(mBaseSize2)
                                 .tagChild(LabelText(MUIX_R "Base Address 3:"))
                                 .tagChild(mBaseAddress3)
                                 .tagChild(LabelText(MUIX_R "Base Size 3:"))
                                 .tagChild(mBaseSize3)
                                 .tagChild(LabelText(MUIX_R "Base Address 4:"))
                                 .tagChild(mBaseAddress4)
                                 .tagChild(LabelText(MUIX_R "Base Size 4:"))
                                 .tagChild(mBaseSize4)
                                 .tagChild(LabelText(MUIX_R "Base Address 5:"))
                                 .tagChild(mBaseAddress5)
                                 .tagChild(LabelText(MUIX_R "Base Size 5:"))
                                 .tagChild(mBaseSize5)
                                 .object())
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
                                          .tagChild(mHeaderGroup)
                                          .tagChild(MUI::MakeObject::HBar(0))
                                          .tagChild(mMainAttributesGroup)
                                          .tagChild(mBaseAttributesGroup)
                                          .tagChild(MUI::MakeObject::HVSpace())
                                          .object())
                       .object())
    {
        // window "X" button => close window
        MUI::Notifier::from(mComponent).onCloseRequest(true).notifySelf().setOpen(false);
    }

    void BoardAttributesWindow::Open(const std::string &vendor, const std::string &device, const std::string &className,
                                     const AOS::PCIX::BoardAttributes &attributes)
    {
        mVendor.setContents(vendor);
        mDevice.setContents(device);
        mClass.setContents(className);

        mBusNumber.setContents(std::to_string(attributes.busNumber));
        mBridgeName.setContents(attributes.bridgeName);
        mDeviceNumber.setContents(std::to_string(attributes.deviceNumber));
        mFunctionNumber.setContents(std::to_string(attributes.functionNumber));
        mRomAddress.setContents(attributes.romAddress != 0 ? ToString::FromDataPointer(attributes.romAddress) : "N/A");
        mRomSize.setContents(attributes.romSize ? ToString::FromBytesValue(attributes.romSize) : "N/A");

        mBaseAddress0.setContents(attributes.baseAddress0 != 0 ? ToString::FromHexValue(attributes.baseAddress0) : "N/A");
        mBaseSize0.setContents(attributes.baseSize0 ? ToString::FromBytesValue(attributes.baseSize0) : "N/A");
        mBaseAddress1.setContents(attributes.baseAddress1 != 0 ? ToString::FromHexValue(attributes.baseAddress1) : "N/A");
        mBaseSize1.setContents(attributes.baseSize1 ? ToString::FromBytesValue(attributes.baseSize1) : "N/A");
        mBaseAddress2.setContents(attributes.baseAddress2 != 0 ? ToString::FromHexValue(attributes.baseAddress2) : "N/A");
        mBaseSize2.setContents(attributes.baseSize2 ? ToString::FromBytesValue(attributes.baseSize2) : "N/A");
        mBaseAddress3.setContents(attributes.baseAddress3 != 0 ? ToString::FromHexValue(attributes.baseAddress3) : "N/A");
        mBaseSize3.setContents(attributes.baseSize3 ? ToString::FromBytesValue(attributes.baseSize3) : "N/A");
        mBaseAddress4.setContents(attributes.baseAddress4 != 0 ? ToString::FromHexValue(attributes.baseAddress4) : "N/A");
        mBaseSize4.setContents(attributes.baseSize4 ? ToString::FromBytesValue(attributes.baseSize4) : "N/A");
        mBaseAddress5.setContents(attributes.baseAddress5 != 0 ? ToString::FromHexValue(attributes.baseAddress5) : "N/A");
        mBaseSize5.setContents(attributes.baseSize5 ? ToString::FromBytesValue(attributes.baseSize5) : "N/A");

        if (mComponent.isOpen())
            return;

        mComponent.Open();
    }

    void BoardAttributesWindow::Close()
    {
        mComponent.Close();
    }
}
