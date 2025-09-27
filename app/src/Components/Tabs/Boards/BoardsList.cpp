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
      : mComponent(MUI::ListBuilder().tagTitle(true).tagFormat("BAR,").tagFrame(MUI::Frame::ReadList).tagConstructHookString().tagDestructHookString().object()) 
    {
        mComponent.InsertSingleBottom(std::string("Vendor & Device & Class"));

        for (auto &board : boards)
        {
            std::stringstream vendorIdStream, deviceIdStream, classIdStream;;
            vendorIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << board.vendorId;
            deviceIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << board.deviceId;
            classIdStream << "0x" << std::setfill('0') << std::setw(2) << std::hex << board.classId;

            mComponent.InsertSingleBottom(std::string(MUIX_B "[") + vendorIdStream.str() + "] " MUIX_N + AOS::PCIIDS::Library::libGetVendorName(board.vendorId) + MUIX_B " [" + deviceIdStream.str() + "] " MUIX_N + AOS::PCIIDS::Library::libGetDeviceName(board.vendorId, board.deviceId) + MUIX_B " [" + classIdStream.str() + "] " MUIX_N + AOS::PCIIDS::Library::libGetClassName(board.classId) );
        }
    }
}
