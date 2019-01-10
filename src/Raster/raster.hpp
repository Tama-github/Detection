#ifndef RASTER_H
#define RASTER_H

#include <opencv2/opencv.hpp>
#include <algorithm>
#include <vector>
#include <glm/glm.hpp>

class Raster
{
public:
    Raster();
    std::vector<glm::mat3> genTransformations (float xMax, float yMax, float aMax, float sMax, float dMin, float dMax);
};

#endif // RASTER_H
