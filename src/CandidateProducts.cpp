#include "CandidateProducts.h"

    void CandidateProducts::calculate(std::map<int, std::vector<int>>& matrix, int productId, std::map<int, int>& similarityMap) {
        for (std::map<int, std::vector<int>>::iterator it = matrix.begin(); it != matrix.end(); ++it) {
            int userId = it->first;
            std::vector<int>& products = it->second;

<<<<<<< HEAD
            for (int i = 0; i < products.size(); ++i) {
=======
            //calculate the recommendation weight by summing the similarity values
            //of all the other users that watched this target product.
            for (int i = 0; i < products.size(); ++i)
                {
>>>>>>> PA-32-Implement-Recommendation-Weight-calculation-algorithm
                if (products[i] == productId) {
                    int tempSimilarity = similarityMap[userId];
                    for (int i = 0; i < products.size(); ++i) {
                        if (products[i] != productId) {
                            candidateProductsMap[products[i]] += tempSimilarity;
                        }
                    }
                    break;
                }
            }
        }
    }

    std::map<int, int>& CandidateProducts::getMap() {
        return candidateProductsMap;
    }