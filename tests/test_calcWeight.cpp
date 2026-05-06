// #include <gtest/gtest.h>
// #include "CandidateProducts.h"
//
// TEST(RecommendationAccuracy, StepB_TotalRelevance) {
//     std::map<int, std::vector<int>> matrix;
//
//     matrix[1] = {100, 101, 102, 103};
//     matrix[2] = {101, 102, 104, 105, 106};
//     matrix[3] = {100, 104, 105, 107, 108};
//     matrix[6] = {100, 103, 104, 110, 111, 112, 113};
//     matrix[8] = {101, 104, 105, 106, 109, 111, 114};
//
//     std::map<int, int> simMap;
//     simMap[2] = 2; simMap[3] = 1; simMap[6] = 2; simMap[8] = 1;
//
//     CandidateProducts cp;
//     cp.calculate(matrix, 104, simMap, 1);
//     std::map<int, int>& relevance = cp.getMap();
//
//     EXPECT_EQ(relevance[105], 4); // User 2(2) + 3(1) + 8(1)
//     EXPECT_EQ(relevance[106], 3); // User 2(2) + 8(1)
//     EXPECT_EQ(relevance[111], 3); // User 6(2) + 8(1)
//     EXPECT_EQ(relevance[110], 2); // User 6(2)
//     EXPECT_EQ(relevance[107], 1); // User 3(1)
// }
