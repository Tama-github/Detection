#include "distances.h"

double hDKth(std::vector<glm::vec2> A, std::vector<glm::vec2> B, float k) {
    int aSize = A.size();
    int bSize = B.size();
    std::vector<double> distances;
    for (int i = 0; i < aSize ; i++) {
        glm::vec2 a = A[i];
        for (int j = 0; j < bSize; j++) {
            glm::vec2 b = B[j];
            distances.push_back(glm::norm(a,b));
        }
    }
    std::sort (distances.begin(), distances.end());
    return distances[int(aSize*k)];
}

static double Distances::Hf1 (std::vector<glm::vec2> A, std::vector<glm::vec2> B, float k) {
    double d1 = hDKth(A,B,k);
    double d2 = hDKth(B,A,k);
    return std::min(d1,d2);
}

static double Distances::Hf2 (std::vector<glm::vec2> A, std::vector<glm::vec2> B, float k) {
    double d1 = hDKth(A,B,k);
    double d2 = hDKth(B,A,k);
    return std::max(d1,d2);
}

static double Distances::Hf3 (std::vector<glm::vec2> A, std::vector<glm::vec2> B, float k) {
    double d1 = hDKth(A,B,k);
    double d2 = hDKth(B,A,k);
    return (d1+d2)/double(2);
}

static double Distances::Hf4 (std::vector<glm::vec2> A, std::vector<glm::vec2> B, float k) {
    double d1 = hDKth(A,B,k);
    double d2 = hDKth(B,A,k);
    int aSize = A.size();
    int bSize = B.size();
    return (aSize*d1 + bSize*d2)/(aSize+bSize);
}

