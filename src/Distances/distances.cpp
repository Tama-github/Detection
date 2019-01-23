#include "distances.hpp"

double Distances::hDKth(Cloud &A, Cloud &B, float k) {
    uint aSize = A.size();
    uint bSize = B.size();
    if (aSize == 0 || bSize == 0)
        return std::numeric_limits<uint>::max();

    std::vector<double> distances;
    for (uint i = 0; i < aSize ; i++) {
        glm::vec2 a = A[i];
        for (uint j = 0; j < bSize; j++) {
            glm::vec2 b = B[j];
            distances.push_back(double(glm::length(a-b)));
        }
    }
    std::sort(distances.begin(), distances.end());
    uint ind = uint(k == 1.f ? (aSize*bSize)-1 : aSize*bSize*k);
    return distances[ind];
}

double Distances::Hf1 (Cloud& A, Cloud& B, float k) {
    double d1 = hDKth(A,B,k);
    double d2 = hDKth(B,A,k);
    return std::min(d1,d2);
}

double Distances::Hf2 (Cloud& A, Cloud& B, float k) {
    double d1 = hDKth(A,B,k);
    double d2 = hDKth(B,A,k);
    return std::max(d1,d2);
}

double Distances::Hf2 (Cloud& A, Cloud& B, float fr, float ff) {
    double d1 = hDKth(A, B, ff);
    double d2 = hDKth(B, A, fr);
    return std::max(d1, d2);
}

double Distances::Hf3 (Cloud& A, Cloud& B, float k) {
    double d1 = hDKth(A,B,k);
    double d2 = hDKth(B,A,k);
    return double(d1+d2)/double(2);
}

double Distances::Hf4 (Cloud& A, Cloud& B, float k) {
    double d1 = hDKth(A,B,k);
    double d2 = hDKth(B,A,k);
    uint aSize = A.size();
    uint bSize = B.size();
    return double(aSize*d1 + bSize*d2)/double(aSize+bSize);
}

double Distances::delta(Cloud &model, Cloud &image, uint ind) {
    double distMin = std::numeric_limits<double>::max();
    for (uint i = 0; i < image.size(); i++) {
        double dist = double(glm::length(model[ind] - image[i]));
        if (distMin > dist)
            distMin = dist;
    }
    return distMin;
}

double Distances::delta(float x, float y, cv::Mat& image) {
    if (x < image.rows && y < image.cols)
        return std::numeric_limits<double>::max();
    return image.at<double>(int(x), int(y));
}


uint findInd(Cloud& cloud, float x, float y) {
    float epsX = 1.f/cloud.getBox().xMax;
    float epsY = 1.f/cloud.getBox().yMax;

    for (uint i = 0; i < cloud.size(); i++) {
        glm::vec2 p = cloud[i];
        bool okX = p[0] >= x-epsX && p[0] <= x+epsX;
        bool okY = p[1] >= y-epsY && p[1] <= y+epsY;
        if (okX && okY)
            return i;
    }
    return std::numeric_limits<uint>::max();
}

double Distances::deltap(Cloud& model, cv::Mat& image, float x, float y, float w, float h) {
    /*double minDist = std::numeric_limits<double>::max();
    for (float i = x; i <= x+w; i++) {
        for (float j = y; j <= x+h; j++) {
            uint ind = findInd(model, i, j);
            double dist;
            if (ind == std::numeric_limits<uint>::max() || ind > model.size())
                dist = std::numeric_limits<double>::max();
            else
                dist = delta(model, image, ind);
            if (minDist > dist)
                minDist = dist;
        }
    }
    return minDist;*/
    double minDist = std::numeric_limits<double>::max();
    //float j;
    w = w+1;
    h = h+1;
    //#pragma omp parallel for reduction(min:minDist)
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            double dist = std::numeric_limits<double>::max();
            if (x+i <= model.getBox().xMax && y+j <= model.getBox().yMax)
                dist = delta(x+i, y+j, image);
            if (minDist > dist)
                minDist = dist;
        }
        //std::cout << "iter = " << i-x << std::endl;
    }

    return minDist;
}

double Distances::f(Cloud& model, Cloud& image, double thau) {
    if (model.size() == 0 || image.size() == 0)
        return 0;

    uint cardM = model.size();
    uint cpt = 0;
    for (uint i = 0; i < cardM; i++) {
        if (delta(model, image, i) <= thau)
            cpt++;
    }
    return double(cpt)/double(cardM);
}

double Distances::fp(Cloud& model, cv::Mat& image, double t, float w, float h) {
    if (model.size() == 0 || image.total() == 0)
        return 0;

    uint cardM = model.size();
    uint cpt = 0;
    #pragma omp parallel for
    for (uint i = 0; i < cardM; i++) {
        double d = deltap(model, image, model[i][0], model[i][1], w, h);
        //if (cpt != 0)
            //std::cout << "iter = " << i << "/" << cardM << "   |   deltap = " << d << "   |   cpt = " << cpt << std::endl;
        //std::cout << "iter = " << i << "/" << cardM << std::endl;
        if (d <= t) {
            #pragma omp atomic
            cpt++;
        }

    }
    return double(cpt)/double(cardM);
}

cv::Mat Distances::distanceTransform(cv::Mat& img) {

    cv::Canny(img,img,50,150);
    for (uint i = 0; i < img.total(); i++) {
        float f = img.at<float>(int(i));
        if (f != f)
            img.at<float>(int(i)) = 255.f;
    }

    ImageManager im = ImageManager();
    im.imwrite("DistTransformFunction.png", img);
    cv::Mat res = cv::Mat::zeros(img.rows, img.cols, CV_32SC1);


//    cv::Mat matCloud;
  //  cv::findNonZero(img, matCloud);
    int rows = img.rows;
    int cols = img.cols;
    //img = res = cv::Mat::zeros(rows, cols, CV_32F);

    uint cpt = 0;
    for (unsigned int i = 0; i < img.total(); i++ ) {
        //cloud.push_back(glm::vec2(matCloud.at<cv::Point>(int(i)).x,matCloud.at<cv::Point>(int(i)).y));

      //  img.at<float>(matCloud.at<cv::Point>(int(i)).x, matCloud.at<cv::Point>(int(i)).y) = 255.f;
        std::cout << img.at<float>(int(i)) << std::endl;
        if (img.at<float>(int(i)) != 0.f)
            cpt++;
    }
    std::cout << "nbValPos : " << cpt << std::endl;

    std::cout << img.rows << ", " << img.cols << std::endl;

    float *inputImg = (float*)(img.data);
    float *output = (float*)(res.data);

    //#pragma omp parallel for
    for (uint i = 0; i < uint(rows); i++) {
        for (uint j = 0; j < uint(cols); j++) {
           // std::cout << img.at<float>(i, j) << std::endl;
            float distMin = std::numeric_limits<float>::max();
            for (uint k = 0; k < uint(rows); k++) {
                for (uint l = 0; l < uint(cols); l++) {
                    //std::cout << "distance : " << img.at<int>(int(k), int(l)) << std::endl;
                    float dist = 0.f;
                    //if (img.at<float>(int(k), int(l)) != 0.f && i!=k && j!=l) {
                      //  dist = glm::length(glm::vec2(float(i), float(j)) - glm::vec2(float(k), float(l)));
                    if (inputImg[uint(cols) * l + k] != 0.f && i != k && j != l)  {
                        dist = glm::length(glm::vec2(float(i), float(j)) - glm::vec2(float(k), float(l)));
                        //#pragma omp critical
                        //{
                            if (distMin > dist)
                                distMin = dist;
                            //std::cout << dist << std::endl;

                        //}
                    }
                }
            }
            std::cout << "distMin : " << distMin << std::endl;
            //res.at<float>(int(i), int(j)) = distMin;
            output[uint(cols) * j + i] = distMin;
        }
       // std::cout << float(i)/float(img.rows)*100.f << "%" << std::endl;
    }
    //cv::rotate(res, res, 0);
    //cv::flip(res, res, 1);

    return res;
}






