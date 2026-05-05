//
// Created by vitaly on 29.04.2026.
//

#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H
#include <map>
#include <vector>
#include "ICommand.h"
#include "DataManager.h"

class AddCommand: public ICommand{
private:
    DataManager* dataManager;
    std::map <int, std::vector<int>> map;
public:
    explicit AddCommand(DataManager* dm);
    std::map<int, std::vector<int>> getArgs();
    void execute(std::map<int, std::vector<int>> map) override;

};



#endif //ADDCOMMAND_H
