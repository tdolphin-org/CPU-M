//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "MainboardTab.hpp"

#include "AOS/Exec/Library.hpp"
#include "DataInfo/HardwareSystemSpec.hpp"
#include "FileResources/ManufacturerImages.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Image.hpp"

static std::map<DataInfo::HardwareManufacturerID, std::pair<std::string, std::pair<unsigned int, unsigned int>>> hardware2image = {
    { DataInfo::HardwareManufacturerID::A_EON, { ManufacturerImageFile::a_eon_logo, { 100, 100 } } },
    { DataInfo::HardwareManufacturerID::ACUBE, { ManufacturerImageFile::acube_logo, { 100, 100 } } },
    { DataInfo::HardwareManufacturerID::APPLE, { ManufacturerImageFile::apple_logo, { 85, 104 } } },
    { DataInfo::HardwareManufacturerID::BPLAN, { ManufacturerImageFile::bplan_logo, { 64, 64 } } },
    { DataInfo::HardwareManufacturerID::MIRARI, { ManufacturerImageFile::mirari_logo, { 100, 100 } } },
};

namespace Components
{
    MainboardTab::MainboardTab()
      : mVendorText(ValueText("Vendor of Hardware System or Mainboard"))
      , mSystemText(ValueText("System Name"))
      , mFullNameText(ValueText("Full/Marketing Name"))
      , mModelNumberText(ValueText("Model Number (optional)"))
      , mTimelineText(ValueText("Timeline, years range, e.g. 2006-2009"))
      , mSystemInfoGroup(MUI::GroupBuilder()
                             .horizontal()
                             .tagFrame(MUI::Frame::Group)
                             .tagFrameTitle("System Information")
                             .tagChild(MUI::GroupBuilder()
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
                             .object())
      , mProcessorSocketText(ValueText("Processor Socket, type or description"))
      , mFirmwareTypeText(ValueText("Firmware Type, e.g. Open Firmware, U-Boot"))
      , mStorageInterfacesText(ValueText("Storage Interfaces if applicable, e.g. SATA", "--", true, 250))
      , mPortsGroup(MUI::FloattextBuilder().object())
      , mComponent(
            MUI::GroupBuilder()
                .vertical()
                .tagChild(MUI::MakeObject::HVSpace())
                .tagChild(mSystemInfoGroup)
                .tagChild(
                    MUI::GroupBuilder()
                        .tagFrame(MUI::Frame::Group)
                        .tagFrameTitle("Hardware Specifications")
                        .vertical()
                        .tagChild(MUI::GroupBuilder()
                                      .horizontal()
                                      .tagChild(MUI::GroupBuilder()
                                                    .vertical()
                                                    .tagChild(LabelText(MUIX_R "Processor Socket:"))
                                                    .tagChild(LabelText(MUIX_R "Storage Interfaces:"))
                                                    .object())
                                      .tagChild(MUI::GroupBuilder()
                                                    .vertical()
                                                    .tagChild(MUI::GroupBuilder()
                                                                  .horizontal()
                                                                  .tagChild(mProcessorSocketText)
                                                                  .tagChild(LabelText(MUIX_R "Firmware Type:"))
                                                                  .tagChild(mFirmwareTypeText)
                                                                  .object())
                                                    .tagChild(MUI::GroupBuilder().horizontal().tagChild(mStorageInterfacesText).object())
                                                    .object())
                                      .object())
                        .tagChild(MUI::GroupBuilder().tagFrame(MUI::Frame::Group).tagFrameTitle("Ports").tagChild(mPortsGroup).object())
                        .object())
                .object())
    {
        auto systemName = AOS::Exec::Library::libNewGetSystemAttrsAsString(AOS::Exec::SYSTEMINFOTYPE::SYSTEM);

        mVendorText.setContents(AOS::Exec::Library::libNewGetSystemAttrsAsString(AOS::Exec::SYSTEMINFOTYPE::VENDOR));
        mSystemText.setContents(systemName);

        auto hardwareSpec = DataInfo::FindHardwareSystemSpecByID(systemName);
        if (!hardwareSpec.has_value())
            return;

        const auto &spec = hardwareSpec.value();
        mFullNameText.setContents(MUIX_B + spec.marketingName);
        if (spec.modelNumber.has_value())
            mModelNumberText.setContents(spec.modelNumber.value());
        mTimelineText.setContents(std::to_string(spec.introductionYear)
                                  + (spec.discontinuedYear.has_value() ? " - " + std::to_string(spec.discontinuedYear.value()) : ""));
        mProcessorSocketText.setContents(spec.cpuSocket);

        // producer logo
        auto it = hardware2image.find(spec.manufacturer);
        if (it != hardware2image.end())
        {
            mSystemInfoGroup.AddTail(MUI::ImageBuilder()
                                         .tagSpecPicture(it->second.first.c_str())
                                         .tagFixWidth(it->second.second.first)
                                         .tagFixHeight(it->second.second.second)
                                         .tagFreeHoriz(true)
                                         .tagFreeVert(true)
                                         .object());
        }

        mStorageInterfacesText.setContents(ToString::Concatenate(spec.storageInterfaces, ", "));
        mFirmwareTypeText.setContents(spec.firmwareType);
        for (const auto &port : spec.ports)
            mPortsGroup.Append(port.type + " (x" + std::to_string(port.count) + "); ");
        if (spec.notes.has_value())
        {
            mComponent.AddTail(MUI::TextBuilder()
                                   .tagFrame(MUI::Frame::Text)
                                   .tagShortHelp("Additional Notes regarding this mainboard or system")
                                   .tagSetMin(true)
                                   .tagContents(spec.notes.value())
                                   .object());
        }

        mComponent.AddTail(MUI::MakeObject::HVSpace());
    }
}
