#ifndef CLOUD_HPP
#define CLOUD_HPP

#include <vector>
#include <glm/glm.hpp>
#include <iostream>

class Cloud
{
public:

    Cloud();
    Cloud(std::vector<glm::vec2> vectorPoints);
    Cloud(const Cloud&);

    struct Box {
        float xMin;
        float xMax;
        float yMin;
        float yMax;
    };

    Box getBox(std::vector<glm::vec2>& cloud);
    Box getBox();
    uint size();

    std::vector<glm::vec2>& getVector();

    Cloud getSubCloud(Box box);

    Cloud transformCloud(glm::mat3 transform);

    void transform(glm::mat3 transform);

    glm::vec2& operator[](uint idx);

private:
    std::vector<glm::vec2> cloud;
    Box box;

};

#endif // CLOUD_HPP
