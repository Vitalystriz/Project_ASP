class RecommendationList {
    private:
        Similarity* similarity;
        CandidateProducts* candidateProducts;
    public:
        RecommendationList(Similarity* s, CandidateProducts* cp)
            : similarity(s), candidateProducts(cp) {}

        int* calculate(){
            return nullptr;
        }
}