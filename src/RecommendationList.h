#ifndef RECOMMENDATIONLIST_H
#define RECOMMENDATIONLIST_H

#include "Similarity.h"
#include "CandidateProducts.h"

class RecommendationList {
private:
    Similarity* similarity;
    CandidateProducts* candidateProducts;

public:
    RecommendationList(Similarity* s, CandidateProducts* cp);
    int* calculate();
};

#endif