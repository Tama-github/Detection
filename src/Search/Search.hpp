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
    Search();

    //Return a set of transforms
    //Transforms search(Cloud &modelCloud, Cloud &imageCloud, std::vector<glm::mat3> transforms);
    //Transforms search(Cloud &modelCloud, Cloud &imageCloud, std::vector<glm::mat3>& transforms, float ff, float fr, float tf, float tr);
    Transforms search(Cloud &modelCloud, Cloud &imageCloud, float ff, float fr, float tf, float tr);

private:
    bool forwardCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t);
    bool reverseCriterion (Cloud& modelCloud, Cloud& imageCloud, float f, float t);

};

#endif // SEARCH_HPP
