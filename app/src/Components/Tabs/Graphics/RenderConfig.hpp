//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"

#include "Components/Tabs/TabBase.hpp"
#include "DataInfo/GPUSpec.hpp"
#include "MUI/Group.hpp"

namespace Components
{
    class RenderConfig : public Root<MUI::Group>, public TabBase
    {
        MUI::Group mUnitsGroup;
        MUI::Group mComponent;

      public:
        RenderConfig(const DataInfo::RenderConfig &renderConfig);

      protected:
        MUI::Group &muiRoot() const
        {
            return const_cast<MUI::Group &>(mComponent);
        }
    };
}
