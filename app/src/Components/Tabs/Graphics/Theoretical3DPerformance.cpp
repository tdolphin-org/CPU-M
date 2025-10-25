//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "Theoretical3DPerformance.hpp"

#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    Theoretical3DPerformance::Theoretical3DPerformance(const std::optional<DataInfo::Theoretical3DPerformance> &theoretical3DPerformance)
      : mComponent(MUI::GroupBuilder().tagFrame(MUI::Frame::Group).tagFrameTitle("Theoretical Performance").object())
    {
        if (theoretical3DPerformance.has_value())
        {
            mComponent.setColumns(2);
            mComponent.AddMember(LabelText("Pixel Rate:"))
                .AddMember(MUI::TextBuilder()
                               .tagFrame(MUI::Frame::String)
                               .tagContents(DataInfo::PerformancePixelRateToString(theoretical3DPerformance.value().pixelRate))
                               .object())
                .AddMember(LabelText("Vertex Rate:"))
                .AddMember(MUI::TextBuilder()
                               .tagFrame(MUI::Frame::String)
                               .tagContents(DataInfo::PerformanceVertexRateToString(theoretical3DPerformance.value().vertexRate))
                               .object())
                .AddMember(LabelText("Texture Rate:"))
                .AddMember(MUI::TextBuilder()
                               .tagFrame(MUI::Frame::String)
                               .tagContents(DataInfo::PerformanceTextureRateToString(theoretical3DPerformance.value().textureRate))
                               .object());
        }
        else
        {
            mComponent.AddMember(MUI::MakeObject::HVSpace())
                .AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("N/A")))
                .AddMember(MUI::MakeObject::HVSpace());
        }
    }
}