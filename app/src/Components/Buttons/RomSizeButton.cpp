//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "RomSizeButton.hpp"

#include "AOS/ASL/FileRequester.hpp"
#include "AOS/Dos/FileHandleScope.hpp"
#include "AOS/Exec/Library.hpp"

namespace Components
{
    RomSizeButton::RomSizeButton(const unsigned char *romAddress, const unsigned long romSize)
      : BasicImageButton(MUI::ImageOrBackground::PopFile, "Save ROM to file")
      , mRomAddress(const_cast<unsigned char *>(romAddress))
      , mRomSize(romSize)
    {
    }

    void RomSizeButton::SetRomData(const unsigned char *romAddress, const unsigned long romSize)
    {
        mRomAddress = const_cast<unsigned char *>(romAddress);
        mRomSize = romSize;

        if (verifyRomData())
            this->Enable();
        else
            this->Disable();
    }

    unsigned long RomSizeButton::OnClick()
    {
        if (!verifyRomData())
            return 0;

        AOS::ASL::FileRequesterScope fileRequester(AOS::ASL::FileRequesterTagsBuilder().tagInitialFile("romfile.bin").tagDoSaveMode(true));

        if (!fileRequester.request())
            return 0;

        if (const auto fullPath = fileRequester.FullPath(); fullPath.has_value())
            saveBufferToFile(fullPath.value(), mRomAddress, mRomSize);

        return 0;
    }

    bool RomSizeButton::verifyRomData() const
    {
        return mRomAddress != nullptr && mRomSize > 0 && AOS::Exec::Library::libTypeOfMem(mRomAddress) != AOS::Exec::MEMF_Type::ANY;
    }

    void RomSizeButton::saveBufferToFile(const std::string &filename, const void *data, size_t len)
    {
        AOS::Dos::FileHandleScope file(filename, AOS::Dos::OpenMode::NewFile, false);

        LONG bytesWritten = file.Write((void *)data, len);
        if (bytesWritten != (LONG)len)
            MuiWarning("Write failed!");
    }
}
