#ifndef CELLTREE_HPP
#define CELLTREE_HPP

#include <vector>
#include <iostream>

#define MAX_DEPTH 6
#define CHILDREN_NUMBER 64
#define R 2

class CellTree
{    
    public:
        CellTree(float xmin, float xmax, float ymin, float ymax, float a00min, float a00max, float a01min, float a01max, float a10min, float a10max,float a11min, float a11max, float ii1, float ii2, float ii3, float ii4, float ii5, float ii6,  CellTree * parent = nullptr) ;
        ~CellTree();
        CellTree * getParent();
        CellTree * getChild(int number);
        CellTree ** getChilds();
        bool getInterest();
        void setInterest(bool value);   
        void subdivideCell();
        void displayMe();
        std::vector<CellTree> getInterestingCells();

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
        CellTree * children [CHILDREN_NUMBER] = {};
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
