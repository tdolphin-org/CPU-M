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
    const char *titles[4] = { "[ID] Vendor", "[ID] Device", "Class", "Subsystem ID" };

    BoardsList::BoardsList(const std::vector<AOS::PCIX::Board> &boards)
      : mComponent(MUI::ListBuilder()
                       .stringArrayHooks(4)
                       .tagFormat("BAR MINWIDTH=0,BAR MINWIDTH=0,BAR MINWIDTH=0,")
                       .tagTitleArray(titles)
                       .tagTitle(true)
                       .tagFrame(MUI::Frame::Group)
                       .object())
    {
        for (auto &board : boards)
        {
            std::stringstream vendorIdStream, deviceIdStream, classIdStream, subsystem;
            vendorIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << board.vendorId;
            deviceIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << board.deviceId;
            classIdStream << "0x" << std::setfill('0') << std::setw(2) << std::hex << board.classId;

            if (board.subsystemId.has_value())
                subsystem << std::setfill('0') << std::setw(4) << std::hex << board.subsystemVendorId.value();
            if (board.subsystemVendorId.has_value())
                subsystem << ":" << std::setfill('0') << std::setw(4) << std::hex << board.subsystemId.value();
            if (board.subclassId.has_value())
            {
                std::string clazz { AOS::PCIIDS::Library::libGetClassName(board.subclassId.value()) };
                classIdStream << " - " << clazz;
            }

            std::string vendor { MUIX_B "[" + vendorIdStream.str() + "] " MUIX_N + AOS::PCIIDS::Library::libGetVendorName(board.vendorId) };
            std::string device { MUIX_B " [" + deviceIdStream.str() + "] " MUIX_N
                                 + AOS::PCIIDS::Library::libGetDeviceName(board.vendorId, board.deviceId) };
            std::string clazz { AOS::PCIIDS::Library::libGetClassName(board.classId) };

            const char *arr[] = { vendor.c_str(), device.c_str(), clazz.c_str(), subsystem.str().c_str(), nullptr };
            mComponent.InsertSingleBottom(arr);
        }
    }
}
