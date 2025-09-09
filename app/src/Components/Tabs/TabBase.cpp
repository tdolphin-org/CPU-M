//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "TabBase.hpp"

namespace Components
{
    MUI::Text TabBase::LabelText(const std::string &label)
    {
        return MUI::TextBuilder().tagContents(label).tagFrame(MUI::Frame::String).tagPhantomHoriz(true).tagWeight(0).object();
    }

    MUI::Text TabBase::ValueText(const std::string &help, const std::string &defaultValue, bool shorten)
    {
        return MUI::TextBuilder()
            .tagFrame(MUI::Frame::String)
            .tagContents(defaultValue)
            .tagShortHelp(help)
            .tagShorten(shorten ? MUI::Text_Shorten::Cutoff : MUI::Text_Shorten::Nothing)
            .tagSetMin(!shorten)
            .object();
    }
}
