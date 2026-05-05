#ifndef CANDIDATEPRODUCTS_H
#define CANDIDATEPRODUCTS_H

#include <map>
#include <vector>

class CandidateProducts {
private:
    std::map<int, int> candidateProductsMap;
public:
    void calculate(std::map<int, std::vector<int>>& matrix, int productId, std::map<int, int>& simMap, int targetUserId);
    std::map<int, int>& getMap();
};

#endif //CANDIDATEPRODUCTS_H
