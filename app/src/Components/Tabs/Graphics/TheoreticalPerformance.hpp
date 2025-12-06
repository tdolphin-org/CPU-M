//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Base.hpp"
#include "Components/Core/Root.hpp"
#include "DataInfo/GfxBoardSpec.hpp"

#include "MUI/Group.hpp"

#include <optional>

namespace Components
{
    class TheoreticalPerformance : public Root<MUI::Group>, public Base
    {
        MUI::Group mComponent;

      public:
        TheoreticalPerformance(const std::optional<DataInfo::TheoreticalPerformance> &theoreticalPerformance);

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
