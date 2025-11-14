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
      : mVendorText(ValueText("Vendor of Hardware System or Mainboard"))
      , mSystemText(ValueText("System Name"))
      , mFullNameText(ValueText("Full/Marketing Name"))
      , mModelNumberText(ValueText("Model Number (optional)"))
      , mTimelineText(ValueText("Timeline, years range, e.g. 2006-2009"))
      , mProcessorSocketText(ValueText("Processor Socket, type or description"))
      , mFirmwareTypeText(ValueText("Firmware Type, e.g. Open Firmware, U-Boot"))
      , mStorageInterfacesText(ValueText("Storage Interfaces if applicable, e.g. SATA", "--", true, 250))
      , mPortsGroup(MUI::FloattextBuilder().object())
      , mNoteText(ValueText("Additional Notes regarding this mainboard or system"))
      , mComponent(
            MUI::GroupBuilder()
                .vertical()
                .tagChild(MUI::MakeObject::HVSpace())
                .tagChild(MUI::GroupBuilder()
                              .tagFrame(MUI::Frame::Group)
                              .tagFrameTitle("System Information")
                              .tagColumns(4)
                              .tagChild(LabelText(MUIX_R "Vendor:"))
                              .tagChild(mVendorText)
                              .tagChild(LabelText(MUIX_R "Name:"))
                              .tagChild(mSystemText)
                              .tagChild(LabelText(MUIX_R "Full Name:"))
                              .tagChild(mFullNameText)
                              .tagChild(LabelText(MUIX_R "Model Number:"))
                              .tagChild(mModelNumberText)
                              .tagChild(LabelText(MUIX_R "Timeline:"))
                              .tagChild(mTimelineText)
                              .object())
                .tagChild(
                    MUI::GroupBuilder()
                        .tagFrame(MUI::Frame::Group)
                        .tagFrameTitle("Hardware Specifications")
                        .vertical()
                        .tagChild(MUI::GroupBuilder()
                                      .horizontal()
                                      .tagChild(LabelText(MUIX_R "Processor Socket:", 50))
                                      .tagChild(mProcessorSocketText)
                                      .tagChild(LabelText(MUIX_R "Firmware Type:", 50))
                                      .tagChild(mFirmwareTypeText)
                                      .object())
                        .tagChild(MUI::GroupBuilder()
                                      .horizontal()
                                      .tagChild(LabelText(MUIX_R "Storage Interfaces:", 50))
                                      .tagChild(mStorageInterfacesText)
                                      .object())
                        .tagChild(MUI::GroupBuilder().tagFrame(MUI::Frame::Group).tagFrameTitle("Ports").tagChild(mPortsGroup).object())
                        .object())
                .tagChild(MUI::GroupBuilder().tagFrame(MUI::Frame::Group).tagFrameTitle("Additional Notes").tagChild(mNoteText).object())
                .tagChild(MUI::MakeObject::HVSpace())
                .object())
    {
        mVendorText.setContents(AOS::Exec::Library::libNewGetSystemAttrsAsString(AOS::Exec::SYSTEMINFOTYPE::VENDOR));
        mSystemText.setContents(AOS::Exec::Library::libNewGetSystemAttrsAsString(AOS::Exec::SYSTEMINFOTYPE::SYSTEM));

        auto hardwareSpec = DataInfo::hardwareSystem2spec.find(mSystemText.getContents());
        if (hardwareSpec == DataInfo::hardwareSystem2spec.end())
            return;

        const auto &spec = hardwareSpec->second;
        mFullNameText.setContents(MUIX_B + spec.marketingName);
        if (spec.modelNumber.has_value())
            mModelNumberText.setContents(spec.modelNumber.value());
        mTimelineText.setContents(std::to_string(spec.introductionYear)
                                  + (spec.discontinuedYear.has_value() ? " - " + std::to_string(spec.discontinuedYear.value()) : ""));
        mProcessorSocketText.setContents(spec.cpuSocket);

        mStorageInterfacesText.setContents(ToString::Concatenate(spec.storageInterfaces, ", "));
        mFirmwareTypeText.setContents(spec.firmwareType);
        for (const auto &port : spec.ports)
            mPortsGroup.Append(port.type + " (x" + std::to_string(port.count) + "); ");
        if (spec.notes.has_value())
            mNoteText.setContents(spec.notes.value());
    }
}
