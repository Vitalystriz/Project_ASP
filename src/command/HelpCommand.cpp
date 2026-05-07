#include "ICommand.h"
//
// Created by vitaly on 29.04.2026.
//
#include "HelpCommand.h"

    void HelpCommand::execute(std::map<std::string, std::vector<std::string>> map) {
        execute();
    }
    void HelpCommand::execute() {
        std::cout << "add [userid] [productid1] [productid2] ..." << std::endl;
        std::cout << "recommend [userid] [productid]" << std::endl;
        std::cout << "help" << std::endl;
    }




