//
// Created by vitaly on 29.04.2026.
//

#include "AddCommand.h"

#include <utility>

#include "persistence/dataAction/AppendProductAction.h"
#include "persistence/dataAction/AppendUserAction.h"
#include "persistence/dataStorage/AppendUserStorage.h"


AddCommand::AddCommand(DataManager *dm) {
    this->dataManager = dm;
}

void AddCommand::execute(std::map<int, std::vector<int>> map) {
    this->map = std::move(map);

    auto it = this->map.begin();
    int userId = it->first;
    std::vector<int> data = it->second;


    auto* append_user_action = new AppendUserAction(userId);
    append_user_action->execute(dataManager);
    delete append_user_action;

    auto* append_products_action = new AppendProductAction(data, userId);
    append_products_action->execute(dataManager);
    delete append_products_action;

    auto* append_user_storage = new AppendUserStorage(userId);
    append_user_storage->execute(dataManager);
    delete append_user_storage;

    std::cout<<"Adding user..."<<std::endl;
}

std::map<int, std::vector<int> > AddCommand::getArgs() {
    return this->map;
}
