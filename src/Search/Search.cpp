#include "Search.hpp"

Search::Search() {

}


bool Search::forwardCriterion (std::vector<glm::vec2>& modelCloud, std::vector<glm::vec2>& imageCloud, float f, float t) {
    return Distances::hDKth(modelCloud, imageCloud, f) < t;
}

bool Search::reverseCriterion (std::vector<glm::vec2>& modelCloud, std::vector<glm::vec2>& imageCloud, float f, float t) {
    return Distances::hDKth(imageCloud, modelCloud, f) < t;
}


Transforms Search::search(std::vector<glm::vec2>& modelCloud, std::vector<glm::vec2>& imageCloud, std::vector<glm::mat3> transforms) {
    std::cout << "Starting search" << std::endl;

    Transforms validTrans;
    #pragma omp parallel for
    for (unsigned int i = 0; i < transforms.size(); i++) {
        std::vector<glm::vec2> tmpModel = Cloud::transformCloud(modelCloud, transforms[i]);
        Cloud::Box box = Cloud::getBox(tmpModel);
        std::vector<glm::vec2> subImage = Cloud::getSubCloud(imageCloud, box);
        double dist = Distances::Hf2(tmpModel, subImage, 0.5);
        std::cout << "dist = " << dist << std::endl;
        //TODO Set good condition to select a transform
        if (dist < 2*std::sqrt(2))
            validTrans.emplace_back(transforms[i]);
        //std::cout << float(i+1)/float(transforms.size())*100.f << "%" << std::endl;
    }
    return validTrans;
}

Transforms Search::search(std::vector<glm::vec2> &modelCloud, std::vector<glm::vec2> &imageCloud, std::vector<glm::mat3> transforms, float ff, float fr, float tf, float tr) {
    std::cout << "Starting search" << std::endl;

    Transforms validTrans;
    //#pragma omp parallel for
    for (unsigned int i = 0; i < transforms.size(); i++) {
        std::cout << "search : " << ((float)i*100/(float)(transforms.size())) << "%"<< std::endl;
        std::vector<glm::vec2> tmpModel = Cloud::transformCloud(modelCloud, transforms[i]);
        Cloud::Box box = Cloud::getBox(tmpModel);
        std::vector<glm::vec2> subImage = Cloud::getSubCloud(imageCloud, box);
        double dist = Distances::Hf2(tmpModel, subImage, fr, ff);
        std::cout << "dist = " << dist << std::endl;

        //TODO Set good condition to select a transform
        if (forwardCriterion(tmpModel, subImage, ff, tf) && reverseCriterion(tmpModel, subImage, fr, tr))
            validTrans.emplace_back(transforms[i]);
        //std::cout << float(i+1)/float(transforms.size())*100.f << "%" << std::endl;
    }
    return validTrans;
}
