//
// Created by vitaly on 28.04.2026.
//

#ifndef IMENU_H
#define IMENU_H

#include<string>
#include<iostream>
#include <map>
class IMenu {
public:
    int nextCommand();
    void displayError();
    std::map<int, int> getArgs();
};



#endif //IMENU_H
