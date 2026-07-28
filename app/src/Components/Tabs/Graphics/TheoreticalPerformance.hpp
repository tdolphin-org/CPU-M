//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Base.hpp"
#include "Components/Core/Root.hpp"
#include "DataInfo/GfxCardSpec.hpp"

#include "MUI/Group.hpp"

#include <optional>

namespace Components
{
    class TheoreticalPerformance : public Root<MUI::Group>, public Base
    {
        MUI::Group mComponent;

      public:
        explicit TheoreticalPerformance(const std::optional<DataInfo::TheoreticalPerformance> &theoreticalPerformance);

      protected:
        MUI::Group &muiRoot() const override
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
