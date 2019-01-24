#ifndef SEARCH_HPP
#define SEARCH_HPP

#include "Distances/distances.hpp"
#include "Cloud/cloud.hpp"

#include <vector>
#include <glm/glm.hpp>
#include <limits>
#include <omp.h>
#include <Raster/raster.hpp>

//typedef std::vector<glm::vec2> Cloud;
typedef std::vector<glm::mat3> Transforms;


class Search
{
public:
    Search(cv::Mat &_transDist);

    Transforms search(Cloud &modelCloud, Cloud &imageCloud, float ff, float fr, float tf, float tr);

private:
    bool forwardCriterion (Cloud& modelCloud, cv::Mat &imageCloud, float f, float t);
    bool forwardCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t);

    bool reverseCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t);

    cv::Mat& transDist;
};

#endif // SEARCH_HPP
