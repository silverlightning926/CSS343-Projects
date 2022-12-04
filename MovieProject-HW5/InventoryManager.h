//
// Created by siddr on 12/1/2022.
//

#ifndef MOVIESP5_INVENTORYMANAGER_H
#define MOVIESP5_INVENTORYMANAGER_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include "Customer.h"

class InventoryManager {
public:
    InventoryManager() = default;

    InventoryManager(const InventoryManager &other) = delete;
    InventoryManager(InventoryManager &&other) = delete;

    InventoryManager &operator=(const InventoryManager &other) = delete;
    InventoryManager &operator=(InventoryManager &&other) = delete;

    void readFile(const std::string& filePath);

private:
    std::unordered_map<std::string, Customer> customers_;

    std::vector<Comedy> comedyInventory_;
    std::vector<Drama> dramaInventory_;
    std::vector<Classic> classicInventory_;

    void newMovie(std::vector<std::string> parsedCommand);
    void newCustomer(std::vector<std::string> parsedCommand);

    void newCommand(const std::string& command);

    static std::vector<std::string> splitString(const std::string &delimiter, const std::string& referenceLine) ;
};


#endif //MOVIESP5_INVENTORYMANAGER_H
