//
// Created by vitaly on 05.05.2026.
//

#include "AppendProductAction.h"

#include <utility>

#include "DataManager.h"

AppendProductAction::AppendProductAction(std::vector<int> products, int userId) {
    this->products = std::move(products);
    this->userId = userId;
}
void AppendProductAction::execute(DataManager *dataManager) {
    try {
        std::map <int, std::set <int>> data = dataManager->getMapUserToProducts();

        data[this->userId].insert(this->products.begin(), this->products.end());
        dataManager->setMapUserToProducts(data);

        std::map <int, std::set <int>> data2 = dataManager->getMapProductToUser();

        //iterating all products and set user
        for(int product : this->products) {
            data2[product].insert(this->userId);
        }
        dataManager->setMapProductToUsers(data2);
    }
    catch (...) {
        this->displayError();
    }
}
void AppendProductAction::displayError() {
    std::cout<<"Something went wrong, try one more time"<<std::endl;
}


