#ifndef SEARCH_HPP
#define SEARCH_HPP

#include "Distances/distances.hpp"

#include <vector>
#include <glm/glm.hpp>
#include <limits>

typedef std::vector<glm::vec2> Cloud;
typedef std::vector<glm::mat3> Transforms;


class Search
{
public:
    Search();

    struct Box {
        float xMin;
        float xMax;
        float yMin;
        float yMax;
    };

    //Return a set of clouds
    Transforms search(const std::vector<glm::vec2> &modelCloud, const std::vector<glm::vec2> &imageCloud, std::vector<glm::mat3> transforms);

private:


    Box getBox(const std::vector<glm::vec2>& cloud);

    Cloud getSubCloud(const std::vector<glm::vec2>& cloud, Box box);

    Cloud transformCloud(const std::vector<glm::vec2>& cloud, glm::mat3 transform);

};

#endif // SEARCH_HPP
