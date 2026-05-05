//
// Created by vitaly on 03.05.2026.
//

#include "DataManager.h"

void DataManager::setMapUserToProducts(std::map<int, std::set<int> > map) {
    userToProducts = std::move(map);
}

void DataManager::setMapProductToUsers(std::map<int, std::set<int> > map) {
    productToUser = std::move(map);
}

std::map<int, std::set<int> > DataManager::getMapProductToUser() {
    return productToUser;
}

std::map<int, std::set<int> > DataManager::getMapUserToProducts() {
    return userToProducts;
}