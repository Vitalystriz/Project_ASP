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



std::map<std::string, ICommand*> Initialization::createCommandMap() {
    std::map<std::string, ICommand*> commands; // fix magic numbers trouble

    commands["exit"] = new DisplayErrorClass();
    commands["help"] = new HelpCommand();
    commands["add"] = new AddCommand();
    commands["recommend"] = new RecommendCommand();

    return commands;
}

void Initialization::appLaunch() {

    IMenu* menu = new ConsoleMenu();

    std::map<std::string, ICommand*> commands = createCommandMap();

    App app(menu, commands);


    app.run();


    for (auto const& [key, val] : commands) {
        delete val;
    }
    delete menu;
}