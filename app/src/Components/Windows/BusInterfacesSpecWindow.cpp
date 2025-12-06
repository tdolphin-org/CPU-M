//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "BusInterfacesSpecWindow.hpp"

#include "Components/IDs.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Notifier/Notifier.hpp"
#include "MUI/Text.hpp"
#include "Version.hpp"

// values in MB
std::vector<std::pair<std::string, uint32_t>> pci2transfer = {
    // PCI
    { "PCI 32-bit/33 MHz", 133 }, // 133 MiB/s
    { "PCI 32-bit/66 MHz", 266 }, // 266 MiB/s
    { "PCI 64-bit/33 MHz", 266 }, // 266 MiB/s
    { "PCI 64-bit/66 MHz", 533 }, // 533 MiB/s
};

// values in MB
std::vector<std::pair<std::string, uint32_t>> agp2transfer = {
    // AGP
    { "AGP 1x", 266 }, // 266 MiB/s
    { "AGP 2x", 533 }, // 533 MiB/s
    { "AGP 4x", 1066 }, // 1 GiB/s
    { "AGP 8x", 2133 }, // 2 GiB/s
};

// values in MB
std::vector<std::pair<std::string, uint32_t>> pcie2transfer = {
    // PCIe
    { "PCIe x8 Gen1", 1907 }, // 1907 MiB/s
    { "PCIe x8 Gen2", 3814 }, // 3814 MiB/s
    { "PCIe x8 Gen3", 7516 }, // 7516 MiB/s
    { "PCIe x8 Gen4", 15017 }, // 15017 MiB/s
    { "PCIe x16 Gen1", 3814 }, // 3814 MiB/s
    { "PCIe x16 Gen2", 7629 }, // 7629 MiB/s
    { "PCIe x16 Gen3", 15032 }, // 15032 MiB/s
    { "PCIe x16 Gen4", 30034 }, // 30034 MiB/s
};

namespace Components
{
    BusInterfacesSpecWindow::BusInterfacesSpecWindow()
      : mPciInterfacesGroup(MUI::GroupBuilder().tagColumns(2).object())
      , mAgpInterfacesGroup(MUI::GroupBuilder().tagColumns(2).object())
      , mPcieInterfacesGroup(MUI::GroupBuilder().tagColumns(2).object())
      , mBusInterfacesGroup(
            MUI::GroupBuilder()
                .vertical()
                .tagChild(MUI::GroupBuilder()
                              .tagColumns(2)
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Bus Interface:").tagWeight(50).object())
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Max Throughput:").object())
                              .object())
                .tagChild(MUI::MakeObject::HBar(0))
                .tagChild(mPciInterfacesGroup)
                .tagChild(MUI::MakeObject::HBar(0))
                .tagChild(mAgpInterfacesGroup)
                .tagChild(MUI::MakeObject::HBar(0))
                .tagChild(mPcieInterfacesGroup)
                .object())
      , mComponent(MUI::WindowBuilder()
                       .tagTitle("Bus Interfaces Specification")
                       .tagScreenTitle(SCREEN_TITLE)
                       .tagID(WindowID::BusInterfacesSpecWindow)
                       .tagWidth(400)
                       .tagHeight(500)
                       .tagAltWidth(600)
                       .tagAltHeight(600)
                       .tagRootObject(mBusInterfacesGroup)
                       .object())
    {
        for (const auto &[name, speed] : pci2transfer)
            mPciInterfacesGroup.AddTail(LabelText(MUIX_R + name, 50)).AddTail(ValueText(name, std::to_string(speed) + " MB/s"));

        for (const auto &[name, speed] : agp2transfer)
            mAgpInterfacesGroup.AddTail(LabelText(MUIX_R + name, 50)).AddTail(ValueText(name, std::to_string(speed) + " MB/s"));
        for (const auto &[name, speed] : pcie2transfer)
            mPcieInterfacesGroup.AddTail(LabelText(MUIX_R + name, 50)).AddTail(ValueText(name, "~" + std::to_string(speed) + " MB/s"));

        // window "X" button => close window
        MUI::Notifier::from(mComponent).onCloseRequest(true).notifySelf().setOpen(false);
    }

    void BusInterfacesSpecWindow::Open()
    {
        if (mComponent.isOpen())
            return;
        mComponent.Open();
    }

    void BusInterfacesSpecWindow::Close()
    {

        mComponent.Close();
    }
}
