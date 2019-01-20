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

float Raster::clamp2N(float X) {
    bool stop = false;
    float u = 2;
    for (int i = 1; i < 16; i++) {
        if (X < u) {
            return u;
        }
        u = 2*u;
    }
    return -1;
}

std::vector<glm::mat3> Raster::genTransformations(float xMax, float yMax, float aMax, float sMax, float dMin, float dMax) {
    std::cout << "Starting transform compute" << std::endl;
    std::vector<glm::mat3> res = {};
    // Definition of the unitary displacement on each dimension of the trasformation space.
    float i1 = 1/xMax;
    float i2 = 1/yMax;
    float i3 = 1/xMax;
    float i4 = 1/yMax;
    float i5 = 1.f;
    float i6 = 1.f;

    //initialisation of the first tl
    float tl1, tl2, tl3, tl4, tl5, tl6;
    tl1 = tl2 = tl3 = tl4 = -1.f;
    tl5 = tl6 = 0.f;

    //initialisation of the first th
    float th1, th2, th3, th4, th5, th6;
    th1 = th2 = th3 = th4 = 1.f;
    th5 = xMax;
    th6 = yMax;

    //Clamp of the cell edges to the first greater 2^N
    float xSize = 2.f/i1;
    float ySize = 2.f/i2;

    std::cout << "Before the clamping " << std::endl;
    std::cout << "xMax = " << xMax << std::endl;
    std::cout << "yMax = " << yMax << std::endl;
    std::cout << "i1|i3 = " << i1 << std::endl;
    std::cout << "i2|i4 = " << i2 << std::endl;

    std::cout << "taille de la  cellule sur i1|i3 = " << xSize << std::endl;
    std::cout << "taille de la  cellule sur i2|i4 = " << ySize << std::endl;
    std::cout << "taille de la  cellule sur i5 = " << xMax << std::endl;
    std::cout << "taille de la  cellule sur i6 = " << yMax << std::endl;

    xSize = clamp2N(xSize);
    ySize = clamp2N(ySize);
    xMax = clamp2N(xMax);
    yMax = clamp2N(yMax);

    //Uniformisation
    xSize = ySize = xMax = yMax = std::max(std::max(xSize,ySize),std::max(xMax,yMax));

    //Convertion to axis
    th1 = th3 = (xSize * i1);
    th2 = th4 = (ySize * i2);
    th5 = th6 = xMax;
    std::cout << "After the clamping " << std::endl;

    std::cout << "th1|th3 = " << th1 << std::endl;
    std::cout << "th2|th4 = " << th2 << std::endl;
    std::cout << "th5 = " << th5 << std::endl;
    std::cout << "th6 = " << th6 << std::endl;

    std::cout << "taille de la  cellule sur th1|th3 = " << th1/i1 << std::endl;
    std::cout << "taille de la  cellule sur th2|th4 = " << th2/i2 << std::endl;
    std::cout << "taille de la  cellule sur th5 = " << th5 << std::endl;
    std::cout << "taille de la  cellule sur th6 = " << th6 << std::endl;

    CellTree tree = CellTree(tl5, th5, tl6, th6, tl1, th1, tl2, th2, tl3, th3, tl4, th4, i1, i2, i3, i4, i5, i6);

    tree.subdivideCell();
    tree.displayMe();


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

