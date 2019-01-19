#include "CellTree.hpp"


CellTree::CellTree(int xmin, int xmax, int ymin, int ymax, float a00min, float a00max, float a01min, float a01max, float a10min, float a10max,float a11min, float a11max, CellTree * parent ){
    this->coord.xmin = xmin;
    this->coord.xmax = xmax;
    this->coord.ymin = ymin;
    this->coord.ymax = ymax;
    this->coord.a00min = a00min;
    this->coord.a00max = a00max;
    this->coord.a01min = a01min;
    this->coord.a01max = a01max;
    this->coord.a10min = a10min;
    this->coord.a10max = a10max;
    this->coord.a11min = a11min;
    this->coord.a11max = a11max;

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
    int mid_a00 = (this->coord.a00max - this->coord.a00max)/2;
    int mid_a01 = (this->coord.a01max - this->coord.a01max)/2;
    int mid_a10 = (this->coord.a10max - this->coord.a10max)/2;
    int mid_a11 = (this->coord.a11max - this->coord.a11max)/2;

    for(int i = 0; i < R; i++)
    {
        int x_min = this->coord.xmin + i * mid_x;
        int x_max = this->coord.xmax - (1-i) * mid_x;
        
        for(int j = 0; j < R; j++)
        {
            int y_min = this->coord.xmin + j * mid_y;
            int y_max = this->coord.ymax - (1-j) * mid_y;

            for(int u = 0; u < R; u++)
            {
                float a00_min = this->coord.a00min + u * mid_a00;
                float a00_max = this->coord.a00max - (1-u) * mid_a00;
                
                for(int v = 0; v < R; v++)
                {
                    float a01_min = this->coord.a01min + v * mid_a01;
                    float a01_max = this->coord.a01max - (1-v) * mid_a01;
                    
                    for(int m = 0; m < R; m++)
                    {
                        float a10_min = this->coord.a10min + m * mid_a10;
                        float a10_max = this->coord.a10max - (1-m) * mid_a10;
                        
                        for(int n = 0; n < R; n++)
                        {
                            float a11_min = this->coord.a11min + n * mid_a11;
                            float a11_max = this->coord.a11max - (1-n) * mid_a11;
                            
                            this->children[i+j*2+u*4+v*8+m*16+n*32] = new CellTree(x_min, x_max, y_min, y_max, a00_min,a00_max,a01_min,a01_max,a10_min,a10_max,a11_min,a11_max, this);
                        }
                    }

                }
            }
        }        
    }
}

void CellTree::displayMe(){
    /*
    //std::cout << this->depth << std::endl;
    if(this->children[0] == nullptr)
    {
        return;
    }
    std::cout << this->depth;
    printCoordinate(this->coord);
    
    for(int i = 0; i < CHILDREN_NUMBER; i++)
    {        
        this->children[i]->displayMe();
    }
    std::cout << "   " << std::endl;
    */
    for(int i = 0; i < CHILDREN_NUMBER; i++)
    {
        std::cout << i << " " << this->children[i]->coord.xmin << std::endl;
    }
    
}

std::vector<CellTree> CellTree::getInterestingCells() {
    std::vector<CellTree> list;
   
    recursiveInterestingCells(&list);

    return list;
}

void CellTree::recursiveInterestingCells(std::vector<CellTree> * list) {    
    
    if (this->isInteresting) 
    {
        list->push_back(*this);
    }

    if(this->children[0] != nullptr)
    {
        for(size_t i = 0; i < CHILDREN_NUMBER; i++)
        {
            this->children[i]->recursiveInterestingCells(list);
        }            
    }
}


void CellTree::printCoordinate(CellTree::Coordinate coord) {
    std::cout << "(" << coord.xmin << ", " << coord.xmax << ", " << coord.ymin << ", " << coord.ymax << ")" << std::endl;
}
