#ifndef RASTER_H
#define RASTER_H

#include <opencv2/opencv.hpp>
#include <algorithm>
#include <vector>
#include <glm/glm.hpp>
#include <Cloud/cloud.hpp>
#include <CellTree/CellTree.hpp>
#include <Distances/distances.hpp>
#include <Cloud/cloud.hpp>

class Raster
{
public:
    Raster(Cloud& model, Cloud& image, cv::Mat& transFormImage);

    std::vector<glm::mat3> genTransformations(float xMax, float yMax, float aMax, float sMax, float dMin, float dMax, float ff, float fr, float tf, float tr);
    bool isValid(float aMax, float sMax, float dMin, float dMax, glm::mat3 transform);

    std::vector<glm::mat3> transformFilter(std::vector<glm::mat3>& transforms, float xMax, float yMax, Cloud& model);
    void computeTranslations(std::vector<glm::mat3>& transforms, Cloud& model, float xMax, float yMax);


private:
    float clamp2N(float X);
    bool forwardCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t);
    bool reverseCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t);
    bool isCellInteresting(Cloud& modelCloud, cv::Mat& imageCloud, float f, float t, float w, float h);

    Cloud& model;
    Cloud& image;
    cv::Mat& transformImage;

};

#endif // RASTER_H
