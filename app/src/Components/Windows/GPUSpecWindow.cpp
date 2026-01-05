//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "GPUSpecWindow.hpp"

#include "Components/IDs.hpp"
#include "Components/Tabs/Graphics/RenderConfig.hpp"
#include "FileResources/VendorImages.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Image.hpp"
#include "MUI/Notifier/Notifier.hpp"
#include "ProgDefines.hpp"
#include "Version.hpp"

static std::map<DataInfo::ManufacturerID, std::pair<std::string, std::pair<unsigned int, unsigned int>>> manufacturer2image = {
    { DataInfo::ManufacturerID::_3DFX, { VendorImageFile::three_dfx_logo, { 132, 104 } } },
    { DataInfo::ManufacturerID::_3DLABS, { VendorImageFile::three_dlabs_logo, { 128, 49 } } },
    { DataInfo::ManufacturerID::AMD, { VendorImageFile::amd_logo, { 135, 35 } } },
    { DataInfo::ManufacturerID::ATI, { VendorImageFile::ati_logo, { 128, 90 } } },
    { DataInfo::ManufacturerID::SIS, { VendorImageFile::sis_logo, { 128, 78 } } },
    { DataInfo::ManufacturerID::XGI, { VendorImageFile::xgi_logo, { 128, 89 } } },
};

namespace Components
{
    GPUSpecWindow::GPUSpecWindow()
      : mManufacturer(MUI::TextBuilder().tagFrame(MUI::Frame::Text).object())
      , mModelName(MUI::TextBuilder().tagFrame(MUI::Frame::Text).object())
      , mPremiere(MUI::TextBuilder().tagFrame(MUI::Frame::Text).object())
      , mArchitecture(MUI::TextBuilder().tagFrame(MUI::Frame::Text).object())
      , mTechnology(MUI::TextBuilder().tagFrame(MUI::Frame::Text).object())
      , mMaxTDP(MUI::TextBuilder().tagFrame(MUI::Frame::Text).object())
      , mWarningsText(
            MUI::TextBuilder()
                .tagFrame(MUI::Frame::Text)
                .tagContents(MUIX_B
                             "Note:" MUIX_N " The listed GPU configuration reflects the full capabilities of the GPU model.\n"
                             "The actual hardware on this graphics card may have reduced units (e.g., disabled shaders, TMUs, or ROPs).")
                .object())
      , mWithLogoGroup(MUI::GroupBuilder()
                           .horizontal()
                           .tagChild(mLogoImage = MUI::MakeObject::VCenter(MUI::MakeObject::CLabel("logo placeholder")))
                           .tagChild(MUI::GroupBuilder()
                                         .tagColumns(3)
                                         .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Manufacturer:").object())
                                         .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Name:").object())
                                         .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Premiere:").object())
                                         .tagChild(mManufacturer)
                                         .tagChild(mModelName)
                                         .tagChild(mPremiere)
                                         .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Architecture:").object())
                                         .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Technology:").object())
                                         .tagChild(MUI::TextBuilder().tagFont(MUI::Font::Tiny).tagContents("Max TDP:").object())
                                         .tagChild(mArchitecture)
                                         .tagChild(mTechnology)
                                         .tagChild(mMaxTDP)
                                         .object())
                           .object())
      , mChipSpecGroup(MUI::GroupBuilder()
                           .horizontal()
                           .tagChild(MUI::GroupBuilder().vertical().tagChild(mWithLogoGroup).tagChild(mWarningsText).object())
                           .tagChild(mRenderConfig = MUI::MakeObject::CLabel("render config placeholder"))
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

    void GPUSpecWindow::Open(const DataInfo::GPUID gpuId)
    {
        auto gpuSpec = DataInfo::gpu2spec.find(gpuId);
        if (gpuSpec != DataInfo::gpu2spec.end())
        {
            auto imageIt = manufacturer2image.find(gpuSpec->second.manufacturer);
            if (imageIt != manufacturer2image.end())
            {
                mWithLogoGroup.InitChange();
                if (mLogoImage)
                    mWithLogoGroup.Remove(mLogoImage);
                mLogoImage = CreateImage(gpuSpec->second.manufacturer);
                mWithLogoGroup.AddHead(MUI::MakeObject::VCenter(mLogoImage ? mLogoImage : MUI::MakeObject::CLabel("logo placeholder")));
                mWithLogoGroup.ExitChange();
            }

            mManufacturer.setContents(std::to_string(gpuSpec->second.manufacturer));
            mModelName.setContents(std::to_string(gpuId));
            mPremiere.setContents(std::to_string(gpuSpec->second.premiere));
            mArchitecture.setContents(gpuSpec->second.architecture ? std::to_string(gpuSpec->second.architecture.value()) : "N/A");
            mTechnology.setContents(std::to_string(gpuSpec->second.technology));
            mMaxTDP.setContents(gpuSpec->second.maxTDP ? std::to_string(gpuSpec->second.maxTDP.value()) + " W" : "N/A");

            mChipSpecGroup.Remove(mRenderConfig);
            mChipSpecGroup.AddTail(mRenderConfig = RenderConfig(gpuSpec->second.renderConfig).muiObject());
        }

        if (mComponent.isOpen())
        {
            mComponent.ToFront();
            return;
        }

        mComponent.Open();
    }

    void GPUSpecWindow::Close()
    {
        mComponent.Close();
    }

    Object *GPUSpecWindow::CreateImage(const DataInfo::ManufacturerID manufacturerId)
    {
        auto imageIt = manufacturer2image.find(manufacturerId);
        if (imageIt != manufacturer2image.end())
        {
            return MUI::ImageBuilder()
                .tagSpecPicture(imageIt->second.first.c_str())
                .tagFixWidth(imageIt->second.second.first)
                .tagFixHeight(imageIt->second.second.second)
                .tagFreeHoriz(true)
                .tagFreeVert(true)
                .object();
        }

        return nullptr;
    }
}