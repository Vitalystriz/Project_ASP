//
// Created by vitaly on 03.05.2026.
//

#include "DataManager.h"
#include <map>
#include <vector>
void DataManager::setMapUserToProducts(std::map<int, std::vector<int> > map) {
    userToProducts = std::move(map);
}

void DataManager::setMapProductToUsers(std::map<int, std::vector<int> > map) {
    productToUser = std::move(map);
}

std::map<int, std::vector<int> > DataManager::getMapProductToUser() {
    return productToUser;
}

std::map<int, std::vector<int> > DataManager::getMapUserToProducts() {
    return userToProducts;
}