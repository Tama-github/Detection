#include "raster.hpp"

Raster::Raster() {

}


bool isInImage(Cloud& model, float xMax, float yMax, glm::mat3 transform) {

    Cloud newModel = model.transformCloud(transform);
    for (unsigned int i = 0; i < newModel.size(); i++) {
        float x = newModel[i][0];
        float y = newModel[i][1];
        //std::cout << "x : " << x << ", y : " << y << std::endl;
        if (x < 0 || y < 0)
            return false;
        if (x > xMax || y > yMax)
            return false;

    }
    return true;
}

bool Raster::isValid(float aMax, float sMax, float dMin, float dMax, glm::mat3 transform) {
    float a00 = transform[0][0];
    float a01 = transform[0][1];
    float a10 = transform[1][0];
    float a11 = transform[1][1];

    float det = a00*a11 - a01*a10;
    bool skewTest = std::max((std::sqrt(a00*a00 + a10*a10)/(std::sqrt(a01*a01 + a11*a11))), (std::sqrt(a01*a01 + a11*a11)/(std::sqrt(a00*a00 + a10*a10)))) <= aMax;
    bool scaleTest = (std::abs(a00*a01 + a10*a11)/(std::sqrt(a00*a00 + a10*a10) * std::sqrt(a01*a01 + a11*a11))) <= sMax;
    bool detTest = (det > 0) && (det > dMin) && (det < dMax);
    if (skewTest && scaleTest && detTest)
        return true;
    return false;
}

std::vector<glm::mat3> Raster::getTranslations(std::vector<glm::mat3>& transforms, uint nTranslation, uint xMax, uint yMax) {


    uint totalTransforms = uint(xMax * yMax);

    if (totalTransforms < nTranslation)
        nTranslation = totalTransforms;
    std::vector<glm::mat3> trans;
    int xTranslation = int(nTranslation / xMax);
    int yTranslation = int(nTranslation % yMax);

    for (uint t = 0; t < uint(transforms.size()); t++) {
        glm::mat3 newTrans = transforms[t];
        newTrans[0][2] = xTranslation;
        newTrans[1][2] = yTranslation;
        trans.emplace_back(newTrans);
    }
    return trans;
}

glm::mat3 Raster::getTranslation(std::vector<glm::mat3>& transforms, uint nTranslation, uint nTransform, uint xMax, uint yMax) {
    uint totalTransforms = uint(xMax * yMax);

    if (totalTransforms < nTranslation)
        nTranslation = totalTransforms;
    glm::mat3 trans;
    int xTranslation = int(nTranslation / xMax);
    int yTranslation = int(nTranslation % yMax);
    std::cout << "coucou1" << std::endl;
    std::cout << "nTransform : " << nTransform << ", transfoSize ! " << transforms.size()  << std::endl;

    glm::mat3 newTrans = transforms[nTransform];
    newTrans[0][2] = xTranslation;
    newTrans[1][2] = yTranslation;
    std::cout << "coucou2" << std::endl;
    trans = newTrans;

    return trans;
}

void Raster::computeTranslations(std::vector<glm::mat3>& transforms, Cloud& model, float xMax, float yMax) {
    //std::vector<glm::mat3> newTransforms = transforms;
    #pragma omp parallel for
    for (unsigned int t = 0; t < transforms.size(); t++) {
        std::cout << "Raster::computeTranslations  : " << ((float)t*100/(float)(transforms.size())) << "%"<< std::endl;
        for (unsigned int i = 0; i < xMax; i+= xMax/10) {
            for (unsigned int j = 0; j < yMax; j+= yMax/10) {
                glm::mat3 m = transforms[t];
                m[0][2] += i;
                m[1][2] += j;
                //if(isInImage(model, xMax, yMax, m))
                  //  newTransforms.emplace_back(m);
                #pragma omp critical
                {
                    transforms.emplace_back(m);
                }
            }
        }
        //std::cout << "coucou " << (t+1)/float(transforms.size())*100 << std::endl;
    }
    //transforms = newTransforms;
    //return;
}


std::vector<glm::mat3> Raster::genTransformations(float xMax, float yMax, float aMax, float sMax, float dMin, float dMax) {
    std::cout << "Starting transform compute" << std::endl;

    float i1 = 1/xMax;
    float i2 = 1/yMax;
    float i3 = 1/xMax;
    float i4 = 1/yMax;
    std::vector<glm::mat3> res;
    for (float i = -1.f; i < 1.f; i+=i1) {
        for (float j = -1.f; j < 1.f; j+=i2) {
            for (float k = -1.f; k < 1.f; k+=i3) {
                for (float l = -1.f; l < 1.f; l+=i4) {
                    glm::mat3 m = glm::mat3(0);
                    m[0][0] = i;
                    m[0][1] = k;
                    m[1][0] = j;
                    m[1][1] = l;
                    m[2][2] = 1;
                    if (isValid(aMax, sMax, dMin, dMax, m))
                        res.emplace_back(m);
                }
            }
        }
        std::cout << "advencement[-1,1] : " << i <<  std::endl;
    }
    return res;
}


std::vector<glm::mat3> Raster::transformFilter(std::vector<glm::mat3>& transforms, float xMax, float yMax, Cloud& model) {
    std::vector<glm::mat3> newTransforms;
    for (unsigned int i = 0; i < transforms.size(); i++) {
        if(isInImage(model, xMax, yMax, transforms[i]))
            newTransforms.emplace_back(transforms[i]);
    }
    return newTransforms;
}

