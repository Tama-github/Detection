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

    /*
        return min distance(L2) between indth point of m and image
    */
    static double delta(Cloud& model, Cloud& image, uint ind);
    static double deltap(Cloud& model, Cloud& image, float x, float y, float w, float h);

    static double f(Cloud& model, Cloud& image, double thau);
   // static double probe (std::vector<glm::vec2>& A, )

private:


};

#endif // DISTANCES_H
