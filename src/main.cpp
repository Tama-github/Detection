#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "ImageManager/imagemanager.hpp"
#include "CellTree/CellTree.hpp"
#include "Raster/raster.hpp"
#include "Search/Search.hpp"


int main(int argv, char *argc[]) {

    if (argv != 2) {
        std::cerr << "Usage : " << argc[0] << " (0 ou 1)" << std::endl;
        std::cerr << "0 : algorithme de décomposition en cellule" << std::endl;
        std::cerr << "1 : algorithme avec uniqueent les translations" << std::endl;
        return 1;
    }

    char* algo = argc[1];

    /*********************************************************************************************/
    /************************** Chargement des images d'entré ************************************/
    /*********************************************************************************************/
    std::string imName = "14b";
    std::string modelName = "14a.png";

    ImageManager *im = new ImageManager();
    Cloud modelC = im->getCoord(modelName);
    Cloud imageC = im->getCoord(imName + ".png");
    cv::Mat img;

    /********************************************************************************/
    /************************** Précalcule delta ************************************/
    /********************************************************************************/
    img = im->imread(imName + ".png");
    cv::Mat edges;
    cv::Canny(img, edges, 50, 150);
    cv::bitwise_not(edges,edges);
    cv::Mat res;

    cv::distanceTransform(edges,res,CV_DIST_L2, 3);
    im->imwrite(imName + "_DT.png", res);


    /**********************************************************************************************/
    /************************** Définition des hyper-paramtres ************************************/
    /**********************************************************************************************/

    float aMax = 2.f;
    float sMax = 0.4f;
    float dMin = 0.3f;
    float dMax = 1.f;
    float ff = 0.6f;
    float fr = 0.5f;
    float tf = std::sqrt(5.f);
    float tr = std::sqrt(5.f);

    float xMax = float(img.cols);
    float yMax = float(img.rows);

    /****************************************************************************************/
    /************************** Décomposition en cellule ************************************/
    /****************************************************************************************/

    if (algo[0] == '0') {
        Raster *raster = new Raster(modelC, imageC, res);

        //lancement de l'algorithme basé sur la décomposition en cellule
        std::vector<glm::mat3> transforms = raster->genTransformations(xMax, yMax, aMax, sMax, dMin, dMax, ff, fr, tf, tr);
        //affichage des résultats
        std::cout << "nombre de transformations : " << transforms.size() << std::endl;
        std::cout << "tes transformations : " << std::endl;
        for (int i = 0; i < transforms.size(); i++) {
            std::cout << transforms[i][0][0] << " " << transforms[i][0][1] << " " << transforms[i][0][2] << std::endl
                      << transforms[i][1][0] << " " << transforms[i][1][1] << " " << transforms[i][1][2] << std::endl
                      << transforms[i][2][0] << " " << transforms[i][2][1] << " " << transforms[i][2][2] << std::endl
            << std:: endl;
        }

        delete raster;
    }



    /*************************************************************************************/
    /***********************Translation uniquement****************************************/
    /*************************************************************************************/

    if (algo[0] == '1') {
        Search *search = new Search(res);

        //Lancement de l'algorithme avec les translations uniquement
        std::vector<glm::mat3> transforms = search->search(modelC, imageC, ff, fr, tf, tr);
        //affichage des résultats
        std::cout << "nombre de transformations : " << transforms.size() << std::endl;
        std::cout << "tes transformations : " << std::endl;
        for (int i = 0; i < transforms.size(); i++) {
            std::cout << transforms[i][0][0] << " " << transforms[i][0][1] << " " << transforms[i][0][2] << std::endl
                      << transforms[i][1][0] << " " << transforms[i][1][1] << " " << transforms[i][1][2] << std::endl
                      << transforms[i][2][0] << " " << transforms[i][2][1] << " " << transforms[i][2][2] << std::endl
            << std:: endl;
        }

        delete search;
    }



    delete im;
    return 0;
}
