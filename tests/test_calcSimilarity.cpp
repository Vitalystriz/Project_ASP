#include <gtest/gtest.h>
#include "Similarity.h"

TEST(RecommendationAccuracy, StepA_UserSimilarity) {
    std::map<int, std::vector<int>> matrix;
    matrix[1] = {100, 101, 102, 103};
    matrix[2] = {101, 102, 104, 105, 106};
    matrix[3] = {100, 104, 105, 107, 108};
    matrix[4] = {101, 105, 106, 107, 109, 110};
    matrix[5] = {100, 102, 103, 105, 108, 111};
    matrix[6] = {100, 103, 104, 110, 111, 112, 113};
    matrix[7] = {102, 105, 106, 107, 108, 109, 110};
    matrix[8] = {101, 104, 105, 106, 109, 111, 114};
    matrix[9] = {100, 103, 105, 107, 112, 113, 115};
    matrix[10] = {100, 102, 105, 106, 107, 109, 110, 116};

    Similarity sim;
    sim.calculateSimilarity(matrix, 1);
    std::map<int, int>& scores = sim.getSimilarityMap();

    // Comparing against the "Common products with User 1" table
    EXPECT_EQ(scores[2], 2);
    EXPECT_EQ(scores[3], 1);
    EXPECT_EQ(scores[4], 1);
    EXPECT_EQ(scores[5], 3);
    EXPECT_EQ(scores[6], 2);
    EXPECT_EQ(scores[7], 1);
    EXPECT_EQ(scores[8], 1);
    EXPECT_EQ(scores[9], 2);
    EXPECT_EQ(scores[10], 2);
}