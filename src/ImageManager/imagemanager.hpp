#ifndef IMAGEMANAGER_HPP
#define IMAGEMANAGER_HPP

#include <iostream>
#include <opencv2/opencv.hpp>
#include <glm/glm.hpp>
#include <Search/Search.hpp>
#include <Cloud/cloud.hpp>
#include <string>

class ImageManager
{
public:    
    cv::Mat imread(std::string fileName);
    bool imwrite(const std::string& fileName, cv::Mat img);
    // Transforme l'image en nuage de point (imread>Canny>Nuage)
    Cloud getCoord(cv::Mat img);
    Cloud getCoord(std::string fileName);


    // Point cloud to image
    void cloudToImage(Cloud& cloud, cv::Mat& img);

private:
    std::string getEnvPath();

};

#endif // IMAGEMANAGER_HPP
