//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "Components/Core/Root.hpp"

#include "DataInfo/MemorySpec.hpp"
#include "MUI/Group.hpp"
#include "MUI/Text.hpp"
#include "MUI/Window.hpp"

namespace Components
{
    class MemoryModuleSpecWindow : public Root<MUI::Window>
    {
        Object *mModuleImage { nullptr };

        MUI::Text mTypeText;
        MUI::Text mModuleFormText;
        MUI::Text mGenerationText;
        MUI::Text mIntroductionYearText;
        MUI::Text mDataTransferMTsText;
        MUI::Text mBandwidthMBsText;
        MUI::Text mClockText;
        MUI::Text mWidthText; // in millimeters
        MUI::Text mPinsCountText; // number of pins
        MUI::Text mVoltageText;
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

      private:
        Object *CreateImage(const MemoryGeneration memoryGeneration, const ModuleForm memoryTypeAndForm);
    };
}
