//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "RenderConfig.hpp"

#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    RenderConfig::RenderConfig(const DataInfo::RenderConfig &renderConfig)
      : mUnitsGroup(
            MUI::GroupBuilder().tagFrame(MUI::Frame::Group).tagFrameTitle("Render Config specification").vertical().tagColumns(2).object())
      , mComponent(MUI::GroupBuilder()
                       .vertical()
                       .tagChild(MUI::MakeObject::HVSpace())
                       .tagChild(mUnitsGroup)
                       .tagChild(MUI::MakeObject::HVSpace())
                       .object())
    {
        if (renderConfig.shadingUnits.has_value())
        {
            mUnitsGroup.AddTail(LabelText(MUIX_R "Render Config Specification"));
            mUnitsGroup.AddTail(
                ValueText("Number of shading units supported by the GPU.", std::to_string(renderConfig.shadingUnits.value()), false, 0));
        }
        if (renderConfig.pixelShaders.has_value())
        {
            mUnitsGroup.AddTail(LabelText(MUIX_R "Pixel Shaders:"));
            mUnitsGroup.AddTail(
                ValueText("Number of pixel shaders supported by the GPU.", std::to_string(renderConfig.pixelShaders.value()), false, 0));
        }
        if (renderConfig.vertexShaders.has_value())
        {
            mUnitsGroup.AddTail(LabelText(MUIX_R "Vertex Shaders:"));
            mUnitsGroup.AddTail(
                ValueText("Number of vertex shaders supported by the GPU.", std::to_string(renderConfig.vertexShaders.value()), false, 0));
        }
        mUnitsGroup.AddTail(LabelText(MUIX_R "Texture Mapping Units:"));
        mUnitsGroup.AddTail(
            ValueText("Number of texture mapping units (TMUs) supported by the GPU.", std::to_string(renderConfig.TMUs), false, 0));
        mUnitsGroup.AddTail(LabelText(MUIX_R "Render Output Units:"));
        mUnitsGroup.AddTail(
            ValueText("Number of render output units (ROPs) supported by the GPU.", std::to_string(renderConfig.ROPs), false, 0));
        if (renderConfig.computeUnits.has_value())
        {
            mUnitsGroup.AddTail(LabelText(MUIX_R "Compute Units:"));
            mUnitsGroup.AddTail(
                ValueText("Number of compute units supported by the GPU.", std::to_string(renderConfig.computeUnits.value()), false, 0));
        }
    }
}
