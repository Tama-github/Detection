#ifndef IMAGEMANAGER_HPP
#define IMAGEMANAGER_HPP

#include <iostream>
#include <opencv2/opencv.hpp>

class ImageManager
{
public:
    ImageManager();
    ~ImageManager();
    cv::Mat imread(std::string fileName);
    bool imwrite(const std::string& fileName, cv::Mat img);
    // Transform l'image en nuage de point (imread>Canny>Nuage)
    // Type getCoord()
};

#endif // IMAGEMANAGER_HPP
