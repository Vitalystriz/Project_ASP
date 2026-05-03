//
// Created by geras on 29.04.2026.
//

#ifndef RECOMMENDCOMMAND_H
#define RECOMMENDCOMMAND_H
#include <iosfwd>
#include <map>

#include "ICommand.h"
#include <map>
#include <vector>
#include <bits/stl_vector.h>

class RecommendCommand: public ICommand {
private:
    std::map <int, std::vector<int>> map;
public:
    RecommendCommand();
    void execute(std::map<int, std::vector<int>> map) override;
    std::map<int, std::vector<int>> getArgs();
};



#endif //RECOMMENDCOMMAND_H
