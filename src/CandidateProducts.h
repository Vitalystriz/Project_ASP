//
// Created by Mika on 03.05.2026.
//

#ifndef CANDIDATEPRODUCTS_H
#define CANDIDATEPRODUCTS_H

#include <map>
#include <vector>

class CandidateProducts {
private:
    std::map<int, int> candidateProductsMap;
public:
    void calculate(std::vector<int>& matrix, int productId);
};

#endif //CANDIDATEPRODUCTS_H