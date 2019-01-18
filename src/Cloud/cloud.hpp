#ifndef CLOUD_HPP
#define CLOUD_HPP

#include <vector>
#include <glm/glm.hpp>
#include <iostream>

class Cloud
{
public:


    struct Box {
        float xMin;
        float xMax;
        float yMin;
        float yMax;
    };

    static Box getBox(std::vector<glm::vec2>& cloud);

    static std::vector<glm::vec2> getSubCloud(std::vector<glm::vec2>& cloud, Box box);

    static std::vector<glm::vec2> transformCloud(std::vector<glm::vec2>& cloud, glm::mat3 transform);

private:
        Cloud();
};

#endif // CLOUD_HPP
