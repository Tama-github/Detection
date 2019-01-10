#include "Search.hpp"

Search::Search() {

}


std::vector<glm::vec2> Search::getSubCloud(const std::vector<glm::vec2>& cloud, Box box) {
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


std::vector<glm::vec2> Search::transformCloud(const std::vector<glm::vec2>& cloud, glm::mat3 transform) {

    std::vector<glm::vec2> newCloud;
    for (unsigned int i = 0; i < cloud.size(); i++) {
        glm::vec3 temp = transform * glm::vec3(cloud[i][0], cloud[i][1], 1);
        newCloud.emplace_back(glm::vec2(temp[0], temp[1]));
    }
    return newCloud;
}

Search::Box Search::getBox(const std::vector<glm::vec2>& cloud) {
    float xMin = std::numeric_limits<float>::max();
    float xMax = std::numeric_limits<float>::min();
    float yMin = std::numeric_limits<float>::max();
    float yMax = std::numeric_limits<float>::min();

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


Transforms Search::search(const std::vector<glm::vec2>& modelCloud,const std::vector<glm::vec2>& imageCloud, std::vector<glm::mat3> transforms) {

    Transforms validTrans;
    for (unsigned int i = 0; i < transforms.size(); i++) {
        Cloud newModel = transformCloud(modelCloud, transforms[i]);
        Cloud subImage = getSubCloud(imageCloud, getBox(newModel));
        double dist = Distances::Hf2(newModel, subImage, 0.5);
        //TODO Set good condition to select a transform
        //caution, 5 is a random number i've chose
        if (dist < 5)
            validTrans.emplace_back(transforms[i]);

    }
    return validTrans;
}
