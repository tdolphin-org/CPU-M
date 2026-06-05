//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "BoardsList.hpp"

#include "AOS/PCIIDS/Library.hpp"
#include "WindowManager.hpp"

#include "amiga_std_light/sstream.hpp"
#include <iomanip>

namespace Components
{
    const char *titles[] = { "[ID] Vendor", "[ID] Device", "Class", "Subsystem ID", nullptr };

    BoardsList::BoardsList(const std::vector<AOS::PCIX::Board> &boards)
      : mComponent(MCC::ActionListBuilder()
                       .stringArrayHooks(4)
                       .tagFormat("BAR MINWIDTH=0,BAR MINWIDTH=0,BAR MINWIDTH=0,")
                       .tagTitleArray(titles)
                       .tagTitle(true)
                       .tagFrame(MUI::Frame::Group)
                       .object(*this))
    {
        for (auto &board : boards)
        {
            amiga_std_light::stringstream vendorIdStream, deviceIdStream, classIdStream, subsystem;
            vendorIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << board.vendorId;
            deviceIdStream << "0x" << std::setfill('0') << std::setw(4) << std::hex << board.deviceId;
            classIdStream << "0x" << std::setfill('0') << std::setw(2) << std::hex << board.classId;

            if (board.subsystemVendorId != 0)
                subsystem << std::setfill('0') << std::setw(4) << std::hex << board.subsystemVendorId;
            if (board.subsystemId != 0)
                subsystem << ":" << std::setfill('0') << std::setw(4) << std::hex << board.subsystemId;
            if (board.subclassId != 0)
            {
                std::string clazz { AOS::PCIIDS::Library::libGetClassName(board.subclassId) };
                classIdStream << " - " << clazz;
            }

            std::string vendor { MUIX_B "[" + vendorIdStream.str() + "] " MUIX_N + AOS::PCIIDS::Library::libGetVendorName(board.vendorId) };
            std::string device { MUIX_B " [" + deviceIdStream.str() + "] " MUIX_N
                                 + AOS::PCIIDS::Library::libGetDeviceName(board.vendorId, board.deviceId) };
            std::string clazz { AOS::PCIIDS::Library::libGetClassName(board.classId) };

            const char *arr[] = { vendor.c_str(), device.c_str(), clazz.c_str(), subsystem.str().c_str(), nullptr };
            mComponent.InsertSingleBottom(arr);

            mBoards.emplace_back(board, BoardInfo { vendor, device, clazz });
        }
    }

    unsigned long BoardsList::OnActiveEntry()
    {
        auto activeEntry = mComponent.getActive();
        if (activeEntry < 0)
            return 0;

        if (!WindowManager::instance().getBoardAttributesWindow().isOpen())
            return 0;

        // when board attributes window is open, than activate entry also show  attributes of the active board
        OpenBoardAttributes(activeEntry);

        return 0;
    }

    unsigned long BoardsList::OnDoubleClickEntry()
    {
        auto activeEntry = mComponent.getActive();
        if (activeEntry < 0)
            return 0;

        // when entry is double clicked, than open board attributes window (or bring it to front if already open) and show attributes of the
        // active board
        OpenBoardAttributes(activeEntry);

        return 0;
    }

    void BoardsList::OpenBoardAttributes(const long activeEntry)
    {
        auto boardAttributesOpt = AOS::PCIX::Library::GetBoardAttributes(mBoards[activeEntry].first);
        if (boardAttributesOpt.has_value())
            WindowManager::instance().getBoardAttributesWindow().Open(mBoards[activeEntry].second.vendor,
                                                                      mBoards[activeEntry].second.device,
                                                                      mBoards[activeEntry].second.className, boardAttributesOpt.value());
    }
}
