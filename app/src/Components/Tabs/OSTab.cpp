//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "OSTab.hpp"

#include "AOS/Dos/Library.hpp"
#include "AOS/Exec/Library.hpp"
#include "Core/StringUtils.hpp"
#include "MUI/Listview.hpp"

namespace Components
{
    OSTab::OSTab()
      : mFullOSNameText(ValueText("Full name of Operating System and version, copyrights etc", "??", true))
      , mKickstartVersionText(ValueText("Kickstart Version"))
      , mExecVersionText(ValueText("Exec Version"))
      , mAmbientVersionText(ValueText("Ambient Version"))
      , mWorkbenchVersionText(ValueText("Workbench Version"))
      , mLoadedLibrariesList(MUI::ListBuilder().tagConstructHookString().tagDestructHookString().tagWeight(10).object())
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Operating System")
                                     //  .tagChild(LabelText(MUIX_R "Name"))
                                     .tagChild(mFullOSNameText)
                                     .tagChild(MUI::GroupBuilder()
                                                   .tagColumns(8)
                                                   .tagChild(LabelText(MUIX_R "Kickstart"))
                                                   .tagChild(mKickstartVersionText)
                                                   .tagChild(LabelText(MUIX_R "Exec"))
                                                   .tagChild(mExecVersionText)
                                                   .tagChild(LabelText(MUIX_R "Ambient"))
                                                   .tagChild(mAmbientVersionText)
                                                   .tagChild(LabelText(MUIX_R "Workbench"))
                                                   .tagChild(mWorkbenchVersionText)
                                                   .object())
                                     .object())
                       .tagChild(MUI::ListviewBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Loaded Libraries, Datatypes, ...")
                                     .tagList(mLoadedLibrariesList)
                                     .object())
                       .object())
    {
        auto os = AOS::Exec::Library::libFindResident("MorphOS");
        std::string osName = os != nullptr ? std::string(os->rt_IdString) : "??";
        StringUtils::Trim(osName);
        auto pos = osName.find(169); // copyright symbol in ISO-8859-1
        if (pos != std::string::npos && pos > 0)
            osName.replace(pos - 1, 1, "\n");
        mFullOSNameText.setContents(osName);

        auto kickstart = AOS::Dos::Library::libGetVar("Kickstart");
        mKickstartVersionText.setContents(kickstart.has_value() ? "v" + StringUtils::Split(kickstart.value()).back() : "??");

        auto ambient = AOS::Dos::Library::libGetVar("Ambient");
        mAmbientVersionText.setContents(ambient.has_value() ? "v" + StringUtils::Split(ambient.value()).back() : "??");

        auto workbench = AOS::Dos::Library::libGetVar("Workbench");
        mWorkbenchVersionText.setContents(workbench.has_value() ? "v" + StringUtils::Split(workbench.value()).back() : "??");

        mExecVersionText.setContents("v" + AOS::Exec::Library::GetVersion());

        mLoadedLibrariesList.InsertSorted([&]() -> std::vector<std::string> {
            std::vector<std::string> result;
            for (const auto &entry : AOS::Exec::Library::GetAllLibraryNames())
                result.push_back(entry.libName + " (v" + entry.version + ")");
            return result;
        }());
    }
}
