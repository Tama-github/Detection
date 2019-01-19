#include "CellTree.hpp"


CellTree::CellTree(int xmin, int xmax, int ymin, int ymax, CellTree * parent ){
    this->coord.xmin = xmin;
    this->coord.xmax = xmax;
    this->coord.ymin = ymin;
    this->coord.ymax = ymax;

    this->isInteresting = false;
    
    if (parent) {
        this->parent = parent;
        this->depth = parent->depth + 1;
    } else {
        this->depth = 0;
    }    
}

CellTree::~CellTree(){
    
}

CellTree * CellTree::getParent(){
    return this->parent;
}

CellTree * CellTree::getChild(int number){
    
    if (number < 0) {
        throw "Position of child must be positive";
    } else if (number > 3) {
        throw "Position of child must be under 4";
    }    

    return this->children[number];
}

CellTree ** CellTree::getChilds(){
    return this->children;
}

bool CellTree::getInterest(){
    return this->isInteresting;
}

void CellTree::setInterest(bool value){
    this->isInteresting = value;
}

void CellTree::subdivideCell(){    
    if (this->depth == MAX_DEPTH) {
        return;
    }
    
    int mid_x = (this->coord.xmax - this->coord.xmin)/2;
    int mid_y = (this->coord.ymax - this->coord.ymin)/2;

    for(int i = 0; i < 2; i++)
    {
        int x_min = this->coord.xmin + i * mid_x;
        int x_max = this->coord.xmax - (1-i) * mid_x;
        
        for(int j = 0; j < 2; j++)
        {
            int y_min = this->coord.xmin + j * mid_y;
            int y_max = this->coord.ymax - (1-j) * mid_y;

            this->children[i + j*2] = new CellTree(x_min, x_max, y_min, y_max, this);
            this->children[i + j*2]->subdivideCell();
        }        
    }    
}

void CellTree::displayMe(){
    //std::cout << this->depth << std::endl;
    if(this->children[0] == nullptr)
    {
        return;
    }
    std::cout << this->depth;
    printCoordinate(this->coord);
    
    for(int i = 0; i < 4; i++)
    {        
        this->children[i]->displayMe();
    }
    std::cout << "   " << std::endl;
    
}

std::vector<CellTree> CellTree::getInterestingCells() {
    return std::vector<CellTree>();
}
void CellTree::printCoordinate(CellTree::Coordinate coord) {
    std::cout << "(" << coord.xmin << ", " << coord.xmax << ", " << coord.ymin << ", " << coord.ymax << ")" << std::endl;
}
