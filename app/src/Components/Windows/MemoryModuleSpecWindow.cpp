//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "MemoryModuleSpecWindow.hpp"

#include "Components/IDs.hpp"
#include "FileResources/MemoryModuleImages.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Notifier/Notifier.hpp"
#include "ProgDefines.hpp"
#include "Version.hpp"

static std::map<std::pair<MemoryGeneration, ModuleForm>, std::string> memoryModule2image = {
    { { MemoryGeneration::SDR, ModuleForm::DIMM }, MemoryModuleImageFile::sdr_dimm },
    { { MemoryGeneration::SDR, ModuleForm::SO_DIMM }, MemoryModuleImageFile::sdr_so_dimm },
    { { MemoryGeneration::DDR, ModuleForm::DIMM }, MemoryModuleImageFile::ddr_dimm },
    { { MemoryGeneration::DDR, ModuleForm::SO_DIMM }, MemoryModuleImageFile::ddr_so_dimm },
    { { MemoryGeneration::DDR2, ModuleForm::DIMM }, MemoryModuleImageFile::ddr2_dimm },
    { { MemoryGeneration::DDR2, ModuleForm::SO_DIMM }, MemoryModuleImageFile::ddr2_so_dimm },
    { { MemoryGeneration::DDR3, ModuleForm::DIMM }, MemoryModuleImageFile::ddr3_dimm },
    { { MemoryGeneration::DDR3, ModuleForm::SO_DIMM }, MemoryModuleImageFile::ddr3_so_dimm },
};

namespace Components
{
    MemoryModuleSpecWindow::MemoryModuleSpecWindow()
      : mTypeText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mModuleFormText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mGenerationText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mIntroductionYearText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mDataTransferMTsText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mBandwidthMBsText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mClockText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mWidthText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mPinsCountText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mVoltageText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mNotesText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mModuleSpecGroup(
            MUI::GroupBuilder()
                .vertical()
                .tagChild(mModuleImage = MUI::MakeObject::CLabel("image placeholder"))
                .tagChild(MUI::GroupBuilder()
                              .tagColumns(4)
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Type:").object())
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Module Form:").object())
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Generation:").object())
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Introduction Year:").object())
                              .tagChild(mTypeText)
                              .tagChild(mModuleFormText)
                              .tagChild(mGenerationText)
                              .tagChild(mIntroductionYearText)
                              .object())
                .tagChild(MUI::GroupBuilder()
                              .tagColumns(3)
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Width:").object())
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Number of Pins:").object())
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Voltage:").object())
                              .tagChild(mWidthText)
                              .tagChild(mPinsCountText)
                              .tagChild(mVoltageText)
                              .object())
                .tagChild(MUI::GroupBuilder()
                              .tagColumns(3)
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Data Transfer Rate:").object())
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Bandwidth:").object())
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Clock:").object())
                              .tagChild(mDataTransferMTsText)
                              .tagChild(mBandwidthMBsText)
                              .tagChild(mClockText)
                              .object())
                .tagChild(MUI::GroupBuilder()
                              .tagColumns(1)
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Notes:").object())
                              .tagChild(mNotesText)
                              .object())
                .object())
      , mComponent(MUI::WindowBuilder()
                       .tagTitle("Memory Module Specification")
                       .tagScreenTitle(SCREEN_TITLE)
                       .tagID(WindowID::MemoryModuleSpecWindow)
                       .tagWidth(500)
                       .tagHeight(240)
                       .tagAltWidth(820)
                       .tagAltHeight(480)
                       .tagRootObject(mModuleSpecGroup)
                       .object())
    {
        // window "X" button => close window
        MUI::Notifier::from(mComponent).onCloseRequest(true).notifySelf().setOpen(false);
    }

    void MemoryModuleSpecWindow::Open(const std::pair<MemoryType, ModuleForm> &memoryTypeAndForm)
    {
        auto memorySpec = DataInfo::memorySpecs.find(memoryTypeAndForm.first);
        if (memorySpec != DataInfo::memorySpecs.end())
        {
            auto imageIt = memoryModule2image.find({ memorySpec->second.generation, memoryTypeAndForm.second });
            if (imageIt != memoryModule2image.end())
            {
                mModuleSpecGroup.InitChange();
                if (mModuleImage)
                    mModuleSpecGroup.Remove(mModuleImage);
                mModuleImage = CreateImage(memorySpec->second.generation, memoryTypeAndForm.second);
                mModuleSpecGroup.AddHead(mModuleImage ? MUI::MakeObject::HCenter(mModuleImage)
                                                      : MUI::MakeObject::CLabel("image placeholder"));
                mModuleSpecGroup.ExitChange();
            }
            mTypeText.setContents(memorySpec->second.name());
            mModuleFormText.setContents(std::to_string(memoryTypeAndForm.second));
            mGenerationText.setContents(std::to_string(memorySpec->second.generation));
            mVoltageText.setContents(DataInfo::mVToVoltage(memorySpec->second.voltage_mV));
            mDataTransferMTsText.setContents(std::to_string(memorySpec->second.dataRateMTs) + " MT/s");
            mBandwidthMBsText.setContents(std::to_string(memorySpec->second.bandwidthMBs) + " MB/s");
            mClockText.setContents(std::to_string(memorySpec->second.clockMHz) + " MHz");
            mNotesText.setContents(memorySpec->second.notes);
        }
        else
        {
            mTypeText.setContents(std::to_string(memoryTypeAndForm.first));
            mModuleFormText.setContents(std::to_string(memoryTypeAndForm.second));
            mGenerationText.setContents("--");
            mVoltageText.setContents("--");
            mDataTransferMTsText.setContents("--");
            mBandwidthMBsText.setContents("--");
            mClockText.setContents("--");
            mNotesText.setContents("No additional information available.");
        }

        auto moduleSpec = DataInfo::moduleSpecs.find({ memorySpec->second.generation, memoryTypeAndForm.second });
        if (moduleSpec != DataInfo::moduleSpecs.end())
        {
            mWidthText.setContents(std::to_string(moduleSpec->second.length_mm) + " mm");
            mPinsCountText.setContents(std::to_string(moduleSpec->second.pins) + " pins");
            mIntroductionYearText.setContents(std::to_string(moduleSpec->second.introductionYear));
        }
        else
        {
            mWidthText.setContents("--");
            mPinsCountText.setContents("--");
            mIntroductionYearText.setContents("--");
        }

        MUI::Window(*this).Open();
    }

    void MemoryModuleSpecWindow::Close()
    {
        MUI::Window(*this).Close();
    }

    Object *MemoryModuleSpecWindow::CreateImage(const MemoryGeneration memoryGeneration, const ModuleForm memoryTypeAndForm)
    {
        auto imageIt = memoryModule2image.find({ memoryGeneration, memoryTypeAndForm });
        if (imageIt != memoryModule2image.end())
        {
            if (memoryTypeAndForm == ModuleForm::DIMM)
            {
                return MUI::ImageBuilder()
                    .tagSpecPicture(imageIt->second.c_str())
                    .tagFixWidth(810)
                    .tagFixHeight(190)
                    .tagFreeHoriz(true)
                    .tagFreeVert(true)
                    .object()
                    .muiObject();
            }
            else // SO_DIMM
            {
                return MUI::ImageBuilder()
                    .tagSpecPicture(imageIt->second.c_str())
                    .tagFixWidth(410)
                    .tagFixHeight(190)
                    .tagFreeHoriz(true)
                    .tagFreeVert(true)
                    .object()
                    .muiObject();
            }
        }

        return nullptr;
    }
}