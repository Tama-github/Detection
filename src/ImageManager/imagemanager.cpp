#include "imagemanager.hpp"

cv::Mat ImageManager::imread(std::string fileName) {
    cv::Mat img;

    try{
        img = cv::imread("../Ressources/"+fileName, CV_LOAD_IMAGE_GRAYSCALE);
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

    std::string path = getEnvPath() + fileName;

    try {
        res = cv::imwrite(path,img);
    }
    catch (std::exception& ex) {
        std::cout << "Exception converting image to PNG format: " << ex.what();
    }
    return res;
}

Cloud ImageManager::getCoord(cv::Mat img){
    cv::Mat edge,matCloud;
    cv::Canny(img,edge,50,150);

    cv::findNonZero(edge,matCloud);

    std::vector<glm::vec2> cloud;

    for (unsigned int i = 0; i < matCloud.total(); i++ ) {
        cloud.push_back(glm::vec2(matCloud.at<cv::Point>(int(i)).x,matCloud.at<cv::Point>(int(i)).y));
        //std::cout << "Zero#" << i << ": " << cloud.at<cv::Point>(i).x << ", " << cloud.at<cv::Point>(i).y << std::endl;
    }

    edge.release();
    matCloud.release();

    return Cloud(cloud);
}

Cloud ImageManager::getCoord(std::string fileName) {
    return getCoord(imread(fileName));
}

//In work in progress
void ImageManager::cloudToImage(Cloud& cloud, cv::Mat& img) {
    Cloud::Box box = cloud.getBox();
    std::cout << "cloudToImage: "<<box.xMin<<", "<<box.xMax<<", "<<box.yMin<<", "<<box.yMax<<std::endl;
    float tmp = std::abs(std::min(box.xMin, box.yMin));
    box.xMin += tmp;
    box.xMax += tmp;
    box.yMin += tmp;
    box.yMax += tmp;
    std::cout << "cloudToImage: "<<box.xMin<<", "<<box.xMax<<", "<<box.yMin<<", "<<box.yMax<<std::endl;

    /*cv::Mat*/ img = cv::Mat::zeros(int(box.yMax), int(box.xMax), CV_8S);

    std::cout << "coucou 1" << std::endl;

    for (unsigned int i = 0; i < cloud.size(); i++) {
        int x = int(cloud[i][0]);
        int y = int(cloud[i][1]);
        img.at<float>(int(x+(y*box.xMax))) = 255;
    }
    std::cout << "coucou 2 " << img.total() << std::endl;

    return;
}

std::string ImageManager::getEnvPath() {
    std::string env = std::getenv("PWD");
    
    std::size_t pos = env.find("build");

    return env.substr(0,pos) + "Ressources/";
}





