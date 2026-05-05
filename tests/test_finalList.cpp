#include <gtest/gtest.h>
#include "RecommendationList.h"
#include "Similarity.h"
#include "CandidateProducts.h"

TEST(RecommendationAccuracy, StepG_FinalRankAndSorting) {
    // Step 1: Build the matrix
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

    // Step 2: Calculate similarity for user 1
    Similarity sim;
    sim.calculateSimilarity(matrix, 1);
    std::map<int, int>& simMap = sim.getSimilarityMap();

    // Step 3: Calculate candidate products (excluding products user 1 already watched)
    CandidateProducts cp;
    cp.calculate(matrix, 104, simMap, 1);
    std::map<int, int>& relevance = cp.getMap();

    // Step 4: Sort and get final recommendation list
    RecommendationList recList(&sim, &cp);
    int* results = recList.calculate();

    // Expected order based on scores (descending) then by product ID (ascending) for ties
    int expected[] = {105, 106, 111, 110, 112, 113, 107, 108, 109, 114};
    
    for(int i = 0; i < 10; ++i) {
        EXPECT_EQ(results[i], expected[i]);
    }

    delete[] results;
}
