//
// Created by geras on 03.05.2026.
//
// tests/test_Initialization.cpp

#include <gtest/gtest.h>
#include "Initialization.h"

TEST(InitializationTest, CreateCommandMapPopulatesCorrectly) {
    Initialization init;
    auto commandMap = init.createCommandMap();

    // 1. Verify the exact number of commands registered
    EXPECT_EQ(commandMap.size(), 4);

    // 2. Verify specific keys exist and are not null pointers
    EXPECT_TRUE(commandMap.find(-1) != commandMap.end());
    EXPECT_NE(commandMap[-1], nullptr); // DisplayErrorClass

    EXPECT_TRUE(commandMap.find(1) != commandMap.end());
    EXPECT_NE(commandMap[1], nullptr);  // HelpCommand

    EXPECT_TRUE(commandMap.find(2) != commandMap.end());
    EXPECT_NE(commandMap[2], nullptr);  // AddCommand

    EXPECT_TRUE(commandMap.find(3) != commandMap.end());
    EXPECT_NE(commandMap[3], nullptr);  // RecommendCommand

    // 3. Clean up the memory allocated by new in createCommandMap
    // to prevent memory leaks during testing
    for (auto const& [key, val] : commandMap) {
        delete val;
    }
}