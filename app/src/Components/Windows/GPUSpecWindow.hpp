//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "Components/Core/Root.hpp"

#include "DataInfo/GPUSpec.hpp"
#include "MUI/Group.hpp"
#include "MUI/Text.hpp"
#include "MUI/Window.hpp"

namespace Components
{
    class GPUSpecWindow : public Root<MUI::Window>
    {
        Object *mLogoImage { nullptr };
        Object *mRenderConfig { nullptr };

        MUI::Text mManufacturer;
        MUI::Text mModelName;
        MUI::Text mPremiere;
        MUI::Text mArchitecture;
        MUI::Text mTechnology;
        MUI::Text mMaxTDP;
        MUI::Text mWarningsText;
        MUI::Group mWithLogoGroup;
        MUI::Group mChipSpecGroup;

        MUI::Window mComponent;

      public:
        GPUSpecWindow();

        void Open(const DataInfo::GPUID gpuId);
        void Close();

      protected:
        MUI::Window &muiRoot() const
        {
            return const_cast<MUI::Window &>(mComponent);
        }

      private:
        Object *CreateImage(const DataInfo::ManufacturerID manufacturerId);
    };
}
