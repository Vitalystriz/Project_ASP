//
// Created by vitaly on 28.04.2026.
//


#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include "IMenu.h"
#include "HelpCommand.h"
#include "ConsoleMenu.h"

    ConsoleMenu::ConsoleMenu() {
        this->mapArgs = std::map<int, std::vector<int>>();
        printMenu();
    }

    void ConsoleMenu::printMenu() {
        HelpCommand help;
        help.execute();
    }

std::string ConsoleMenu::nextCommand() { // -> int command
        std::string line;

        // 1. Read the entire line from the user at once
        if(!std::getline(std::cin, line) || line == "exit") {
            return "exit";
        }

        if (line.empty()) {
            return "error";
        }

        std::stringstream ss(line);
        std::string command;

        ss >> command;

        if (command == "help") return "help";

        if (command == "add") {
            int uId;
            std::vector<int> pId;
            if (ss >> uId) {
                int temp_pId; // Temporary variable to hold the parsed ID
                while(ss >> temp_pId) {
                    pId.push_back(temp_pId); // Safely append to the vector
                }
                mapArgs[uId] = pId;
            }
            return "add";
        }

        if (command == "recommend") {
            int uId;
            int temp_pId; // Temporary variable
            std::vector<int> pId;
            if (ss >> uId && ss >> temp_pId) {
                pId.push_back(temp_pId); // Safely append to the vector
                mapArgs[uId] = pId; // map{targetUId: targetPId}
            }
            return "recommend";
        }

        return "error";
    }

    void ConsoleMenu::displayError() {
        std::cout << "Sorry, an error occurred" << std::endl;
        std::cout << "Please, try enter your command one more time" << std::endl;
    }

    void ConsoleMenu::exitMessage() {
        std::cout << "Goodbye" << std::endl;
    }

    std::map<int, std::vector<int> > ConsoleMenu::getArgs() {
        return mapArgs;
    }
