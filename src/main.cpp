#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "ImageManager/imagemanager.hpp"
#include "CellTree/CellTree.hpp"
#include "Raster/raster.hpp"
#include "Search/Search.hpp"


int main(int, char *[]) {
    //Initialization of Image Manager
    //cv::WINOWS_AUTORIZE;


    std::string imName = "xerox_img";
    std::string modelName = "xerox_model.png";

    ImageManager *im = new ImageManager();
    Cloud modelC = im->getCoord(modelName);
    Cloud imageC = im->getCoord(imName + ".png");
    cv::Mat img;

    img = im->imread(imName + ".png");
    cv::Mat edges;
    cv::Canny(img, edges, 50, 150);
    cv::bitwise_not(edges,edges);
    cv::Mat res;

    cv::distanceTransform(edges,res,CV_DIST_L2, 3);
    im->imwrite(imName + "_DT.png", res);
    //im->imwrite(imName + "_edges.png", edges);

    //std::cout << "Press ENTER to continue...";
    //std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );

    // Param definitions
    float aMax = 2.f;
    float sMax = 0.4f;
    float dMin = 0.3f;
    float dMax = 1.f;
    float ff = 0.8f;
    float fr = 0.5f;
    float tf = std::sqrt(5.f);
    float tr = std::sqrt(5.f);

    float xMax = float(img.cols);
    float yMax = float(img.rows);

    // Décomposition en cellule
    //Raster *raster = new Raster(modelC, imageC, res);
    //std::vector<glm::mat3> transforms = raster->genTransformations(xMax, yMax, aMax, sMax, dMin, dMax, ff, fr, tf, tr);
    //std::cout << "nombre de transformations : " << transforms.size() << std::endl;

    //Translation uniquement
    Search *search = new Search(res);
    std::vector<glm::mat3> transforms = search->search(modelC, imageC, ff, fr, tf, tr);
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
   // delete raster;
    delete search;
    return 0;
}
