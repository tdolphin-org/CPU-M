//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "MainboardTab.hpp"

#include "AOS/Exec/Library.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    MainboardTab::MainboardTab()
      : mVendorText(ValueText("Vendor"))
      , mSystemText(ValueText("System Name"))
      , mFullNameText(ValueText("Full Name"))
      , mRevisionText(ValueText("Revision"))
      , mIntroductionDateText(ValueText("Introduction Date"))
      , mDiscontinuedDateText(ValueText("Discontinued Date"))
      , mProcessorUpgradeText(ValueText("Processor Socket"))
      , mProcessorUpgradeDetailsText(ValueText("Processor Socket Details", "--", true))
      , mBatteryTypeText(ValueText("Battery Type"))
      , mStorageDimensionsText(ValueText("Storage Dimensions"))
      , mStorageInterfaceText(ValueText("Storage Interface"))
      , mFirmwareTypeText(ValueText("Firmware Type"))
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Hardware System")
                                     .tagColumns(4)
                                     .tagChild(LabelText(MUIX_R "Vendor"))
                                     .tagChild(mVendorText)
                                     .tagChild(LabelText(MUIX_R "Name"))
                                     .tagChild(mSystemText)
                                     .tagChild(LabelText(MUIX_R "Full Name"))
                                     .tagChild(mFullNameText)
                                     .tagChild(LabelText(MUIX_R "Revision"))
                                     .tagChild(mRevisionText)
                                     .tagChild(LabelText(MUIX_R "Introduction"))
                                     .tagChild(mIntroductionDateText)
                                     .tagChild(LabelText(MUIX_R "Discontinued"))
                                     .tagChild(mDiscontinuedDateText)
                                     .tagChild(LabelText(MUIX_R "Processor Socket"))
                                     .tagChild(mProcessorUpgradeText)
                                     .tagChild(LabelText(MUIX_R "Processor Socket Details"))
                                     .tagChild(mProcessorUpgradeDetailsText)
                                     .tagChild(LabelText(MUIX_R "Battery Type"))
                                     .tagChild(mBatteryTypeText)
                                     .tagChild(LabelText(MUIX_R "Storage Dimensions"))
                                     .tagChild(mStorageDimensionsText)
                                     .tagChild(LabelText(MUIX_R "Storage Interface"))
                                     .tagChild(mStorageInterfaceText)
                                     .tagChild(LabelText(MUIX_R "Firmware Type"))
                                     .tagChild(mFirmwareTypeText)
                                     .object())
                       .object())
    {
        mVendorText.setContents(AOS::Exec::Library::libNewGetSystemAttrsAsString(AOS::Exec::SYSTEMINFOTYPE::VENDOR));
        mSystemText.setContents(AOS::Exec::Library::libNewGetSystemAttrsAsString(AOS::Exec::SYSTEMINFOTYPE::SYSTEM));
        mRevisionText.setContents(
            std::to_string(AOS::Exec::Library::libNewGetSystemAttrsAsUnsignedLong(AOS::Exec::SYSTEMINFOTYPE::REVISION)));
    }
}
