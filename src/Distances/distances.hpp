#ifndef DISTANCES_H
#define DISTANCES_H

#include <opencv2/opencv.hpp>
#include <algorithm>
#include <vector>
#include <glm/glm.hpp>
#include <limits>
#include "Cloud/cloud.hpp"

class Distances
{
public:
    static double Hf1 (Cloud& A, Cloud& B, float k);
    static double Hf2 (Cloud& A, Cloud& B, float k);
    static double Hf2 (Cloud& A, Cloud& B, float fr, float ff);
    static double Hf3 (Cloud& A, Cloud& B, float k);
    static double Hf4 (Cloud& A, Cloud& B, float k);

    static double hDKth(Cloud &A, Cloud &B, float k);

   // static double probe (std::vector<glm::vec2>& A, )

private:


};

#endif // DISTANCES_H
