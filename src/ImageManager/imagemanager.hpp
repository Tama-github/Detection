#ifndef IMAGEMANAGER_HPP
#define IMAGEMANAGER_HPP

#include <iostream>
#include <opencv2/opencv.hpp>

class ImageManager
{
public:    
    cv::Mat imread(std::string fileName);
    bool imwrite(const std::string& fileName, cv::Mat img);
    // Transforme l'image en nuage de point (imread>Canny>Nuage)
    int** getCoord(cv::Mat img);

};

#endif // IMAGEMANAGER_HPP
