

#include <gtest/gtest.h>
#include "command/HelpCommand.h"
#include <sstream>
#include <iostream>

TEST(HelpCommandTest, ExecutePrintsCorrectMenu) {

    std::stringstream buffer;


    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());


    HelpCommand helpCommand;
    helpCommand.execute();


    std::cout.rdbuf(oldCoutBuffer);


    std::string output = buffer.str();



    EXPECT_TRUE(output.find("add [userid] [productid1] [productid2] ...") != std::string::npos);
    EXPECT_TRUE(output.find("recommend [userid] [productid]") != std::string::npos);
    EXPECT_TRUE(output.find("help") != std::string::npos);
}
