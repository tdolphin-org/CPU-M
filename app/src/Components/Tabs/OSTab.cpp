//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "OSTab.hpp"

#include "AOS/Exec/Library.hpp"
#include "MUI/Listview.hpp"

namespace Components
{
    OSTab::OSTab()
      : mOSNumberText(ValueText("Operating System Number"))
      , mOSVersionText(ValueText("Operating System Version"))
      , mExecVersionText(ValueText("Exec Version"))
      , mWBVersionText(ValueText("Workbench Version"))
      , mLoadedLibrariesList(MUI::ListBuilder().tagConstructHookString().tagDestructHookString().object())
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagBackground(MUI::ImageOrBackground::WindowBack)
                                     .tagFrameTitle("Operating System")
                                     .tagColumns(4)
                                     .tagChild(LabelText(MUIX_R "Number"))
                                     .tagChild(mOSNumberText)
                                     .tagChild(LabelText(MUIX_R "Version"))
                                     .tagChild(mOSVersionText)
                                     .tagChild(LabelText(MUIX_R "Exec"))
                                     .tagChild(mExecVersionText)
                                     .tagChild(LabelText(MUIX_R "Workbench"))
                                     .tagChild(mWBVersionText)
                                     .object())
                       .tagChild(MUI::ListviewBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Loaded Libraries, Datatypes, ...")
                                     .tagBackground(MUI::ImageOrBackground::WindowBack)
                                     .tagList(mLoadedLibrariesList)
                                     .object())
                       .object())
    {
        mOSVersionText.setContents("mock 1.0.0"); // TODO: get real version
        mOSNumberText.setContents("mock 1.0.0");
        mExecVersionText.setContents("mock 1.0.0");
        mWBVersionText.setContents("mock 1.0.0");
        mLoadedLibrariesList.InsertSorted([]() -> std::vector<std::string> {
            std::vector<std::string> result;
            for (const auto &entry : AOS::Exec::Library::GetAllLibraryNames())
                result.push_back(entry.libName + " (v" + entry.version + ")");
            return result;
        }());
    }
}
