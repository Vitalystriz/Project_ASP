#include "RecommendationList.h"

RecommendationList::RecommendationList(Similarity* s, CandidateProducts* cp) 
    : similarity(s), candidateProducts(cp) {}

//
//forces the rule that we were given: products that are tied- are sorted in an
//ascending order
//creates a sorted list with all the final recommendation scores

bool compare(std::pair<int, int> x, std::pair<int, int> y) {
    if (x.second != y.second) {
        return x.second > y.second; 
    }
    return x.first < y.first; 
}

int* RecommendationList::calculate() {
    std::map<int, int>& productMap = candidateProducts->getMap();
    std::vector<std::pair<int, int>> sortedProducts(productMap.begin(), productMap.end());
    std::sort(sortedProducts.begin(), sortedProducts.end(), compare);

    int size = sortedProducts.size();
    int* results = new int[size]; 
    for (int i = 0; i < size; ++i) {
        results[i] = sortedProducts[i].first;
    }

    return results; 
}