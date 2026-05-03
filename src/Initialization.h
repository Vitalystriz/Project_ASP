//
// Created by geras on 29.04.2026.
//

#ifndef INITIALIZATION_H
#define INITIALIZATION_H


#include <map>
#include "ICommand.h"
class Initialization {
  public:
    std::map<std::string, ICommand*> createCommandMap();
    void appLaunch();
};



#endif //INITIALIZATION_H
