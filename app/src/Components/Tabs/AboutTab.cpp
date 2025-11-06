//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "AboutTab.hpp"

#include "MUI/Core/MakeObject.hpp"
#include "MUI/Image.hpp"
#include "ProgDefines.hpp"
#include "TextResources/Labels.hpp"

namespace Components
{
    AboutTab::AboutTab()
      : mGoHomePageButton(MUIX_C MUIX_PH TDOLPHIN_WEBPAGE, TDOLPHIN_WEBPAGE, TDOLPHIN_WEBPAGE, 0)
      , mMailToButton(MUIX_C MUIX_PH TDOLPHIN_EMAIL, "mailto:" TDOLPHIN_EMAIL, "mailto:" TDOLPHIN_EMAIL, 0)
      , mGoGitRepositoryButton(MUIX_C MUIX_PH GIT_REPOSITORY_URL, GIT_REPOSITORY_URL, GIT_REPOSITORY_URL, 0)
      , mGoYouTubeChannelButton(MUIX_C MUIX_PH YOUTUBE_CHANNEL_URL, YOUTUBE_CHANNEL_URL, YOUTUBE_CHANNEL_URL, 0)
      , mComponent(MUI::GroupBuilder()
                       .horizontal()
                       .tagChild(MUI::GroupBuilder()
                                     .vertical()
                                     .tagChild(MUI::MakeObject::HVSpace())
                                     .tagChild(MUI::MakeObject::HCenter(MUI::ImageBuilder()
                                                                            .tagSpecPicture("PROGDIR:images/applogo.128x128.png")
                                                                            .tagFixWidth(128)
                                                                            .tagFixHeight(128)
                                                                            .tagFreeHoriz(true)
                                                                            .tagFreeVert(true)
                                                                            .object()))
                                     .tagChild(MUI::MakeObject::HVSpace())
                                     .tagChild(MUI::TextBuilder().tagContents(Label::AboutContent).object())
                                     .tagChild(MUI::MakeObject::HVSpace())
                                     .object())
                       .tagChild(MUI::MakeObject::VBar(10))
                       .tagChild(MUI::GroupBuilder()
                                     .vertical()
                                     .tagChild(MUI::MakeObject::HVSpace())
                                     .tagChild(MUI::MakeObject::HCenter(mGoHomePageButton))
                                     .tagChild(MUI::MakeObject::HCenter(mMailToButton))
                                     .tagChild(MUI::MakeObject::HCenter(mGoGitRepositoryButton))
                                     .tagChild(MUI::MakeObject::HCenter(mGoYouTubeChannelButton))
                                     .tagChild(MUI::MakeObject::HVSpace())
                                     .object())
                       .object())
    {
    }
}
