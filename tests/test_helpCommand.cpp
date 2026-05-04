//
// Created by geras on 28.04.2026.
//
// tests/test_HelpCommand.cpp

#include <gtest/gtest.h>
#include "command/HelpCommand.h"
#include <sstream>
#include <iostream>

TEST(HelpCommandTest, ExecutePrintsCorrectMenu) {
    // 1. Create a buffer to intercept the console output
    std::stringstream buffer;

    // 2. Redirect std::cout to our buffer and save the old buffer
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    // 3. Run the command
    HelpCommand helpCommand;
    helpCommand.execute(); // Or helpCommand.execute({})

    // 4. Restore standard output immediately so gtest can print test results!
    std::cout.rdbuf(oldCoutBuffer);

    // 5. Extract the intercepted string
    std::string output = buffer.str();

    // 6. Verify the output contains our expected CLI commands
    EXPECT_TRUE(output.find("--- Recommendation System CLI ---") != std::string::npos);
    EXPECT_TRUE(output.find("- help") != std::string::npos);
    EXPECT_TRUE(output.find("- add <userId> <productId1> <productId2> ...") != std::string::npos);
    EXPECT_TRUE(output.find("- recommend <userId> <productId>") != std::string::npos);
    EXPECT_TRUE(output.find("- exit") != std::string::npos);
}
