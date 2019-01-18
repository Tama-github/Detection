#ifndef CELLTREE_HPP
#define CELLTREE_HPP

#include <vector>
#include <iostream>

#define MAX_DEPTH 6

class CellTree
{    
    public:
        CellTree(int xmin, int xmax, int ymin, int ymax, CellTree * parent = nullptr) ;
        ~CellTree();
        CellTree * getParent();
        CellTree * getChild(int number);
        CellTree ** getChilds();
        bool getInterest();
        void setInterest(bool value);   
        void subdivideCell();
        void displayMe();

    private:
        struct Coordinate
        {
            int xmin;
            int xmax;
            int ymin;
            int ymax;
        };
        
        bool isInteresting;
        int depth;
        CellTree * parent;        
        CellTree * children [4] = {nullptr,nullptr,nullptr,nullptr};
        Coordinate coord;
};

#endif //CELLTREE_HPP
