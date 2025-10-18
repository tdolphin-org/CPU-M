//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "TabBase.hpp"

namespace Components
{
    MUI::Text TabBase::LabelText(const std::string &label, const short weight)
    {
        return MUI::TextBuilder().tagContents(label).tagFrame(MUI::Frame::String).tagFramePhantomHoriz(true).tagWeight(weight).object();
    }

    MUI::Text TabBase::ValueText(const std::string &help, const std::string &defaultValue, const bool shorten, const short weight)
    {
        return MUI::TextBuilder()
            .tagFrame(MUI::Frame::String)
            .tagContents(defaultValue)
            .tagShortHelp(help)
            .tagShorten(shorten ? MUI::Text_Shorten::Cutoff : MUI::Text_Shorten::Nothing)
            .tagSetMin(!shorten)
            .tagWeight(weight)
            .object();
    }
}
