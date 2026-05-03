//
// Created by Mika on 03.05.2026.
//

#ifndef RECOMMENDATIONLIST_H
#define RECOMMENDATIONLIST_H

class Similarity;
class CandidateProducts;

class RecommendationList {
private:
    Similarity* similarity;
    CandidateProducts* candidateProducts;
public:
    RecommendationList(Similarity* s, CandidateProducts* cp)
        : similarity(s), candidateProducts(cp) {}

    int* calculate();
};

#endif //RECOMMENDATIONLIST_H