//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "BoardsList.hpp"

#include "AOS/PCIIDS/Library.hpp"

#include <iomanip>
#include <sstream>

namespace Components
{
    BoardsList::BoardsList(const std::vector<AOS::PCIX::Board> &boards)
      : mComponent(MUI::ListBuilder().tagFrame(MUI::Frame::ReadList).tagConstructHookString().tagDestructHookString().object()) 
    {
        mComponent.InsertSingleBottom(std::string("Vendor & Device"));

        for (auto &board : boards)
        {
            std::stringstream vendorIdStream, deviceIdStream;
            vendorIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << board.vendorId;
            deviceIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << board.deviceId;

            mComponent.InsertSingleBottom(std::string("[") + vendorIdStream.str() + "] " + AOS::PCIIDS::Library::libGetVendorName(board.vendorId) + "[" + deviceIdStream.str() + "] " + AOS::PCIIDS::Library::libGetDeviceName(board.vendorId, board.deviceId));
        }
    }
}
