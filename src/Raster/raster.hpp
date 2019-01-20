#ifndef RASTER_H
#define RASTER_H

#include <opencv2/opencv.hpp>
#include <algorithm>
#include <vector>
#include <glm/glm.hpp>
#include <Cloud/cloud.hpp>
#include <CellTree/CellTree.hpp>

class Raster
{
public:
    Raster();

    std::vector<glm::mat3> genTransformations(float xMax, float yMax, float aMax, float sMax, float dMin, float dMax);
    bool isValid(float aMax, float sMax, float dMin, float dMax, glm::mat3 transform);

    std::vector<glm::mat3> transformFilter(std::vector<glm::mat3>& transforms, float xMax, float yMax, Cloud& model);
    void computeTranslations(std::vector<glm::mat3>& transforms, Cloud& model, float xMax, float yMax);


private:
    float clamp2N(float X);
//    static glm::mat3 getTranslation(std::vector<glm::mat3>& transforms, uint nTranslation, uint nTransform, uint xMax, uint yMax);
//    static std::vector<glm::mat3> getTranslations(std::vector<glm::mat3>& transforms, uint nTranslation, uint xMax, uint yMax);


};

#endif // RASTER_H
