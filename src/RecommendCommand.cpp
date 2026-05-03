//
// Created by vitaly on 29.04.2026.
//

#include "RecommendCommand.h"

#include <utility>
#include <vector>


RecommendCommand::RecommendCommand() = default;


void RecommendCommand::execute(std::map<int, std::vector<int>> map) {
    this->map = std::move(map);
    std::cout<<"Recommending products..."<<std::endl;
    //TODO write implementation
}

std::map<int, std::vector<int>>  RecommendCommand::getArgs() {
    return this->map;
}



