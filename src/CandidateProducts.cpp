#include "CandidateProducts.h"
#include <algorithm>

    void CandidateProducts::calculate(std::map<int, std::vector<int>>& matrix, int productId, std::map<int, int>& similarityMap, int targetUserId) {
        std::vector<int>& targetUserProducts = matrix[targetUserId];
        
        //calculate the recommendation weight by summing the similarity values
        //of all the other users that watched this target product.
        //exclude watched products.
        for (std::map<int, std::vector<int>>::iterator it = matrix.begin(); it != matrix.end(); ++it) {
            int userId = it->first;
            std::vector<int>& products = it->second;

            bool watched = std::find(products.begin(), products.end(), productId) != products.end();
            
            if (watched) {
                int tempSimilarity = similarityMap[userId];
                for (int i = 0; i < products.size(); ++i) {
                    if (products[i] != productId) {
                        bool targetUserWatched = std::find(targetUserProducts.begin(), targetUserProducts.end(), products[i]) != targetUserProducts.end();
                        if (!targetUserWatched) {
                            candidateProductsMap[products[i]] += tempSimilarity;
                        }
                    }
                }
            }
        }
    }

    std::map<int, int>& CandidateProducts::getMap() {
        return candidateProductsMap;
    }
