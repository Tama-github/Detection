#include "imagemanager.hpp"

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

std::vector<glm::vec2> ImageManager::getCoord(cv::Mat img){
    cv::Mat edge,matCloud;
    cv::Canny(img,edge,50,150);

    cv::findNonZero(edge,matCloud);

    std::vector<glm::vec2> cloud;

    for (int i = 0; i < matCloud.total(); i++ ) {
        cloud.push_back(glm::vec2(matCloud.at<cv::Point>(i).x,matCloud.at<cv::Point>(i).y));
        //std::cout << "Zero#" << i << ": " << cloud.at<cv::Point>(i).x << ", " << cloud.at<cv::Point>(i).y << std::endl;
    }

    edge.release();
    matCloud.release();

    return cloud;
}
