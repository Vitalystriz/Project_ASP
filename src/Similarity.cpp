#include "Similarity.h"

    void Similarity::calculateSimilarity(std::map<int, std::vector<int>>& matrix, int user) {
        std::vector<int>& userProducts = matrix[user];

        //for all users that are not our target user- calculate the amount of shared products which
        //will act as the similarity
        std::vector<int>>::iterator it = matrix.begin();
        for (std::map<int, it; it != matrix.end(); ++it) {
            int otherId = it->first;
            std::vector<int>& products = it->second;
            if (otherId != user) {
                int count = 0;
                for (int i = 0; i < products.size(); ++i) {
                    if (std::find(userProducts.begin(), userProducts.end(), products[i]) != userProducts.end()) {
                        count++;
                    }
                }
                similarityMap[otherId] = count;
            }
        }
    }

    std::map<int, int>& Similarity::getSimilarityMap() {
        return similarityMap;
    }