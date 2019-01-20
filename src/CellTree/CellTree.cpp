#include "CellTree.hpp"


CellTree::CellTree(float xmin, float xmax, float ymin, float ymax, float a00min, float a00max, float a01min, float a01max, float a10min, float a10max,float a11min, float a11max, float ii1, float ii2, float ii3, float ii4, float ii5, float ii6, CellTree * parent ){
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
    i1 = ii1;
    i2 = ii2;
    i3 = ii3;
    i4 = ii4;
    i5 = ii5;
    i6 = ii6;

    w = (a00max/i1-a00min/i1)+(a01max/i2-a01min/i2)+(xmax/i5-xmin/i5);
    h = (a10max/i3-a10min/i3)+(a11max/i4-a11min/i4)+(ymax/i6-ymin/i6);

    hasChild = false;

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

CellTree * CellTree::getChild(uint number){
    
    if (number > 63) {
        throw "Position of child must be under 4";
    }

    return this->children[number];
}

std::vector<CellTree*> CellTree::getChilds(){
    return this->children;
}

bool CellTree::getInterest(){
    return this->isInteresting;
}

void CellTree::setInterest(bool value){
    this->isInteresting = value;
}

bool CellTree::hasOneElem() {
    return h == 0.f && w == 0.f;
}

glm::mat3 CellTree::getTransformTL() {
    glm::mat3 res = glm::mat3(0);
    res[0][0] = coord.a00min;
    res[0][1] = coord.a01min;
    res[1][0] = coord.a10min;
    res[1][1] = coord.a11min;
    res[0][2] = coord.xmin;
    res[1][2] = coord.ymin;
    res[2][2] = 1.f;
    return res;
}

void CellTree::subdivideCell(){    
    /*if (this->depth == MAX_DEPTH) {
        return;
    }*/
    hasChild = true;
    float mid_x = float(float(this->coord.xmax) + float(this->coord.xmin))/float(R);
    float mid_y = float(float(this->coord.ymax) + float(this->coord.ymin))/float(R);
    float mid_a00 = float(float(this->coord.a00max) + float(this->coord.a00max))/float(R);
    float mid_a01 = float(float(this->coord.a01max) + float(this->coord.a01max))/float(R);
    float mid_a10 = float(float(this->coord.a10max) + float(this->coord.a10max))/float(R);
    float mid_a11 = float(float(this->coord.a11max) + float(this->coord.a11max))/float(R);

    std::cout << "mid_x = " << mid_x << std::endl;
    std::cout << "mid_y = " << mid_y << std::endl;
    std::cout << "mid_a00 = " << mid_a00 << std::endl;
    std::cout << "mid_a01 = " << mid_a01 << std::endl;
    std::cout << "mid_a10 = " << mid_a10 << std::endl;
    std::cout << "mid_a11 = " << mid_a11 << std::endl;

    for(float i = 0; i < R; i++)
    {
        float x_min = this->coord.xmin + i * mid_x;
        float x_max = this->coord.xmax - (1.f-i) * mid_x;
        
        for(float j = 0; j < R; j++)
        {
            float y_min = this->coord.ymin + j * mid_y;
            float y_max = this->coord.ymax - (1.f-j) * mid_y;

            for(float u = 0; u < R; u++)
            {
                float a00_min = this->coord.a00min + u * mid_a00;
                float a00_max = this->coord.a00max - (1.f-u) * mid_a00;
                
                for(float v = 0; v < R; v++)
                {
                    float a01_min = this->coord.a01min + v * mid_a01;
                    float a01_max = this->coord.a01max - (1.f-v) * mid_a01;
                    
                    for(float m = 0; m < R; m++)
                    {
                        float a10_min = this->coord.a10min + m * mid_a10;
                        float a10_max = this->coord.a10max - (1.f-m) * mid_a10;
                        
                        for(float n = 0; n < R; n++)
                        {
                            float a11_min = this->coord.a11min + n * mid_a11;
                            float a11_max = this->coord.a11max - (1.f-n) * mid_a11;
                            
                            this->children.emplace_back(new CellTree(x_min, x_max, y_min, y_max, a00_min,a00_max,a01_min,a01_max,a10_min,a10_max,a11_min,a11_max,i1,i2,i3,i4,i5,i6, this));
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
    std::cout << "Me :" << std::endl;
    this->printCoordinate();

    if (!hasChild) return;

    std::cout << "My children :" << std::endl;
    for(uint i = 0; i < CHILDREN_NUMBER; i++)
    {
        this->children[i]->printCoordinate();
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


void CellTree::printCoordinate() {
    std::cout << "("
              << coord.a00min << ", " << coord.a00max << ", "
              << coord.a01min << ", " << coord.a01max << ", "
              << coord.a10min << ", " << coord.a10max << ", "
              << coord.a11min << ", " << coord.a11max << ", "
              << coord.xmin << ", " << coord.xmax << ", "
              << coord.ymin << ", " << coord.ymax
              << ")" << std::endl;
}
