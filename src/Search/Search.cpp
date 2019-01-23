#include "Search.hpp"

Search::Search(cv::Mat& _transDist) : transDist{_transDist}{

}


bool Search::forwardCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t) {
    double fRes = Distances::f(modelCloud, imageCloud, double(t));

    //std::cout << "forward fRes : " << fRes << std::endl;

    return fRes >= double(f);
    //return Distances::hDKth(modelCloud, imageCloud, f) < t;
}

bool Search::forwardCriterion (Cloud& modelCloud, cv::Mat& imageCloud, float f, float t) {

    double fRes = Distances::f(modelCloud, imageCloud, double(t));

   // std::cout << "forward mat dist : " << fRes << std::endl;

    return fRes >= double(f);
    //return Distances::hDKth(modelCloud, imageCloud, f) < t;
}

bool Search::reverseCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t) {
    double fRes = Distances::f(modelCloud, imageCloud, double(t));

    //std::cout << "reverse mat dist : " << fRes << std::endl;

    return fRes >= double(f);
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

Transforms Search::search(Cloud &modelCloud, Cloud &imageCloud, float ff, float fr, float tf, float tr) {
    std::vector<glm::mat3> transforms;
    std::cout << "Début de la recherche." << std::endl;
    float xModel = modelCloud.getBox().xMax;
    float xImage = imageCloud.getBox().xMax;
    float yModel = modelCloud.getBox().yMax;
    float yImage = imageCloud.getBox().yMax;
    float xTransMax;
    float yTransMax;
    if (xModel < xImage)
        xTransMax = xImage - xModel;
    else
        xTransMax = 1.f;
    if (yModel < yImage)
        yTransMax = yImage - yModel;
    else
        yTransMax = 1.f;
    std::cout << "nombre de translations en x : " << xTransMax << std::endl;
    std::cout << "nombre de translations en y : " << yTransMax << std::endl;


    for (uint i = 0; i < uint(xTransMax); i++) {
        for (uint j = 0; j < uint(yTransMax); j++) {
            glm::mat3 mat = glm::mat3(1.f);
            mat[0][2] = i;
            mat[1][2] = j;
            Cloud tmp = modelCloud.transformCloud(mat);
            Cloud::Box box = tmp.getBox(tmp.getVector());
          //  std::cout << "box : " << box.xMin<<", "<<box.xMax<<", "<<box.yMin<<", "<<box.yMax<<std::endl;
            Cloud subCloud = imageCloud.getSubCloud(box);
            bool fCriterion = forwardCriterion(tmp, subCloud, ff, tf);
            bool rCriterion = false;
            if (fCriterion)
                rCriterion = reverseCriterion(subCloud, tmp, fr, tr);
            if (rCriterion || fCriterion)
                std::cout << "reverse Criterion : " << rCriterion << ", forward criterion : " << fCriterion << std::endl;
            if (rCriterion && fCriterion) {
                transforms.emplace_back(mat);
            }
        }
        std::cout << float(i)/xTransMax*100.f << "%" << std::endl;
    }

    return transforms;
}
