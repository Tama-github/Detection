#include "cloud.hpp"

/*Cloud::Cloud() {

}*/

Cloud::Cloud() {
    cloud = std::vector<glm::vec2>();
    box = Box{0.f, 0.f, 0.f, 0.f};
}

Cloud::Cloud(std::vector<glm::vec2> vectorPoints) {
    cloud = vectorPoints;
    box = getBox(cloud);
}

Cloud::Cloud(const Cloud& c) {
    cloud = c.cloud;
    box = c.box;
}

glm::vec2& Cloud::operator[](uint idx) {
    return cloud[idx];
}

Cloud Cloud::getSubCloud(Box box) {
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
    return Cloud(newCloud);
}


Cloud Cloud::transformCloud(glm::mat3 transform) {

    std::vector<glm::vec2> newCloud;
    for (unsigned int i = 0; i < cloud.size(); i++) {
        glm::vec3 temp = glm::vec3(cloud[i][0], cloud[i][1], 1) * transform;
        newCloud.emplace_back(glm::vec2(temp[0], temp[1]));
    }
    return Cloud(newCloud);
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

void Cloud::transform(glm::mat3 transform) {
    for (unsigned int i = 0; i < cloud.size(); i++) {
        glm::vec3 tmp = glm::vec3(cloud[i][0], cloud[i][1], 1) * transform;
        cloud[i] = glm::vec2(tmp[0], tmp[1]);
    }
}

Cloud::Box Cloud::getBox() {
    return box;
}

std::vector<glm::vec2>& Cloud::getVector() {
    return cloud;
}

uint Cloud::size() {
    return uint(cloud.size());
}
