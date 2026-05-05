//
// Created by vitaly on 05.05.2026.
//
#include "AppendUserAction.h"

#include "DataManager.h"

AppendUserAction::AppendUserAction(int userId) {
    this->userId = userId;
}

void AppendUserAction::execute(DataManager* dataManager) {
    std::map <int, std::vector <int>> data = dataManager->getMapUserToProducts();
    if (data.find(userId) != data.end()) {
        this->displayError();
        return;
    }
    std::vector <int> products;
    data[userId] = products;
    dataManager->setMapUserToProducts(data);
}

void AppendUserAction::displayError() {
    std::cout<<"User already exists"<<std::endl;
}
