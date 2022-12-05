//
// Created by siddr on 12/1/2022.
//

#include "InventoryManager.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void InventoryManager::readFile(const std::string &filePath) {

  std::ifstream file(filePath);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      if (line[0] == 'F' || line[0] == 'D' || line[0] == 'C') {
        std::vector<std::string> const parsed_line = splitString(", ", line);
        newMovie(parsed_line);
      }

      else if (std::isdigit(line[0])) {
        std::vector<std::string> const parsed_line = splitString(" ", line);
        newCustomer(parsed_line);
      }

      else if (line[0] == 'I' || line[0] == 'H' || line[0] == 'B' ||
               line[0] == 'R') {
        newCommand(line);
      }
    }
    file.close();
  } else
    std::cerr << "Could not open file: " << filePath << std::endl;
}

std::vector<std::string>
InventoryManager::splitString(const std::string &delimiter,
                              const std::string &referenceLine) {
  std::string token;
  std::vector<std::string> parsed_line;
  std::string line = referenceLine;

  while (line.find(delimiter) != std::string::npos) {
    token = line.substr(0, line.find(delimiter));
    parsed_line.push_back(token);
    line.erase(0, line.find(delimiter) + delimiter.length());
  }

  parsed_line.push_back(line);
  return parsed_line;
}

void InventoryManager::newMovie(std::vector<std::string> parsedCommand) {
  std::string const token1 = parsedCommand[0];

  if (token1 == "F") {
    comedyInventory_.emplace_back(std::stoi(parsedCommand[1]), parsedCommand[2],
                                  parsedCommand[3],
                                  std::stoi(parsedCommand[4]));
    std::sort(comedyInventory_.begin(), comedyInventory_.end());
  } else if (token1 == "D") {
    dramaInventory_.emplace_back(std::stoi(parsedCommand[1]), parsedCommand[2],
                                 parsedCommand[3], std::stoi(parsedCommand[4]));
    std::sort(dramaInventory_.begin(), dramaInventory_.end());
  } else if (token1 == "C") {
    std::string const delimiter = " ";

    std::string token;
    std::vector<std::string> parsed_token;

    while (parsedCommand[4].find(delimiter) != std::string::npos) {
      token = parsedCommand[4].substr(0, parsedCommand[4].find(delimiter));
      parsed_token.push_back(token);
      parsedCommand[4].erase(0, parsedCommand[4].find(delimiter) +
                                    delimiter.length());
    }

    parsed_token.push_back(parsedCommand[4]);

    classicInventory_.emplace_back(
        std::stoi(parsedCommand[1]), parsedCommand[2], parsedCommand[3],
        parsed_token[0] + " " + parsed_token[1], std::stoi(parsed_token[2]),
        std::stoi(parsed_token[3]));
    std::sort(classicInventory_.begin(), classicInventory_.end());
  }
}

void InventoryManager::newCustomer(std::vector<std::string> parsedCommand) {
  customers_.insert(
      {parsedCommand[0],
       Customer(parsedCommand[2], parsedCommand[1], parsedCommand[0])});
}

void InventoryManager::newCommand(const std::string &command) {
  if (command[0] == 'I') {
    std::cout << "Current Inventory:" << std::endl;
    std::cout << "\tComedy Inventory:" << std::endl;

    for (const auto &comedy : comedyInventory_)
      std::cout << "\t\t" << comedy << std::endl;

    std::cout << "\tDrama Inventory:" << std::endl;
    for (const auto &drama : dramaInventory_)
      std::cout << "\t\t" << drama << std::endl;

    std::cout << "\tComedy Inventory:" << std::endl;
    for (const auto &classic : classicInventory_)
      std::cout << "\t\t" << classic << std::endl;

    std::cout << std::endl;
  }

  else if (customers_.count(command.substr(2, 4)) > 0) {
    Customer &customer = customers_.at(command.substr(2, 4));

    if (command[0] == 'H') {
      customer.history();
      std::cout << std::endl;
    }

    else if (command[9] == 'F') {
      bool found = false;

      for (Comedy &comedy : comedyInventory_) {
        if (comedy.getTitle() == command.substr(11, command.length() - 17) &&
            comedy.getReleaseYear() ==
                std::stoi(command.substr(command.length() - 4, 4))) {
          found = true;
          if (command[0] == 'B') {
            if (comedy.getStock() > 0) {
              comedy.setStock(comedy.getStock() - 1);
              customer.borrowMovie(comedy);
            }

            else {
              std::cout << "Unable To Borrow Movie: " << comedy << std::endl;
            }
          }

          else if (command[0] == 'R') {
            comedy.setStock(comedy.getStock() + 1);
            customer.returnMovie(comedy);
          }
        }
      }

      if (!found) {
        std::cout << "Error In Command (Command Discarded): " << command
                  << std::endl;
      }
    }

    else if (command[9] == 'D') {
      bool found = false;

      for (Drama &drama : dramaInventory_) {

        if (drama.getTitle() ==
                command.substr(command.find(", ") + 2,
                               command.length() - command.find(',') - 3) &&
            drama.getDirector() == command.substr(11, command.find(',') - 11)) {
          found = true;

          if (command[0] == 'B') {
            if (drama.getStock() > 0) {
              drama.setStock(drama.getStock() - 1);
              customer.borrowMovie(drama);
            }

            else {
              std::cout << "Unable To Borrow Movie: " << drama << std::endl;
            }
          }

          else if (command[0] == 'R') {
            drama.setStock(drama.getStock() + 1);
            customer.returnMovie(drama);
          }
        }
      }

      if (!found) {
        std::cout << "Error In Command (Command Discarded): " << command
                  << std::endl;
      }
    }

    else if (command[9] == 'C') {

      bool found = false;

      for (Classic &classic : classicInventory_) {
        if (classic.getReleaseYear() == std::stoi(command.substr(13, 4)) &&
            classic.getMajorActor() == command.substr(18)) {
          found = true;

          if (command[0] == 'B') {
            if (classic.getStock() > 0) {
              classic.setStock(classic.getStock() - 1);
              customer.borrowMovie(classic);
            }

            else {
              std::cout << "Unable To Borrow Movie: " << classic << std::endl;
            }

          }

          else if (command[0] == 'R') {
            classic.setStock(classic.getStock() + 1);
            customer.returnMovie(classic);
          }
        }
      }

      if (!found) {
        std::cout << "Error In Command (Command Discarded): " << command
                  << std::endl;
      }
    }

    else {
      std::cout << "Error In Command (Command Discarded): " << command
                << std::endl;
    }
  }

  else {
    std::cout << "Error In Command (Command Discarded): " << command
              << std::endl;
  }
}