//
// Created by Mika on 03.05.2026.
//

#ifndef SIMILARITY_H
#define SIMILARITY_H

#include <map>
#include <vector>

class Similarity {
private:
    std::map<int, int> similarityMap;

public:
    void calculateSimilarity(std::vector<int>& matrix, int user);
};

#endif //SIMILARITY_H