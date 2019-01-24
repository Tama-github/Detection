#include "Search.hpp"

Search::Search(cv::Mat& _transDist) : transDist{_transDist}{

}


bool Search::forwardCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t) {
    double fRes = Distances::f(modelCloud, imageCloud, double(t));
    return fRes >= double(f);
}

bool Search::forwardCriterion (Cloud& modelCloud, cv::Mat& imageCloud, float f, float t) {
    double fRes = Distances::f(modelCloud, imageCloud, double(t));
    return fRes >= double(f);
}

bool Search::reverseCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t) {
    double fRes = Distances::f(modelCloud, imageCloud, double(t));
    return fRes >= double(f);
}

Transforms Search::search(Cloud &modelCloud, Cloud &imageCloud, float ff, float fr, float tf, float tr) {
    std::vector<glm::mat3> transforms;
    std::cout << "Starting research on translations only." << std::endl;
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
            Cloud subCloud = imageCloud.getSubCloud(box);
            bool fCriterion = forwardCriterion(tmp, subCloud, ff, tf);
            bool rCriterion = false;
            if (fCriterion)
                rCriterion = reverseCriterion(subCloud, tmp, fr, tr);
            if (rCriterion && fCriterion) {
                transforms.emplace_back(mat);
            }
        }
        std::cout << float(i)/xTransMax*100.f << "%" << std::endl;
    }

    return transforms;
}
