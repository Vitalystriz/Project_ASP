//
// Created by vitaly on 29.04.2026.
//

#include "AddCommand.h"

#include <utility>
AddCommand::AddCommand() = default;


void AddCommand::execute(std::map<int, std::vector<int>> map) {
    this->map = std::move(map);
    std::cout<<"Adding user..."<<std::endl;
    //TODO write execution
}

std::map<int, std::vector<int> > AddCommand::getArgs() {
    return this->map;
}


