//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "Components/Tabs/TabBase.hpp"
#include "DataInfo/GfxBoardSpec.hpp"

#include "MUI/Group.hpp"

#include <optional>

namespace Components
{
    class Theoretical3DPerformance : public Root<MUI::Group>, public TabBase
    {
        MUI::Group mComponent;

      public:
        Theoretical3DPerformance(const std::optional<DataInfo::Theoretical3DPerformance> &theoretical3DPerformance);

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
