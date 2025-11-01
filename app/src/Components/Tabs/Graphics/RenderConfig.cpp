//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "RenderConfig.hpp"

namespace Components
{
    RenderConfig::RenderConfig(const DataInfo::RenderConfig &renderConfig)
      : mComponent(
            MUI::GroupBuilder().tagFrame(MUI::Frame::Group).tagFrameTitle("Render Config specific").vertical().tagColumns(2).object())
    {
        if (renderConfig.shadingUnits.has_value())
        {
            mComponent.AddTail(LabelAndValueText("Shading Units:", std::to_string(renderConfig.shadingUnits.value()),
                                                 "Number of shading units supported by the GPU."));
        }
        if (renderConfig.pixelShaders.has_value())
        {
            mComponent.AddTail(LabelAndValueText("Pixel Shaders:", std::to_string(renderConfig.pixelShaders.value()),
                                                 "Number of pixel shaders supported by the GPU."));
        }
        if (renderConfig.vertexShaders.has_value())
        {
            mComponent.AddTail(LabelAndValueText("Vertex Shaders:", std::to_string(renderConfig.vertexShaders.value()),
                                                 "Number of vertex shaders supported by the GPU."));
        }
        mComponent.AddTail(LabelAndValueText("Texture Mapping Units (TMUs):", std::to_string(renderConfig.MTUs),
                                             "Number of texture mapping units supported by the GPU."));
        mComponent.AddTail(LabelAndValueText("Render Output Units (ROPs):", std::to_string(renderConfig.ROPs),
                                             "Number of render output units supported by the GPU."));
        if (renderConfig.computeUnits.has_value())
        {
            mComponent.AddTail(LabelAndValueText("Compute Units:", std::to_string(renderConfig.computeUnits.value()),
                                                 "Number of compute units supported by the GPU."));
        }
    }
}
