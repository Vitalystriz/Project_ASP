//
// Created by vitaly on 28.04.2026.
//

#include <sstream>
#include <iostream>
#include <map>
#include "IMenu.h"
class ConsoleMenu: public IMenu {
private:
    std::map<int, int> mapArgs;
public:
    ConsoleMenu() {
        printMenu();
    }

    void printMenu() {
        std::cout << "--- Recommendation System CLI ---" << std::endl;
        std::cout << "Available commands:" << std::endl;
        std::cout << "- help" << std::endl;
        std::cout << "- add <userId> <productId1> <productId2> ..." << std::endl;
        std::cout << "- recommend <userId> <productId>" << std::endl;
        std::cout << "- exit" << std::endl;
        std::cout << "---------------------------------" << std::endl;
    }

    int nextCommand() { // -> int command
        std::string line;
        std::cin >> line;

        if(!std::getline(std::cin, line) || line == "exit") {
            return 0;
        }

        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "help") return 1;

        if (command == "add") {
            int uId, pId;
            ss >> uId;
            while(ss>>pId) {
                mapArgs[uId] = pId;
            }
            return 2;
        }

        if (command == "recommend") {
            int uId, pId;
            if (ss >> uId && ss>> pId) mapArgs[uId] = pId; // map{targetUId: targetPId}
            return 3;
        }
        return -1;
    }

    void displayError() {
        std::cout << "Sorry, an error occurred" << std::endl;
        std::cout << "Please, try enter your command one more time" << std::endl;
    }

    std::map<int, int> getArgs() {
        return mapArgs;
    }
};