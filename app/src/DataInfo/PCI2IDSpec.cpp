//
//  CPU-M
//
//  (c) 2025-2026 TDolphin
//

#include "PCI2IDSpec.hpp"

#include "FileResources/Specs.hpp"
#include "GfxCardTypes.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace DataInfo
{
    // Helper function to trim whitespace from both ends of a string
    static std::string trim(const std::string &str)
    {
        size_t start = str.find_first_not_of(" \t\r\n");
        if (start == std::string::npos)
            return "";
        size_t end = str.find_last_not_of(" \t\r\n");
        return str.substr(start, end - start + 1);
    }

    PCI2IDSpecCore::PCI2IDSpecCore()
    {
        // Load data from CSV file
        std::ifstream file(SpecsFile::pciid_graphics_cards_csv_file);
        if (!file.is_open())
        {
            // File not found or cannot be opened - fall back to empty data
            std::cerr << __PRETTY_FUNCTION__
                      << ": Unable to open PCI ID graphics cards CSV file: " << SpecsFile::pciid_graphics_cards_csv_file << std::endl;
            return;
        }

        std::string line;
        // Skip header line
        std::getline(file, line);

        // Read data lines
        while (std::getline(file, line))
        {
            if (line.empty())
                continue;

            std::stringstream ss(line);
            std::string vendorIdStr, deviceIdStr, subsysVendorIdStr, subsysDeviceIdStr, cardName;

            // Parse CSV fields
            std::getline(ss, vendorIdStr, ',');
            std::getline(ss, deviceIdStr, ',');
            std::getline(ss, subsysVendorIdStr, ',');
            std::getline(ss, subsysDeviceIdStr, ',');
            std::getline(ss, cardName);

            // Trim whitespace from all fields
            cardName = trim(cardName);
            vendorIdStr = trim(vendorIdStr);
            deviceIdStr = trim(deviceIdStr);
            subsysVendorIdStr = trim(subsysVendorIdStr);
            subsysDeviceIdStr = trim(subsysDeviceIdStr);

            if (cardName.empty())
                continue;

            // Convert hex strings to integers
            uint16_t vendorId = static_cast<uint16_t>(std::stoul(vendorIdStr, nullptr, 16));
            uint16_t deviceId = static_cast<uint16_t>(std::stoul(deviceIdStr, nullptr, 16));

            // Convert card name string to GfxCardID
            auto gfxCardIdOpt = StringToGfxCardID(cardName);
            if (!gfxCardIdOpt.has_value())
                continue; // Skip if card name is not recognized

            // Create PCI device key
            PCIDeviceKey key = (subsysVendorIdStr.empty() || subsysDeviceIdStr.empty())
                ? PCIDeviceKey(vendorId, deviceId)
                : PCIDeviceKey(vendorId, deviceId, static_cast<uint16_t>(std::stoul(subsysVendorIdStr, nullptr, 16)),
                               static_cast<uint16_t>(std::stoul(subsysDeviceIdStr, nullptr, 16)));

            // Create value
            PCIDeviceValue value { gfxCardIdOpt.value() };

            // Add to map (or append to existing entry)
            vendorAndDevice2gfxBoardId[key].push_back(value);
        }

        file.close();
    }

    std::optional<std::vector<PCIDeviceValue>> PCI2IDSpecCore::Find(PCIDeviceKey pciKey)
    {
        auto it = vendorAndDevice2gfxBoardId.find(pciKey);
        if (it != vendorAndDevice2gfxBoardId.end())
            return it->second;

        return std::nullopt;
    }
}