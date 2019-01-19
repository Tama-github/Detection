#ifndef SEARCH_HPP
#define SEARCH_HPP

#include "Distances/distances.hpp"
#include "Cloud/cloud.hpp"

#include <vector>
#include <glm/glm.hpp>
#include <limits>
#include <omp.h>

//typedef std::vector<glm::vec2> Cloud;
typedef std::vector<glm::mat3> Transforms;


class Search
{
public:
    Search();

    //Return a set of transforms
    Transforms search(Cloud &modelCloud, Cloud &imageCloud, std::vector<glm::mat3> transforms);
    Transforms search(Cloud &modelCloud, Cloud &imageCloud, std::vector<glm::mat3> transforms, float ff, float fr, float tf, float tr);

};

#endif // SEARCH_HPP
