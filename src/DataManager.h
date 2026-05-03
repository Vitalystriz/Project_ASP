//
// Created by vitaly on 03.05.2026.
//

#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <map>
#include <vector>


class DataManager {
private:
    std::map <int, std::vector <int>> userToProducts;
    std::map <int, std::vector <int>> productToUser;
public:
    static void setMapUserToProducts(std::map <int, std::vector <int>>);
    static void setMapProductToUsers(std::map <int, std::vector <int>>);
    static std::map <int, std::vector <int>> getMapUserToProducts();
    static std::map <int, std::vector <int>> getMapProductToUser();

};



#endif //DATAMANAGER_H
