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

double Distances::delta(float x, float y, Cloud &image) {
    double distMin = std::numeric_limits<double>::max();
    for (uint i = 0; i < image.size(); i++) {
        double dist = double(glm::length(glm::vec2(x, y) - image[i]));
        if (distMin > dist)
            distMin = dist;
    }
    return distMin;
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

double Distances::deltap(Cloud& model, Cloud& image, float x, float y, float w, float h) {
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
        for (float i = x; i <= x+w; i++) {
            for (float j = y; j <= x+h; j++) {
                double dist = minDist = std::numeric_limits<double>::max();
                if (i <= model.getBox().xMax && j <= model.getBox().yMax)
                    dist = delta(i, j, image);
                if (minDist > dist)
                    minDist = dist;
            }
        }
        return minDist;
}

double Distances::f(Cloud& model, Cloud& image, double thau) {
    if (model.size() == 0 || image.size() == 0)
        return std::numeric_limits<uint>::max();

    uint cardM = model.size();
    uint cpt = 0;
    for (uint i = 0; i < cardM; i++) {
        if (delta(model, image, i) <= thau)
            cpt++;
    }
    return double(cpt)/double(cardM);
}

double Distances::fp(Cloud& model, Cloud& image, double thau, float w, float h) {
    if (model.size() == 0 || image.size() == 0)
        return std::numeric_limits<uint>::max();

    uint cardM = model.size();
    uint cpt = 0;
    #pragma omp parallel for
    for (uint i = 0; i < cardM; i++) {
        if (deltap(model, image, model[i][0], model[i][1], w, h) <= thau) {
            #pragma omp atomic
            cpt++;
        }
    }
    return double(cpt)/double(cardM);
}









