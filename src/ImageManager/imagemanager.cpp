#include "imagemanager.hpp"

ImageManager::ImageManager() {
    std::cout<<"ImageManager : Creation"<<std::endl;
}

ImageManager::~ImageManager() {
    std::cout<<"ImageManager : Destruction"<<std::endl;
}

cv::Mat ImageManager::imread(std::string fileName) {
    cv::Mat img;
    std::string path = "../Ressources/" + fileName;

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

    std::string path = "../Ressources/" + fileName;

    try {
        res = cv::imwrite(path,img);
    }
    catch (std::exception& ex) {
        std::cout << "Exception converting image to PNG format: " << ex.what()
                     ;
    }
    return res;
}
