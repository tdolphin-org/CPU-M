//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "TheoreticalPerformance.hpp"

#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    TheoreticalPerformance::TheoreticalPerformance(const std::optional<DataInfo::TheoreticalPerformance> &theoreticalPerformance)
      : mComponent(MUI::GroupBuilder().tagFrame(MUI::Frame::Group).tagFrameTitle("Theoretical Performance").tagWeight(50).object())
    {
        if (theoreticalPerformance.has_value())
        {
            mComponent.setColumns(2);
            mComponent.AddMember(LabelText(MUIX_R "Pixel Fillrate:"))
                .AddMember(MUI::TextBuilder()
                               .tagFrame(MUI::Frame::Text)
                               .tagContents(DataInfo::PerformancePixelRateToString(theoreticalPerformance.value().pixelRate))
                               .object());
            if (theoreticalPerformance.value().vertexRate.has_value())
            {
                mComponent.AddMember(LabelText(MUIX_R "Vertex Fillrate:"))
                    .AddMember(MUI::TextBuilder()
                                   .tagFrame(MUI::Frame::Text)
                                   .tagContents(DataInfo::PerformanceVertexRateToString(theoreticalPerformance.value().vertexRate.value()))
                                   .object());
            }
            mComponent.AddMember(LabelText(MUIX_R "Texture Fillrate:"))
                .AddMember(MUI::TextBuilder()
                               .tagFrame(MUI::Frame::Text)
                               .tagContents(DataInfo::PerformanceTextureRateToString(theoreticalPerformance.value().textureRate))
                               .object());
            if (theoreticalPerformance.value().FP32.has_value())
            {
                mComponent.AddMember(LabelText(MUIX_R "FP32 (float):"))
                    .AddMember(MUI::TextBuilder()
                                   .tagFrame(MUI::Frame::Text)
                                   .tagContents(DataInfo::PerformanceFP32RateToString(theoreticalPerformance.value().FP32.value()))
                                   .object());
            }
            if (theoreticalPerformance.value().FP64.has_value())
            {
                mComponent.AddMember(LabelText(MUIX_R "FP64 (double):"))
                    .AddMember(MUI::TextBuilder()
                                   .tagFrame(MUI::Frame::Text)
                                   .tagContents(DataInfo::PerformanceFP64RateToString(theoreticalPerformance.value().FP64.value()))
                                   .object());
            }
        }
        else
        {
            mComponent.AddMember(MUI::MakeObject::HVSpace())
                .AddMember(MUI::MakeObject::HCenter(MUI::MakeObject::FreeLabel("N/A")))
                .AddMember(MUI::MakeObject::HVSpace());
        }
    }
}