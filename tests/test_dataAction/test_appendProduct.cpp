
#include <gtest/gtest.h>
#include "DataManager.h"
#include "persistence/dataAction/AppendProductAction.h"


TEST(AppendProductTest, AppendsProductToExistingUser) {
    std::map<int, std::vector<int>> data = {{1, {101, 102}}};
    std::map<int, std::vector<int>> data2 = {{101, {1}}, {102, {1}}};
    DataManager data_manager;
    data_manager.setMapUserToProducts(data);
    data_manager.setMapProductToUsers(data2);

    std::vector<int> addition = {103};
    AppendProductAction append_product_action(addition, 1);
    append_product_action.execute(&data_manager);


    auto updatedMap = data_manager.getMapUserToProducts();
    auto updateMap2 = data_manager.getMapProductToUser();
    std::vector<int> expected_products = {101, 102, 103};

    EXPECT_EQ(updatedMap[1], expected_products);
    EXPECT_EQ(updateMap2[103], std::vector<int>({1}));
    EXPECT_EQ(updateMap2[102], std::vector<int>({1}));
    EXPECT_EQ(updateMap2[101], std::vector<int>({1}));
}


TEST(AppendProductTest, AppendsProductToExistingUser2) {
    std::map<int, std::vector<int>> data = {{1, {101, 102, 103}}, {2, {103}}};
    std::map<int, std::vector<int>> data2 = {{101, {1}}, {102, {1}}, {103, {1, 2}},
        {104, {2}}};
    DataManager data_manager;
    data_manager.setMapUserToProducts(data);
    data_manager.setMapProductToUsers(data2);

    std::vector<int> addition = {105};
    AppendProductAction append_product_action(addition, 2);
    append_product_action.execute(&data_manager);


    auto updatedMap = data_manager.getMapUserToProducts();
    auto updateMap2 = data_manager.getMapProductToUser();
    std::vector<int> expected_products = {103, 105};

    EXPECT_EQ(updatedMap[2], expected_products);
    EXPECT_EQ(updateMap2[103], std::vector<int>({1,2}));
    EXPECT_EQ(updateMap2[105], std::vector<int>({2}));
    EXPECT_EQ(updateMap2[102], std::vector<int>({1}));

}
