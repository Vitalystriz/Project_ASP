//
// Created by vitaly on 03.05.2026.
//

#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <map>
#include <vector>
#include <set>

class DataManager {
private:
    std::map <int, std::set <int>> userToProducts;
    std::map <int, std::set <int>> productToUser;
public:
    void setMapUserToProducts(std::map <int, std::set <int>>);
    void setMapProductToUsers(std::map <int, std::set <int>>);
    std::map <int, std::set <int>> getMapUserToProducts();
    std::map <int, std::set <int>> getMapProductToUser();

};



#endif //DATAMANAGER_H
