#include <iostream>
#include <opencv2/opencv.hpp>
#include "ImageManager/imagemanager.hpp"
#include "CellTree/CellTree.hpp"
#include "Raster/raster.hpp"
#include "Search/Search.hpp"


int main(int, char *[]) {
    //Initialization of Image Manager
    ImageManager *im = new ImageManager();
    Search *search = new Search();

    Cloud modelC = im->getCoord("model.png");
    Cloud imageC = im->getCoord("image_test.png");

    Raster *raster = new Raster(modelC, imageC);

    cv::Mat img = im->imread("image_test.png");

    float aMax = 2.f;
    float sMax = 0.4f;
    float dMin = 0.3f;
    float dMax = 1.f;
    float ff = 1.f;
    float fr = 0.8f;
    float tf = 2.f*std::sqrt(2.f);
    float tr = 2.f*std::sqrt(2.f);

    float xMax = float(img.cols);
    float yMax = float(img.rows);

    std::vector<glm::mat3> transforms = raster->genTransformations(xMax, yMax, aMax, sMax, dMin, dMax, ff, fr, tf, tr);
    std::cout << "nombre de transformations : " << transforms.size() << std::endl;
    /*raster->computeTranslations(transforms, modelC, img.cols, img.rows);
    std::cout << "nombre de transformations : " << transforms.size() << std::endl;
    transforms = raster->transformFilter(transforms, img.cols, img.rows, modelC);*/



//suppression Valérian
/*    cv::Size sz = img.size();
    CellTree tree = CellTree(0,300,0,300);
    tree.subdivideCell();
    tree.displayMe();

    cv::imshow("Display window",img);
    cv::waitKey(0);

*/
//
    /*std::cout << "is ok, press something" << std::endl;
    #pragma omp parallel for
    for (unsigned int i = 0; i < transforms.size(); i++) {
        std::cout << ((float)i*100/(float)(transforms.size())) << "%"<< std::endl;
        //std::cout << "blabla0" << std::endl;
        std::vector<glm::vec2> temp = Cloud::transformCloud(modelC, transforms[i]);
        //std::cout << "blabla1" << std::endl;
        cv::Mat imToWrite;
        im->cloudToImage(temp, imToWrite);
        //std::cout << "blabla2" << std::endl;
        im->imwrite(std::to_string(i)+".png", imToWrite);
        //std::cout << "blabla3" << std::endl;
    }*/

    /*float ff = 1.f;
    float fr = 0.8f;
    float tf = 2.f*std::sqrt(2.f);
    float tr = 2.f*std::sqrt(2.f);

    search->search(modelC, imageC, transforms, ff, fr, tf, tr);*/

    delete im;
    delete raster;
    delete search;
    return 0;
}
