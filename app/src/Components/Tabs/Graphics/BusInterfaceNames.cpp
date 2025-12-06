//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "BusInterfaceNames.hpp"

namespace Components
{
    BusInterfaceNames::BusInterfaceNames(const std::string &interfaces)
      : mBusInterfaceNamesText(MUI::TextBuilder().tagShortHelp("Graphics board interface(s)").tagContents(interfaces).object())
      , mBusInterfaceSpecButton()
      , mComponent(MUI::GroupBuilder()
                       .horizontal()
                       .tagFrame(MUI::Frame::String)
                       .tagChild(mBusInterfaceNamesText)
                       .tagChild(mBusInterfaceSpecButton)
                       .object())
    {
    }
}