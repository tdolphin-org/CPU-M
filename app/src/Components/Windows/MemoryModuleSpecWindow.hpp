//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "Components/Core/Root.hpp"

#include "DataInfo/MemorySpec.hpp"
#include "MUI/Group.hpp"
#include "MUI/Image.hpp"
#include "MUI/Text.hpp"
#include "MUI/Window.hpp"

namespace Components
{
    class MemoryModuleSpecWindow : public Root<MUI::Window>
    {
        MUI::Image mModuleImage;
        MUI::Text mTypeText;
        MUI::Text mModuleFormText;
        MUI::Text mGenerationText;
        MUI::Text mVoltageText;
        MUI::Text mDataTransferMTsText;
        MUI::Text mBandwidthMBsText;
        MUI::Text mClockText;
        MUI::Text mNotesText;

        MUI::Group mModuleSpecGroup;

        MUI::Window mComponent;

      public:
        MemoryModuleSpecWindow();

        void Open(const std::pair<MemoryType, ModuleForm> &memoryTypeAndForm);
        void Close();

      protected:
        MUI::Window &muiRoot() const
        {
            return const_cast<MUI::Window &>(mComponent);
        }
    };
}
