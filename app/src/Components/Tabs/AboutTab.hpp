//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Buttons/GoUrlButton.hpp"
#include "Components/Core/Root.hpp"
#include "TabBase.hpp"

#include "MUI/Group.hpp"

namespace Components
{
    class AboutTab : public Root<MUI::Group>, public TabBase
    {
        GoUrlButton mGoHomePageButton;
        GoUrlButton mMailToButton;
        GoUrlButton mGoGitRepositoryButton;
        GoUrlButton mGoYouTubeChannelButton;

        MUI::Group mComponent;

      public:
        AboutTab();

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
