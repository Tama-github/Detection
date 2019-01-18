#ifndef RASTER_H
#define RASTER_H

#include <opencv2/opencv.hpp>
#include <algorithm>
#include <vector>
#include <glm/glm.hpp>
#include <Cloud/cloud.hpp>

class Raster
{
public:
    Raster();
   // std::vector<glm::mat3> genTransformations (float xMax, float yMax, float aMax, float sMax, float dMin, float dMax);
    std::vector<glm::mat3> genTransformations(float xMax, float yMax, float aMax, float sMax, float dMin, float dMax);
    bool isValid(float aMax, float sMax, float dMin, float dMax, glm::mat3 transform);

    std::vector<glm::mat3> transformFilter(std::vector<glm::mat3>& transforms, float xMax, float yMax, std::vector<glm::vec2>& model);
    void computeTranslations(std::vector<glm::mat3>& transforms, std::vector<glm::vec2>& model, float xMax, float yMax);

};

#endif // RASTER_H
