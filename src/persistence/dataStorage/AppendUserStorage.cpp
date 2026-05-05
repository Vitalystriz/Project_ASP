
#include "AppendUserStorage.h"
#include <fstream>

#include <iostream>


AppendUserStorage::AppendUserStorage(int userId) {
    this->userId = userId;
}

void AppendUserStorage::execute(DataManager* dataManager) {
    std::map<int, std::vector<int>> data = dataManager->getMapUserToProducts();

    if (data.find(userId) == data.end()) {
        std::cerr << "Error: User " << userId << " not found in DataManager." << std::endl;
        return;
    }

    std::vector<int> products = data[userId];

    std::ofstream outFile("data/data.txt", std::ios::app);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the file to write user data." << std::endl;
        return;
    }

    outFile << "{" << userId << " {";

    for (size_t i = 0; i < products.size(); ++i) {
        outFile << products[i];
        if (i < products.size() - 1) {
            outFile << ", ";
        }
    }

    outFile << "}}\n";

    outFile.close();
}