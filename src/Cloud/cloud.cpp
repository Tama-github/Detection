#include "cloud.hpp"

/*Cloud::Cloud() {

}*/

Cloud::Cloud() {}



std::vector<glm::vec2> Cloud::getSubCloud(std::vector<glm::vec2>&cloud, Box box) {
    std::vector<glm::vec2> newCloud;

    float xMin = box.xMin;
    float xMax = box.xMax;
    float yMin = box.yMin;
    float yMax = box.yMax;

    for (unsigned int i = 0; i < cloud.size(); i++) {
        float x = cloud[i][0];
        float y = cloud[i][1];
        if ((x >= xMin && x <= xMax) && (y >= yMin && y <= yMax))
            newCloud.emplace_back(glm::vec2(x, y));
    }
    return newCloud;
}


std::vector<glm::vec2> Cloud::transformCloud(std::vector<glm::vec2>& cloud, glm::mat3 transform) {

    std::vector<glm::vec2> newCloud;
    for (unsigned int i = 0; i < cloud.size(); i++) {
        glm::vec3 temp = transform * glm::vec3(cloud[i][0], cloud[i][1], 1);
        newCloud.emplace_back(glm::vec2(temp[0], temp[1]));
    }
    return newCloud;
}

Cloud::Box Cloud::getBox(std::vector<glm::vec2>& cloud) {
    float xMin = std::numeric_limits<float>::max();
    float xMax = -1;
    float yMin = std::numeric_limits<float>::max();
    float yMax = -1;

    for (unsigned int i = 0; i < cloud.size(); i++) {

        float x = cloud[i][0];
        float y = cloud[i][1];

        if (xMin > x)
            xMin = x;
        if (xMax < x)
            xMax = x;
        if (yMin > y)
            yMin = y;
        if (yMax < y)
            yMax = y;
    }

    return Box{xMin, xMax, yMin, yMax};
}

