#ifndef CELLTREE_HPP
#define CELLTREE_HPP

#include <vector>
#include <iostream>
#include <glm/glm.hpp>

#define MAX_DEPTH 6
#define CHILDREN_NUMBER 64
#define R 2.f

class CellTree
{    
    public:
        CellTree(float xmin, float xmax, float ymin, float ymax, float a00min, float a00max, float a01min, float a01max, float a10min, float a10max,float a11min, float a11max, float ii1, float ii2, float ii3, float ii4, float ii5, float ii6,  CellTree * parent = nullptr) ;
        ~CellTree();
        CellTree * getParent();
        CellTree * getChild(int number);
        std::vector<CellTree*> getChilds();
        bool getInterest();
        void setInterest(bool value);   
        void subdivideCell();
        void displayMe();
        std::vector<CellTree> getInterestingCells();
        bool hasOneElem();
        glm::mat3 getTransformTL();
        float w;
        float h;


    private:
        struct Coordinate
        {
            float a00min;
            float a00max;
            float a01min;
            float a01max;
            float a10min;
            float a10max;
            float a11min;
            float a11max;
            float xmin;
            float xmax;
            float ymin;
            float ymax;
        };
        bool hasChild;
        bool isInteresting;
        int depth;
        CellTree * parent;        
        std::vector<CellTree*> children;
        Coordinate coord;
        float i1;
        float i2;
        float i3;
        float i4;
        float i5;
        float i6;
        void recursiveInterestingCells(std::vector<CellTree> * list);
        void printCoordinate();
};

#endif //CELLTREE_HPP
