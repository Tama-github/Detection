#include "imagemanager.hpp"

#include <opencv2/core/core.hpp>


cv::Mat ImageManager::imread(std::string fileName) {
    cv::Mat img;
    std::string path = "../../Ressources/" + fileName;

    try{
        img = cv::imread(path, CV_LOAD_IMAGE_GRAYSCALE);
        if(!img.data)
            throw std::invalid_argument("File not found or not supported");
    } catch (std::exception& ex) {
        std::cerr<< "Exception reading file " << fileName << " : " << ex.what() << std::endl;
        exit(1);
    }
    return img;
}

bool ImageManager::imwrite(const std::string &fileName, cv::Mat img) {
    bool res = false;

    std::string path = "../../Ressources/" + fileName;

    try {
        res = cv::imwrite(path,img);
    }
    catch (std::exception& ex) {
        std::cout << "Exception converting image to PNG format: " << ex.what();
    }
    return res;
}

int ** ImageManager::getCoord(cv::Mat img){
    cv::Mat edge,cloud;
    cv::Canny(img,edge,50,150);

    cv::findNonZero(edge,cloud);


    for (int i = 0; i < cloud.total(); i++ ) {
        std::cout << "Zero#" << i << ": " << cloud.at<cv::Point>(i).x << ", " << cloud.at<cv::Point>(i).y << std::endl;
    }

    edge.release();
    cloud.release();

    return nullptr;
}
