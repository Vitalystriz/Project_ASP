//
// Created by vitaly on 29.04.2026.
//

#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H
#include "ICommand.h"
class HelpCommand: public ICommand {
public:
    void execute(std::map<int, std::vector<int>> map) override;
    void execute();
};
#endif //HELPCOMMAND_H
