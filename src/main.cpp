#include <iostream>
#include <opencv2/opencv.hpp>
#include "ImageManager/imagemanager.hpp"

int main(int, char *[]) {
    //Initialization of Image Manager
    ImageManager *im = new ImageManager;
    cv::Mat img,edges;
    img = im->imread("de.png");

    edges = im->Canny(img);

    cv::imshow("Canny",edges);
im->getCoord(img);
    std::cout << "is ok, press something" << std::endl;
    cv::waitKey(0);
    return 0;
}
