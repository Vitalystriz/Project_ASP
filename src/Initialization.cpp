//
// Created by geras on 29.04.2026.
//

#include "Initialization.h"
#include <map>
#include "ICommand.h"
#include "App.h"
#include "ConsoleMenu.h"
#include "HelpCommand.h"
#include "AddCommand.h"
#include "DisplayErrorClass.h"
#include "RecommendCommand.h"



std::map<int, ICommand*> Initialization::createCommandMap() {
    std::map<int, ICommand*> commands; // fix magic numbers trouble

    commands[-1] = new DisplayErrorClass();
    commands[1] = new HelpCommand();
    commands[2] = new AddCommand();
    commands[3] = new RecommendCommand();

    return commands;
}

void Initialization::appLaunch() {

    IMenu* menu = new ConsoleMenu();

    std::map<int, ICommand*> commands = createCommandMap();

    App app(menu, commands);


    app.run();


    for (auto const& [key, val] : commands) {
        delete val;
    }
    delete menu;
}