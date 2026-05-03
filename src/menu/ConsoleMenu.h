//
// Created by vitaly on 29.04.2026.
//

#ifndef CONSOLEMENU_H
#define CONSOLEMENU_H
#include "IMenu.h"
#include <map>
#include <vector>

class ConsoleMenu : public IMenu {
private:
    std::map<int, std::vector<int>> mapArgs;

public:
    ConsoleMenu();

    static void printMenu();
    std::string nextCommand() override;
    void displayError() override;

    void exitMessage() override;

    std::map<int, std::vector<int>> getArgs() override;
};
#endif
