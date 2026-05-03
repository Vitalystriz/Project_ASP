//
// Created by vitaly on 27.04.2026.
//
// tests/test_Initialization.cpp

#include <gtest/gtest.h>
#include "run/Initialization.h"

TEST(InitializationTest, CreateCommandMapPopulatesCorrectly) {
    Initialization init;
    auto commandMap = init.createCommandMap();

    // 1. Verify the exact number of commands registered
    EXPECT_EQ(commandMap.size(), 4);

    // 2. Verify specific keys exist and are not null pointers
    EXPECT_TRUE(commandMap.find("exit") != commandMap.end());
    EXPECT_NE(commandMap["exit"], nullptr); // DisplayErrorClass

    EXPECT_TRUE(commandMap.find("help") != commandMap.end());
    EXPECT_NE(commandMap["help"], nullptr);  // HelpCommand

    EXPECT_TRUE(commandMap.find("add") != commandMap.end());
    EXPECT_NE(commandMap["add"], nullptr);  // AddCommand

    EXPECT_TRUE(commandMap.find("recommend") != commandMap.end());
    EXPECT_NE(commandMap["recommend"], nullptr);  // RecommendCommand

    // 3. Clean up the memory allocated by new in createCommandMap
    // to prevent memory leaks during testing
    for (auto const& [key, val] : commandMap) {
        delete val;
    }
}