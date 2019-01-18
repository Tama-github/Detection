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
    Transforms search(std::vector<glm::vec2> &modelCloud, std::vector<glm::vec2> &imageCloud, std::vector<glm::mat3> transforms);
    Transforms search(std::vector<glm::vec2> &modelCloud, std::vector<glm::vec2> &imageCloud, std::vector<glm::mat3> transforms, float ff, float fr, float tf, float tr);

private:
    bool forwardCriterion (std::vector<glm::vec2>& modelCloud, std::vector<glm::vec2>& imageCloud, float f, float t);
    bool reverseCriterion (std::vector<glm::vec2>& modelCloud, std::vector<glm::vec2>& imageCloud, float f, float t);

};

#endif // SEARCH_HPP
