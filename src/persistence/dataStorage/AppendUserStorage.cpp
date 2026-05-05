#include "AppendUserStorage.h"
#include <fstream>
#include <iostream>
#include <filesystem> // Needed for directory creation and absolute paths

AppendUserStorage::AppendUserStorage(int userId) {
    this->userId = userId;
}

void AppendUserStorage::execute(DataManager* dataManager) {
    std::map<int, std::set<int>> data = dataManager->getMapUserToProducts();

    std::string directoryPath = "data";
    std::string filePath = directoryPath + "/dataUserToProduct.txt";

    if (!std::filesystem::exists(directoryPath)) {
        std::filesystem::create_directories(directoryPath);
    }

    std::ofstream outFile(filePath, std::ios::out | std::ios::trunc);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the file to write user data at " << filePath << std::endl;
        return;
    }

    for (const auto& [currentUserId, products] : data) {
        outFile << "{" << currentUserId << " {";

        int i = 0;
        int total_products = static_cast<int>(products.size());

        for (int product : products) {
            outFile << product;
            if (i < total_products - 1) {
                outFile << ", ";
            }
            i++;
        }

        outFile << "}}\n";
    }

    outFile.flush();
    outFile.close();


    std::cout << "Success! Data saved to: " << std::filesystem::absolute(filePath) << std::endl;
}


