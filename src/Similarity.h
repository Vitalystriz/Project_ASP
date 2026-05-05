#ifndef SIMILARITY_H
#define SIMILARITY_H

#include <map>
#include <vector>

class Similarity {
private:
    std::map<int, int> similarityMap;

public:
    void calculateSimilarity(std::map<int, std::vector<int>>& matrix, int user);
    std::map<int, int>& getSimilarityMap();
};

#endif //SIMILARITY_H
