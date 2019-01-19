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
        CellTree(int xmin, int xmax, int ymin, int ymax, float a00min, float a00max, float a01min, float a01max, float a10min, float a10max,float a11min, float a11max, CellTree * parent = nullptr) ;
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
            int xmin;
            int xmax;
            int ymin;
            int ymax;
        };
        
        bool isInteresting;
        int depth;
        CellTree * parent;        
        CellTree * children [CHILDREN_NUMBER] = {};
        Coordinate coord;

        void recursiveInterestingCells(std::vector<CellTree> * list);
        void printCoordinate(Coordinate coord);
};

#endif //CELLTREE_HPP
