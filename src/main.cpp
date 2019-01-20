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

    Cloud modelC = im->getCoord("model.png");
    Cloud imageC = im->getCoord("image_test.png");
    float aMax = 2.f;
    float sMax = 0.4f;
    float dMin = 0.3f;
    float dMax = 1.f;

    //std::vector<glm::mat3> transforms = raster->genTransformations(modelC.getBox().xMax, modelC.getBox().yMax, aMax, sMax, dMin, dMax);
    //for debug
    std::vector<glm::mat3> transforms;
    glm::mat3 tmp = glm::mat3(0.f);
    tmp[0][0] = -1.f;
    tmp[0][1] = -0.26f;
    tmp[1][0] = -1;
    tmp[1][1] = -0.6625f;
    tmp[2][2] = 1.f;
    transforms.emplace_back(tmp);
    tmp[0][0] = -1.f;
    tmp[0][1] = -0.2749f;
    tmp[1][0] = -1.f;
    tmp[1][1] = -0.7f;
    tmp[2][2] = 1.f;
    transforms.emplace_back(tmp);
    tmp[0][0] = -1.f;
    tmp[0][1] = -0.2749f;
    tmp[1][0] = -1.f;
    tmp[1][1] = -0.6875f;
    tmp[2][2] = 1.f;
    transforms.emplace_back(tmp);


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

    float ff = 1.f;
    float fr = 0.8f;
    float tf = 2.f*std::sqrt(2.f);
    float tr = 2.f*std::sqrt(2.f);

    std::vector<glm::mat3> res = search->search(modelC, imageC, transforms, ff, fr, tf, tr);
    std::cout << "Nombre d'instances trouvées : " << res.size() << std::endl;

    delete im;
    delete raster;
    delete search;
    return 0;
}
