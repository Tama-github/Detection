#include "Search.hpp"

Search::Search() {

}


bool Search::forwardCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t) {
    return Distances::f(modelCloud, imageCloud, double(t)) >= double(f);
    //return Distances::hDKth(modelCloud, imageCloud, f) < t;
}

bool Search::reverseCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t) {
    return Distances::f(modelCloud, imageCloud, double(t)) >= double(f);
    //return Distances::hDKth(imageCloud, modelCloud, f) < t;
}


/*Transforms Search::search(Cloud& modelCloud, Cloud& imageCloud, std::vector<glm::mat3> transforms) {
    std::cout << "Starting search" << std::endl;

    Transforms validTrans;
    #pragma omp parallel for
    for (uint i = 0; i < uint(transforms.size()); i++) {
        Cloud tmpModel = modelCloud.transformCloud(transforms[i]);
        Cloud::Box box = tmpModel.getBox();
        Cloud subImage = imageCloud.getSubCloud(box);
        double dist = Distances::Hf2(tmpModel, subImage, 0.5);
        std::cout << "dist = " << dist << std::endl;
        //TODO Set good condition to select a transform
        if (dist < 2*std::sqrt(2))
            validTrans.emplace_back(transforms[i]);
        //std::cout << float(i+1)/float(transforms.size())*100.f << "%" << std::endl;
    }
    return validTrans;
}*/

/*Transforms Search::search(Cloud &modelCloud, Cloud &imageCloud, std::vector<glm::mat3>& transforms, float ff, float fr, float tf, float tr) {
    std::cout << "Starting search" << std::endl;

    Transforms validTrans;

    uint nbTranslations = uint(imageCloud.getBox().xMax * imageCloud.getBox().yMax);
    #pragma omp parallel for
    for (uint t = 0; t < nbTranslations; t++) {
        for (uint j = 0; j < transforms.size(); j++) {

            glm::mat3 translation = Raster::getTranslation(transforms, t, j, uint(imageCloud.getBox().xMax), uint(imageCloud.getBox().yMax));

            Cloud tmpModel = modelCloud.transformCloud(translation);
            Cloud::Box box = tmpModel.getBox(tmpModel.getVector());

            Cloud subImage = imageCloud.getSubCloud(box);

            if (forwardCriterion(tmpModel, subImage, ff, tf) && reverseCriterion(tmpModel, subImage, fr, tr)) {
                #pragma omp critical
                {
                    validTrans.emplace_back(translation);
                }
            }
        }
        std::cout << "search : " << (float(t)*100.f/float(nbTranslations)) << "%"<< std::endl;
    }


        //std::cout << float(i+1)/float(transforms.size())*100.f << "%" << std::endl;
    return validTrans;
}*/
