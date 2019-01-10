#include <iostream>
#include <opencv2/opencv.hpp>
#include "ImageManager/imagemanager.hpp"

int main(int, char *[]) {
    //Initialization of Image Manager
    ImageManager *im = new ImageManager;
    cv::Mat img;
    img = im->imread("de.png");

    im->getCoord(img);
    std::cout << "is ok, press something" << std::endl;
    return 0;
}
