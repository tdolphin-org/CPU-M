//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "GPUSpecWindow.hpp"

#include "Components/IDs.hpp"
#include "MUI/Notifier/Notifier.hpp"
#include "ProgDefines.hpp"
#include "Version.hpp"

namespace Components
{
    GPUSpecWindow::GPUSpecWindow()
      : mManufacturer(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mModelName(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mPremiere(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mInterface(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mTechnology(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mCoreClock(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mMemory(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mChipSpecGroup(MUI::GroupBuilder()
                           .vertical()
                           .tagChild(MUI::GroupBuilder()
                                         .tagColumns(3)
                                         .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Manufacturer").object())
                                         .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Name").object())
                                         .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Premiere").object())
                                         .tagChild(mManufacturer)
                                         .tagChild(mModelName)
                                         .tagChild(mPremiere)
                                         .object())
                           .tagChild(MUI::GroupBuilder()
                                         .tagColumns(3)
                                         .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Interface").object())
                                         .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Technology").object())
                                         .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Core Clock").object())
                                         .tagChild(mInterface)
                                         .tagChild(mTechnology)
                                         .tagChild(mCoreClock)
                                         .object())
                           .tagChild(MUI::GroupBuilder()
                                         .tagColumns(2)
                                         .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Memory").object())
                                         .tagChild(mMemory)
                                         .object())
                           .object())
      , mComponent(MUI::WindowBuilder()
                       .tagTitle("GPU Specification")
                       .tagScreenTitle(SCREEN_TITLE)
                       .tagID(WindowID::GPUSpecWindow)
                       .tagWidth(500)
                       .tagHeight(240)
                       .tagAltWidth(1024)
                       .tagAltHeight(600)
                       .tagRootObject(mChipSpecGroup)
                       .object())
    {
        // window "X" button => close window
        MUI::Notifier::from(mComponent).onCloseRequest(true).notifySelf().setOpen(false);
    }

    void GPUSpecWindow::Open(const std::vector<DataInfo::GPUID> &chips)
    {
        if (chips.empty())
            return;
        auto chipSpec = DataInfo::gpu2spec.at(chips.at(0));

        mManufacturer.setContents(chipSpec.manufacturer);
        mModelName.setContents(chipSpec.modelName);
        mPremiere.setContents(chipSpec.premiere);
        mInterface.setContents(chipSpec.interface);
        mTechnology.setContents(chipSpec.technology);
        mCoreClock.setContents(chipSpec.coreClock > 0 ? std::to_string(chipSpec.coreClock) + " MHz" : "??");
        mMemory.setContents(chipSpec.memory);

        MUI::Window(*this).Open();
    }

    void GPUSpecWindow::Close()
    {
        MUI::Window(*this).Close();
    }
}