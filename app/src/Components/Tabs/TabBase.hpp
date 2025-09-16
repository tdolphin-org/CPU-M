//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "MUI/Text.hpp"

namespace Components
{
    class TabBase
    {
      public:
        MUI::Text LabelText(const std::string &label, const short weight = 0);
        MUI::Text ValueText(const std::string &help, const std::string &defaultValue = "--", const bool shorten = false,
                            const short weight = 100);
    };
}
