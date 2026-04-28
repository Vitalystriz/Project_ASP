//
// Created by geras on 26.04.2026.
//

#include "math.h"
#include <gtest/gtest.h>

TEST (AdditionTest, PositiveNumbers) {
    EXPECT_EQ(add(1, 2), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}