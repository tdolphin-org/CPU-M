//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "MemoryModuleSpecWindow.hpp"

#include "Components/IDs.hpp"
#include "FileResources/MemoryModuleImages.hpp"
#include "MUI/Notifier/Notifier.hpp"
#include "ProgDefines.hpp"
#include "Version.hpp"

static std::map<std::pair<MemoryGeneration, ModuleForm>, std::string> memoryModule2image = {
    { { MemoryGeneration::SDR, ModuleForm::DIMM }, MemoryModuleImageFile::ddr_dimm }, // FIXME
    { { MemoryGeneration::SDR, ModuleForm::SO_DIMM }, MemoryModuleImageFile::ddr_dimm },
    { { MemoryGeneration::DDR, ModuleForm::DIMM }, MemoryModuleImageFile::ddr_dimm },
    { { MemoryGeneration::DDR, ModuleForm::SO_DIMM }, MemoryModuleImageFile::ddr_dimm },
    { { MemoryGeneration::DDR2, ModuleForm::DIMM }, MemoryModuleImageFile::ddr_dimm },
    { { MemoryGeneration::DDR2, ModuleForm::SO_DIMM }, MemoryModuleImageFile::ddr_dimm },
    { { MemoryGeneration::DDR3, ModuleForm::DIMM }, MemoryModuleImageFile::ddr_dimm },
    { { MemoryGeneration::DDR3, ModuleForm::SO_DIMM }, MemoryModuleImageFile::ddr_dimm },
};

namespace Components
{
    MemoryModuleSpecWindow::MemoryModuleSpecWindow()
      : mModuleImage(MUI::ImageBuilder()
                         .tagSpecPicture(MemoryModuleImageFile::ddr_dimm)
                         .tagFixWidth(800)
                         .tagFixHeight(256)
                         .tagFreeHoriz(true)
                         .tagFreeVert(true)
                         .object())
      , mTypeText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mModuleFormText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mGenerationText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mVoltageText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mDataTransferMTsText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mBandwidthMBsText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mClockText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mNotesText(MUI::TextBuilder().tagFrame(MUI::Frame::String).object())
      , mModuleSpecGroup(
            MUI::GroupBuilder()
                .vertical()
                .tagChild(mModuleImage)
                .tagChild(MUI::GroupBuilder()
                              .tagColumns(3)
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Type:").object())
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Module Form:").object())
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Generation:").object())
                              .tagChild(mTypeText)
                              .tagChild(mModuleFormText)
                              .tagChild(mGenerationText)
                              .object())
                .tagChild(MUI::GroupBuilder()
                              .tagColumns(4)
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Data Transfer Rate:").object())
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Bandwidth:").object())
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Clock:").object())
                              .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Voltage:").object())
                              .tagChild(mDataTransferMTsText)
                              .tagChild(mBandwidthMBsText)
                              .tagChild(mClockText)
                              .tagChild(mVoltageText)
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
                       .tagAltWidth(640)
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
            mTypeText.setContents(memorySpec->second.name() + " (" + memorySpec->second.alias() + ")");
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

        MUI::Window(*this).Open();
    }

    void MemoryModuleSpecWindow::Close()
    {
        MUI::Window(*this).Close();
    }
}