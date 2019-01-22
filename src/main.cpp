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
    std::string imName = "image";
    std::string modelName = "model.png";

    Cloud modelC = im->getCoord(modelName);
    Cloud imageC = im->getCoord(imName + ".png");
    cv::Mat img;

    /*std::cout << "Debut distance transform" << std::endl;
    cv::Mat img = im->imread("image.png");

    img = Distances::distanceTransform(img);

    im->imwrite("sortieDistanceTransform.png", img);
    std::cout << "Fin distance transform" << std::endl;*/
    //cv::Mat imgDT = cv::imread("../Ressources/"+ imName + "_DT.png", CV_LOAD_IMAGE_GRAYSCALE);
    //if (!imgDT.data) {
        img = im->imread(imName + ".png");
        cv::Mat imgDT = Distances::distanceTransform(img);
        std::cout << imgDT.rows << ", " << imgDT.cols << std::endl;
        im->imwrite(imName + "_DT.png", imgDT);
    //}
        /*
    cv::distanceTransform(img, imgDT, CV_DIST_L2, 5);
    cv::normalize(imgDT, imgDT, cv::NORM_MINMAX);
    im->imwrite(imName + "sfjqmslfjmlqs.png", imgDT);
*/


    Raster *raster = new Raster(modelC, imageC, imgDT);



    float aMax = 2.f;
    float sMax = 0.4f;
    float dMin = 0.3f;
    float dMax = 1.f;
    float ff = 1.f;
    float fr = 0.8f;
    float tf = std::sqrt(5.f);
    float tr = std::sqrt(5.f);

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
