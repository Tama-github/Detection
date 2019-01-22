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

bool Distances::fp(Cloud& model, cv::Mat& image, double f, double t, float w, float h) {
    if (model.size() == 0 || image.total() == 0)
        return false;
    std::cout << "fpCouCou 1 : " << image.rows << ", " << image.cols << std::endl;
    uint cardM = model.size();
    uint cpt = 0;
    //#pragma omp parallel for
    for (uint i = 0; i < cardM; i++) {
        std::cout << "iter = " << i << "/" << cardM << std::endl;
        if (deltap(model, image, model[i][0], model[i][1], w, h) <= t) {
            //#pragma omp atomic
            if ((++cpt)/double(cardM) >= f) return true;
        }

    }
    return false;
}

cv::Mat Distances::distanceTransform(cv::Mat img) {
    cv::Canny(img,img,50,150);
    cv::Mat res = cv::Mat::zeros(img.rows, img.cols, CV_32F);

    cv::Mat matCloud;
    cv::findNonZero(img, matCloud);
    int rows = img.rows;
    int cols = img.cols;
    img = res = cv::Mat::zeros(rows, cols, CV_32F);

    for (unsigned int i = 0; i < matCloud.total(); i++ ) {
        //cloud.push_back(glm::vec2(matCloud.at<cv::Point>(int(i)).x,matCloud.at<cv::Point>(int(i)).y));

        img.at<float>(matCloud.at<cv::Point>(int(i)).x, matCloud.at<cv::Point>(int(i)).y) = 255.f;

    }

    //std::cout << img.rows << ", " << img.cols << std::endl;
    #pragma omp parallel for
    for (uint i = 0; i < uint(img.rows); i++) {
        for (uint j = 0; j < uint(img.cols); j++) {
           // std::cout << img.at<float>(i, j) << std::endl;
            float distMin = std::numeric_limits<float>::max();
            for (uint k = 0; k < uint(img.rows); k++) {
                for (uint l = 0; l < uint(img.cols); l++) {
                    if (k != i && l != j && img.at<float>(int(k), int(l)) == 255.f) {
                        float dist = glm::length(glm::vec2(i, j) - glm::vec2(k, l));
                        if (distMin > dist) {
                            #pragma omp critical
                            {
                                distMin = dist;
                            }
                        }
                        if (img.at<float>(int(i), int(j)) == 255.f && i == k && j == l)
                            distMin = 0.f;
                    }
                }
                res.at<float>(int(i), int(j)) = distMin;
            }
        }
       // std::cout << float(i)/float(img.rows)*100.f << "%" << std::endl;
    }
    cv::rotate(res, res, 0);
    cv::flip(res, res, 1);

    return res;
}






