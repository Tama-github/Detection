#include "distances.hpp"

double Distances::hDKth(Cloud &A, Cloud &B, float k) {
    uint aSize = A.size();
    uint bSize = B.size();
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

