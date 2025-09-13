//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "MainboardTab.hpp"

#include "AOS/Exec/Library.hpp"
#include "DataInfo/HardwareSystemSpec.hpp"
#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    MainboardTab::MainboardTab()
      : mVendorText(ValueText("Vendor"))
      , mSystemText(ValueText("System Name"))
      , mFullNameText(ValueText("Full/Marketing Name"))
      , mIntroductionYearText(ValueText("Introduction Year"))
      , mDiscontinuedYearText(ValueText("Discontinued Year"))
      , mProcessorSocketText(ValueText("Processor Socket"))
      , mStorageDimensionsText(ValueText("Storage Dimensions"))
      , mStorageInterfaceText(ValueText("Storage Interface"))
      , mFirmwareTypeText(ValueText("Firmware Type"))
      , mComponent(
            MUI::GroupBuilder()
                .vertical()
                .tagChild(MUI::MakeObject::HVSpace())
                .tagChild(
                    MUI::GroupBuilder()
                        .tagFrame(MUI::Frame::Group)
                        .tagFrameTitle("System Information")
                        .tagChild(MUI::GroupBuilder()
                                      .tagColumns(4)
                                      .tagChild(LabelText(MUIX_R "Vendor"))
                                      .tagChild(mVendorText)
                                      .tagChild(LabelText(MUIX_R "Name"))
                                      .tagChild(mSystemText)
                                      .object())
                        .tagChild(
                            MUI::GroupBuilder().tagColumns(2).tagChild(LabelText(MUIX_R "Full Name")).tagChild(mFullNameText).object())
                        .object())
                .tagChild(MUI::GroupBuilder()
                              .tagFrame(MUI::Frame::Group)
                              .tagFrameTitle("Timeline")
                              .tagColumns(4)
                              .tagChild(LabelText(MUIX_R "Introduction Year"))
                              .tagChild(mIntroductionYearText)
                              .tagChild(LabelText(MUIX_R "Discontinued Year"))
                              .tagChild(mDiscontinuedYearText)
                              .object())
                .tagChild(MUI::GroupBuilder()
                              .tagFrame(MUI::Frame::Group)
                              .tagFrameTitle("Hardware Specifications")
                              .tagColumns(4)
                              .tagChild(LabelText(MUIX_R "Processor Socket"))
                              .tagChild(mProcessorSocketText)
                              .tagChild(LabelText(MUIX_R "Firmware Type"))
                              .tagChild(mFirmwareTypeText)
                              .tagChild(LabelText(MUIX_R "Storage Dimensions"))
                              .tagChild(mStorageDimensionsText)
                              .tagChild(LabelText(MUIX_R "Storage Interface"))
                              .tagChild(mStorageInterfaceText)
                              .object())
                .tagChild(MUI::MakeObject::HVSpace())
                .object())
    {
        mVendorText.setContents(AOS::Exec::Library::libNewGetSystemAttrsAsString(AOS::Exec::SYSTEMINFOTYPE::VENDOR));
        mSystemText.setContents(AOS::Exec::Library::libNewGetSystemAttrsAsString(AOS::Exec::SYSTEMINFOTYPE::SYSTEM));

        auto hardwareSpec = DataInfo::hardwareSystem2spec.find(mSystemText.getContents());
        if (hardwareSpec == DataInfo::hardwareSystem2spec.end())
            return;

        const auto &spec = hardwareSpec->second;
        mFullNameText.setContents(spec.marketingName);
        mIntroductionYearText.setContents(std::to_string(spec.introductionYear));
        mDiscontinuedYearText.setContents(std::to_string(spec.discontinuedYear));
        mProcessorSocketText.setContents(spec.cpuSocket);
        mStorageDimensionsText.setContents(spec.storageDimensions);
        mStorageInterfaceText.setContents(spec.storageInterface);
        mFirmwareTypeText.setContents(spec.firmwareType);
    }
}
