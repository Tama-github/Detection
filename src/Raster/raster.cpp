#include "raster.hpp"

Raster::Raster()
{

}

std::vector<glm::mat3> Raster::genTransformations (float xMax, float yMax, float aMax, float sMax, float dMin, float dMax) {
    float i1 = 1/xMax;
    float i2 = 1/yMax;
    float i3 = 1/xMax;
    float i4 = 1/yMax;
    float i5 = 1;
    float i6 = 1;
    std::vector<glm::mat3> res;
    for (int i = i1; i < xMax; i+=i1) {
        for (int j = i2; j < yMax; j+=i2) {
            for (int k = i3; k < xMax; k+=i3) {
                for (int l = i4; l < yMax; l+=i4) {
                    float a00 = i;
                    float a01 = k;
                    float a10 = j;
                    float a11 = l;
                    float det = a00*a11 - a01*a10;
                    bool skewTest = std::max((std::sqrt(a00*a00 + a10*a10)/(std::sqrt(a01*a01 + a11*a11))), (std::sqrt(a01*a01 + a11*a11)/(std::sqrt(a00*a00 + a10*a10)))) <= aMax;
                    bool scaleTest = (std::abs(a00*a01 + a10*a11)/(std::sqrt(a00*a00 + a10*a10) * std::sqrt(a01*a01 + a11*a11))) <= sMax;
                    bool detTest = (det > 0) && (det > dMin) && (det < dMax);
                    glm::mat3 m;
                    m[0][0] = a00;
                    m[0][1] = a01;
                    m[1][0] = a10;
                    m[1][1] = a11;
                    m[2][2] = 1;
                    if (skewTest && scaleTest && detTest) res.emplace_back();
                }
            }
        }
    }
    return res;
}

