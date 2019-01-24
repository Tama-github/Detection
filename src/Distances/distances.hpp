#ifndef DISTANCES_H
#define DISTANCES_H

#include <opencv2/opencv.hpp>
#include <algorithm>
#include <vector>
#include <glm/glm.hpp>
#include <limits>
#include "Cloud/cloud.hpp"
#include "../ImageManager/imagemanager.hpp"

class Distances
{
public:
    static double Hf1 (Cloud& A, Cloud& B, float k);
    static double Hf2 (Cloud& A, Cloud& B, float k);
    static double Hf2 (Cloud& A, Cloud& B, float fr, float ff);
    static double Hf3 (Cloud& A, Cloud& B, float k);
    static double Hf4 (Cloud& A, Cloud& B, float k);

    static double hDKth(Cloud &A, Cloud &B, float k);


    static double delta(Cloud& model, Cloud& image, uint ind);
    static double delta(float x, float y, cv::Mat &image);
    static double deltap(Cloud& model, cv::Mat &image, float x, float y, float w, float h);

    static double f(Cloud& model, Cloud& image, double thau);
    static double f(Cloud& model, cv::Mat& image, double thau);
    static double fp(Cloud& model, cv::Mat& imageCloud, double t, float w, float h);

    static cv::Mat distanceTransform(cv::Mat& img);


private:


};

#endif // DISTANCES_H
