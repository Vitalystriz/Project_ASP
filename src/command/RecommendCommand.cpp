//
// Created by vitaly on 29.04.2026.
//

#include "RecommendCommand.h"
#include "algorithm/Similarity.h"
#include "algorithm/CandidateProducts.h"
#include "algorithm/RecommendationList.h"
#include "DataManager.h"
#include <utility>
#include <vector>


RecommendCommand::RecommendCommand(DataManager* dm) {
    this->dataManager = dm;
}


void RecommendCommand::execute(std::map<std::string, std::vector<std::string>> map) {
    this->map = std::move(map);
    auto it = this->map.begin();
    std::string userId = it->first;
    std::string productId = it->second[0];


    Similarity similarity;
    similarity.calculate(dataManager, userId);

    CandidateProducts candidateProducts;
    candidateProducts.calculate(dataManager, productId, userId);


    RecommendationList recommendationList(similarity.getMap(), candidateProducts.getMap());
    std::vector<std::string> finalRecommendations = recommendationList.calculate();

    if (finalRecommendations.empty()) {
        std::cout << "" << std::endl;
        return;
    }
    int i = 0;
    for (const std::string& recommendation : finalRecommendations) {
        if (i != 0) {
            std::cout << " ";
        }
        std::cout << recommendation;
        i++;
    }
    std::cout << std::endl;
}

std::map<std::string, std::vector<std::string>>  RecommendCommand::getArgs() {
    return this->map;
}


