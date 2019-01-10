#ifndef RASTER_H
#define RASTER_H


class Raster
{
public:
    Raster();
    std::vector<glm::mat3> genTransformations (xMax, yMax, aMax, sMax, dMin, dMax);
};

#endif // RASTER_H
