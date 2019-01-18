#include <iostream>
#include <opencv2/opencv.hpp>
#include "ImageManager/imagemanager.hpp"
#include "CellTree/CellTree.hpp"
#include "Raster/raster.hpp"
#include "Search/Search.hpp"


int main(int, char *[]) {
    //Initialization of Image Manager
    ImageManager *im = new ImageManager();
    Raster *raster = new Raster();
    Search *search = new Search();
    std::vector<glm::vec2> modelC = im->getCoord("model.png");
    std::vector<glm::vec2> imageC = im->getCoord("image.png");
    cv::Mat img = im->imread("image.png");

    cv::distanceTransform(img, img, cv::DIST_L2, 3);
    cv::normalize(img, img, 0, 255.0, cv::NORM_MINMAX);
    im->imwrite("distanceTransform.png", img);
/*
    std::vector<glm::mat3> transforms = raster->genTransformations(80, 80, 2.f, 0.4f, 0.3f, 1.f);
    raster->computeTranslations(transforms, modelC, 252, 238);
    std::cout << "nombre de transformations : " << transforms.size() << std::endl;
    //transforms = raster->transformFilter(transforms, 252, 238, modelC);

*/
//suppression
    cv::Size sz = img.size();
    CellTree tree = CellTree(0,300,0,300);
    tree.subdivideCell();

    tree.displayMe();

/*

    std::cout << "is ok, press something" << std::endl;       
    for (unsigned int i = 0; i < transforms.size(); i++) {
        std::cout << "blabla0" << std::endl;
        std::vector<glm::vec2> temp = Cloud::transformCloud(modelC, transforms[i]);
        std::cout << "blabla1" << std::endl;
        cv::Mat imToWrite;
        im->cloudToImage(temp, imToWrite);
        std::cout << "blabla2" << std::endl;
        im->imwrite(std::to_string(i)+".png", imToWrite);
        std::cout << "blabla3" << std::endl;
    }
*/
    return 0;
}
