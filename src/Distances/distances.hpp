#ifndef DISTANCES_H
#define DISTANCES_H

#include <opencv2/opencv.hpp>
#include <algorithm>
#include <vector>
#include <glm/glm.hpp>
#include <limits>

class Distances
{
public:
    static double Hf1 (std::vector<glm::vec2>& A, std::vector<glm::vec2>& B, float k);
    static double Hf2 (std::vector<glm::vec2>& A, std::vector<glm::vec2>& B, float k);
    static double Hf2 (std::vector<glm::vec2>& A, std::vector<glm::vec2>& B, float fr, float ff);
    static double Hf3 (std::vector<glm::vec2>& A, std::vector<glm::vec2>& B, float k);
    static double Hf4 (std::vector<glm::vec2>& A, std::vector<glm::vec2>& B, float k);

    static double hDKth(std::vector<glm::vec2> &A, std::vector<glm::vec2> &B, float k);

   // static double probe (std::vector<glm::vec2>& A, )

private:


};

#endif // DISTANCES_H
