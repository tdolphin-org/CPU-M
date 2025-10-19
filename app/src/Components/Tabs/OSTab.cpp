//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "OSTab.hpp"

#include "AOS/Dos/Library.hpp"
#include "AOS/Exec/Library.hpp"
#include "AOS/Rexxsyslib/ArgstringScope.hpp"
#include "AOS/Rexxsyslib/Library.hpp"
#include "AOS/Rexxsyslib/RexxMsgScope.hpp"
#include "AppContext.hpp"
#include "Core/StringUtils.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Listview.hpp"
#include "ProgDefines.hpp"

namespace Components
{
    OSTab::OSTab()
      : mFullOSNameText(ValueText("Full name of Operating System and version, copyrights etc", "??", true))
      , mKickstartVersionText(ValueText("Kickstart Version"))
      , mExecVersionText(ValueText("Exec Version"))
      , mAmbientVersionText(ValueText("Ambient Version", "??"))
      , mWorkbenchVersionText(ValueText("Workbench Version"))
      , mUserText(ValueText("Current user name"))
      , mTimeZoneText(ValueText("Current time zone"))
      , mCodePageText(ValueText("Current code page"))
      , mLocaleText(ValueText("Current locale"))
      , mLoadedLibrariesList(MUI::ListBuilder().tagFrame(MUI::Frame::ReadList).stringHooks().object())
      , mLoadedDevicesList(MUI::ListBuilder().tagFrame(MUI::Frame::ReadList).stringHooks().object())
      , mLoadedDatatypesList(MUI::ListBuilder().tagFrame(MUI::Frame::ReadList).stringHooks().object())
      , mLoadedMUIList(MUI::ListBuilder().tagFrame(MUI::Frame::ReadList).stringHooks().object())
      , mLoadedResourcesList(MUI::ListBuilder().tagFrame(MUI::Frame::ReadList).stringHooks().object())
      , mLoadedOtherList(MUI::ListBuilder().tagFrame(MUI::Frame::ReadList).stringHooks().object())
      , mExecNodesTabs({
            { "Libraries", mLoadedLibrariesList },
            { "Devices", mLoadedDevicesList },
            { "Datatypes", mLoadedDatatypesList },
            { "MUI", mLoadedMUIList },
            { "Resources", mLoadedResourcesList },
            { "Other", mLoadedOtherList },
        })
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::GroupBuilder()
                                     .tagFrame(MUI::Frame::Group)
                                     .tagFrameTitle("Operating System")
                                     //  .tagChild(LabelText(MUIX_R "Name"))
                                     .tagChild(mFullOSNameText)
                                     .tagChild(MUI::GroupBuilder()
                                                   .tagColumns(8)
                                                   .tagChild(LabelText(MUIX_R "Kickstart:"))
                                                   .tagChild(mKickstartVersionText)
                                                   .tagChild(LabelText(MUIX_R "Exec:"))
                                                   .tagChild(mExecVersionText)
                                                   .tagChild(LabelText(MUIX_R "Ambient:"))
                                                   .tagChild(mAmbientVersionText)
                                                   .tagChild(LabelText(MUIX_R "Workbench:"))
                                                   .tagChild(mWorkbenchVersionText)
                                                   .tagChild(LabelText(MUIX_R "User:"))
                                                   .tagChild(mUserText)
                                                   .tagChild(LabelText(MUIX_R "Time Zone:"))
                                                   .tagChild(mTimeZoneText)
                                                   .tagChild(LabelText(MUIX_R "Locale:"))
                                                   .tagChild(mLocaleText)
                                                   .tagChild(LabelText(MUIX_R "Code Page:"))
                                                   .tagChild(mCodePageText)
                                                   .object())
                                     .object())
                       .tagChild(MUI::MakeObject::CLabel("Loaded Exec Nodes"))
                       .tagChild(mExecNodesTabs)
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

        if (AppContext::instance().getRexxsyslibBase().isOpen())
        {
            try
            {
                AOS::Rexxsyslib::RexxMsgScope replayRexxMsgScope;
                AOS::Rexxsyslib::ArgstringScope argstringScope("version");

                // TODO refactor to oop style
                auto rxmsg = replayRexxMsgScope.rexxMsg();
                rxmsg->rm_Action = RXCOMM | RXFF_RESULT;
                rxmsg->rm_Args[0] = argstringScope.argstring();
                if (AOS::Rexxsyslib::Library::libFillRexxMsg(*rxmsg, 1, 0))
                {
                    if (auto ambientArexxPort = AOS::Exec::Library::libFindPort("AMBIENT"))
                    {
                        AOS::Exec::Library::libPutMsg(*ambientArexxPort, *((struct Message *)rxmsg));
                        AOS::Exec::Library::libWaitPort(*replayRexxMsgScope.msgPort());
                        auto result = AOS::Rexxsyslib::Library::GetRexxMsg(replayRexxMsgScope);
                        if (result && result->rm_Result1 == 0 && result->rm_Result2)
                        {
                            mAmbientVersionText.setContents((const char *)result->rm_Result2);
                            AOS::Rexxsyslib::Library::libDeleteArgstring((unsigned char *)result->rm_Result2);
                        }
                    }

                    AOS::Rexxsyslib::Library::libClearRexxMsg(*rxmsg, 1);
                }
            }
            catch (const std::exception &e)
            {
                // ignore
            }
        }

        auto workbench = AOS::Dos::Library::libGetVar("Workbench");
        mWorkbenchVersionText.setContents(workbench.has_value() ? "v" + StringUtils::Split(workbench.value()).back() : "??");

        auto user = AOS::Dos::Library::libGetVar("USER");
        mUserText.setContents(user.has_value() ? user.value() : "??");
        auto timezone = AOS::Dos::Library::libGetVar("TZ");
        mTimeZoneText.setContents(timezone.has_value() ? timezone.value() : "??");
        auto codepage = AOS::Dos::Library::libGetVar("CODEPAGE");
        mCodePageText.setContents(codepage.has_value() ? codepage.value() : "??");
        auto locale = AOS::Dos::Library::libGetVar("Language");
        mLocaleText.setContents(locale.has_value() ? locale.value() : "??");

        mExecVersionText.setContents("v" + AOS::Exec::Library::GetVersion());

        auto isLibrary = [](const AOS::Exec::NodeInfo &node) -> bool { return StringUtils::hasSuffix(node.name, ".library"); };
        auto isDatatype = [](const AOS::Exec::NodeInfo &node) -> bool {
            return StringUtils::hasSuffix(node.name, { ".datatype", ".decoder", ".encoder" });
        };
        auto isMUI = [](const AOS::Exec::NodeInfo &node) -> bool { return StringUtils::hasSuffix(node.name, { ".mui", ".mcc" }); };

        mLoadedLibrariesList.setQuiet(true);
        mLoadedDatatypesList.setQuiet(true);
        mLoadedMUIList.setQuiet(true);
        mLoadedOtherList.setQuiet(true);

        auto allLibraries = AOS::Exec::Library::GetAllLibraryNodeNames();
        for (const auto &entry : allLibraries)
        {
            if (isLibrary(entry))
                mLoadedLibrariesList.InsertSingleSorted(entry.name + " (v" + entry.version.value_or("??") + ")");
            else if (isDatatype(entry))
                mLoadedDatatypesList.InsertSingleSorted(entry.name + " (v" + entry.version.value_or("??") + ")");
            else if (isMUI(entry))
                mLoadedMUIList.InsertSingleSorted(entry.name + " (v" + entry.version.value_or("??") + ")");
            else
                mLoadedOtherList.InsertSingleSorted(entry.name + " (v" + entry.version.value_or("??") + ")");
        }

        mLoadedLibrariesList.setQuiet(false);
        mLoadedDatatypesList.setQuiet(false);
        mLoadedMUIList.setQuiet(false);
        mLoadedOtherList.setQuiet(false);

        auto allDevices = AOS::Exec::Library::GetAllDeviceNodeNames();
        mLoadedDevicesList.InsertSorted([&]() -> std::vector<std::string> {
            std::vector<std::string> result;
            for (const auto &entry : allDevices)
                result.push_back(entry.name + " (v" + entry.version.value_or("??") + ")");
            return result;
        }());

        auto allResources = AOS::Exec::Library::GetAllResourceNodeNames();
        mLoadedResourcesList.InsertSorted([&]() -> std::vector<std::string> {
            std::vector<std::string> result;
            for (const auto &entry : allResources)
                result.push_back(entry.name);
            return result;
        }());
    }
}
