//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "BusInterfaceNames.hpp"

namespace Components
{
    BusInterfaceNames::BusInterfaceNames(const std::string &interfaces)
      : mBusInterfaceNamesText(MUI::TextBuilder().tagShortHelp("Graphics card interface(s)").tagContents(interfaces).object())
      , mBusInterfaceSpecButton()
      , mComponent(MUI::GroupBuilder()
                       .horizontal()
                       .tagFrame(MUI::Frame::Text)
                       .tagChild(mBusInterfaceNamesText)
                       .tagChild(mBusInterfaceSpecButton)
                       .object())
    {
    }
}