#include "raster.hpp"

Raster::Raster(Cloud& _model, Cloud& _image, cv::Mat& _transFormImage) : model{_model}, image{_image}, transformImage{_transFormImage} {

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



bool Raster::forwardCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t) {
    return Distances::f(modelCloud, imageCloud, double(t)) >= double(f);
}

bool Raster::reverseCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t) {
    return Distances::f(modelCloud, imageCloud, double(t)) >= double(f);
}

bool Raster::isCellInteresting(Cloud& modelCloud, cv::Mat& imageCloud, float f, float t, float w, float h) {
    return Distances::fp(modelCloud, imageCloud, double(t), w, h) >= double(f);
}

std::vector<glm::mat3> Raster::genTransformations(float xMax, float yMax, float aMax, float sMax, float dMin, float dMax, float ff, float fr, float tf, float tr) {
    std::cout << "Starting cell decomposition algorythm" << std::endl;
    std::vector<glm::mat3> res = {};
    // Definition of the unitary displacement on each dimension of the trasformation space.
    float i1 = 1/xMax;
    float i2 = 1/yMax;
    float i3 = 1/xMax;
    float i4 = 1/yMax;
    float i5 = 1.f;
    float i6 = 1.f;

    std::cout << "Space base vector : " << "(" << i1 << "," << i2 << "," << i3 << "," << i4 << "," << i5 << "," << i6 <<  ")" << std::endl;

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


    xSize = clamp2N(xSize);
    ySize = clamp2N(ySize);
    xMax = clamp2N(xMax);
    yMax = clamp2N(yMax);

    //Uniformisation
    xSize = ySize = xMax = yMax = std::max(std::max(xSize,ySize),std::max(xMax,yMax));
    xSize -= 1.f/i1;
    ySize -= 1.f/i2;

    //Convertion to axis
    th1 = th3 = (xSize * i1);
    th2 = th4 = (ySize * i2);
    th5 = th6 = xMax;

    //Space creation on the root cell
    CellTree tree = CellTree(0, xMax-1, 0, xMax-1, -1.f/i1, xSize-1, -1.f/i2, ySize-1, -1.f/i3, xSize-1, -1.f/i4, ySize-1, i1, i2, i3, i4, i5, i6);

    tree.subdivideCell6D();

    std::vector<CellTree*> cells = tree.getChilds();
    for (uint i = 0; i < cells.size(); i++) {
        CellTree* currentCell = cells[i];
        std::cout << "(pourcentage / depth = " << currentCell->depth << ")  " << (float(i+1)*100.f/float(cells.size())) << "%" << std::endl;

        if (currentCell->hasOneElem()) {
            glm::mat3 matrix = currentCell->getTransformTL();
            Cloud transformModel = model.transformCloud(matrix);
            Cloud subImage = image.getSubCloud(transformModel.getBox());

            if (isValid(aMax, sMax, dMin, dMax, matrix) && reverseCriterion(transformModel, subImage, fr, tr))
                res.emplace_back(matrix);

        } else {
            glm::mat3 matrix = currentCell->getTransformTL();
            Cloud transformModel = model.transformCloud(matrix);
            bool isInteresting = isCellInteresting(transformModel, transformImage, ff, tf, std::abs(currentCell->w), std::abs(currentCell->h));
            if (isInteresting) {
                currentCell->subdivideCell6D();
                std::vector<CellTree*> tmp = currentCell->getChilds();
                cells.erase(cells.begin());
                cells.insert(cells.begin(), tmp.begin(), tmp.end());
            } else {
                cells.erase(cells.begin());
            }
            i--;
        }
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

