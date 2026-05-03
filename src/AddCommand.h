//
// Created by geras on 29.04.2026.
//

#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H
#include <map>
#include <vector>
#include "ICommand.h"
class AddCommand: public ICommand{
    private:
      std::map <int, std::vector<int>> map;
    public:
      AddCommand();
      std::map<int, std::vector<int>> getArgs();
      void execute(std::map<int, std::vector<int>> map) override;

};



#endif //ADDCOMMAND_H
