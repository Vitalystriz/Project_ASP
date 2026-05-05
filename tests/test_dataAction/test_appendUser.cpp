
#include <gtest/gtest.h>

#include "DataManager.h"
#include "persistence/dataAction/AppendUserAction.h"

TEST(AppendUserTest, UserToProductMap) {
    std::map<int, std::set<int>> data = {{1, {102, 103}}, {4, {105, 106}}};

    auto* data_manager = new DataManager();
    data_manager->setMapUserToProducts(data);

    auto* append_user_action = new AppendUserAction(5);
    append_user_action->execute(data_manager);

    EXPECT_EQ(data_manager->getMapUserToProducts()[5], std::set<int>());
    delete data_manager;
}

TEST(AppendUserTest, UserToProductMapUpdate) {
    std::map<int, std::set<int>> data = {{1, {102, 103}}, {4, {105, 106}}};

    auto* data_manager = new DataManager();
    data_manager->setMapUserToProducts(data);

    auto* append_user_action = new AppendUserAction(5);
    append_user_action->execute(data_manager);

    data[5] = {};
    EXPECT_EQ(data_manager->getMapUserToProducts(), data);
    delete data_manager;
}

TEST(AppendUserTest, UserToProductMapEmpty) {
    std::map<int, std::set<int>> data = {};

    auto* data_manager = new DataManager();
    data_manager->setMapUserToProducts(data);

    auto* append_user_action = new AppendUserAction(2);
    append_user_action->execute(data_manager);

    std::map<int, std::set<int>>updated_data = {{2, {}}};
    EXPECT_EQ(data_manager->getMapUserToProducts(), updated_data);
    delete data_manager;
}

TEST(AppendUserTest, UserToProductNotEQ) {
    std::map<int, std::set<int>> data = {};

    auto* data_manager = new DataManager();
    data_manager->setMapUserToProducts(data);

    auto* append_user_action = new AppendUserAction(2);
    append_user_action->execute(data_manager);

    data[5] = {};
    EXPECT_NE(data_manager->getMapUserToProducts(), data);
    delete data_manager;
}


TEST(AppendUserTest, UserToProductAlreadyExists) {
    std::map<int, std::set<int>> data = {{1, {102, 103}}, {4, {105, 106}}};

    auto* data_manager = new DataManager();
    data_manager->setMapUserToProducts(data);

    auto* append_user_action = new AppendUserAction(1);
    append_user_action->execute(data_manager);

    EXPECT_EQ(data_manager->getMapUserToProducts(), data);
    delete data_manager;
}
