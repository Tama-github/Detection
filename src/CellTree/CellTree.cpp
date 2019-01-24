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

    w = (a00max-a00min)+(a01max-a01min)+(xmax-xmin);
    h = (a10max-a10min)+(a11max-a11min)+(ymax-ymin);

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
        throw "Position of child must be under 63";
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
    return h == 0.f && w == 0.f
            && coord.a00max == coord.a00min
            && coord.a10max == coord.a10min
            && coord.a01max == coord.a01min
            && coord.a11max == coord.a11min
            && coord.xmax == coord.xmin
            && coord.ymax == coord.ymin;
}

glm::mat3 CellTree::getTransformTL() {
    glm::mat3 res = glm::mat3(0);
    res[0][0] = coord.a00min * i1;
    res[0][1] = coord.a01min * i2;
    res[1][0] = coord.a10min * i3;
    res[1][1] = coord.a11min * i4;
    res[0][2] = coord.xmin * i5;
    res[1][2] = coord.ymin * i6;
    res[2][2] = 1.f;
    return res;
}

void CellTree::subdivideCell6D(){

    hasChild = true;
    std::vector<float> mid_x =   {this->coord.xmin,   this->coord.xmin+(this->coord.xmax - this->coord.xmin+1)/2.f -1,       this->coord.xmax-(this->coord.xmax - this->coord.xmin-1)/2.f,       this->coord.xmax};
    std::vector<float> mid_y =   {this->coord.ymin,   this->coord.ymin+(this->coord.ymax - this->coord.ymin+1)/2.f -1,       this->coord.ymax-(this->coord.ymax - this->coord.ymin-1)/2.f,       this->coord.ymax};
    std::vector<float> mid_a00 = {this->coord.a00min, this->coord.a00min+(this->coord.a00max - this->coord.a00min+1)/2.f -1, this->coord.a00max-(this->coord.a00max - this->coord.a00min-1)/2.f, this->coord.a00max};
    std::vector<float> mid_a01 = {this->coord.a01min, this->coord.a01min+(this->coord.a01max - this->coord.a01min+1)/2.f -1, this->coord.a01max-(this->coord.a01max - this->coord.a01min-1)/2.f, this->coord.a01max};
    std::vector<float> mid_a10 = {this->coord.a10min, this->coord.a10min+(this->coord.a10max - this->coord.a10min+1)/2.f -1, this->coord.a10max-(this->coord.a10max - this->coord.a10min-1)/2.f, this->coord.a10max};
    std::vector<float> mid_a11 = {this->coord.a11min, this->coord.a11min+(this->coord.a11max - this->coord.a11min+1)/2.f -1, this->coord.a11max-(this->coord.a11max - this->coord.a11min-1)/2.f, this->coord.a11max};


    for(float i = 0; i < R; i++)
    {
        float x_min = mid_x[i*2];
        float x_max = mid_x[i*2+1];
        
        for(float j = 0; j < R; j++)
        {
            float y_min = mid_y[j*2];
            float y_max = mid_x[j*2+1];

            for(float u = 0; u < R; u++)
            {
                float a00_min = mid_a00[u*2];
                float a00_max = mid_a00[u*2+1];
                
                for(float v = 0; v < R; v++)
                {
                    float a01_min = mid_a01[v*2];
                    float a01_max = mid_a01[v*2+1];
                    
                    for(float m = 0; m < R; m++)
                    {
                        float a10_min = mid_a10[m*2];
                        float a10_max = mid_a10[m*2+1];
                        
                        for(float n = 0; n < R; n++)
                        {
                            float a11_min = mid_a11[n*2];
                            float a11_max = mid_a11[n*2+1];
                            
                            this->children.emplace_back(new CellTree(x_min, x_max, y_min, y_max, a00_min,a00_max,a01_min,a01_max,a10_min,a10_max,a11_min,a11_max,i1,i2,i3,i4,i5,i6, this));
                        }
                    }
                }
            }
        }        
    }
}

void CellTree::subdivideCell2D(){

    hasChild = true;
    float mid_x = float(float(this->coord.xmax) + float(this->coord.xmin))/float(R);
    float mid_y = float(float(this->coord.ymax) + float(this->coord.ymin))/float(R);

    std::cout << "mid_x = " << mid_x << std::endl;
    std::cout << "mid_y = " << mid_y << std::endl;

    for(float i = 0; i < R; i++)
    {
        float x_min = this->coord.xmin + i * mid_x;
        float x_max = this->coord.xmax - (1.f-i) * mid_x;

        for(float j = 0; j < R; j++)
        {
            float y_min = this->coord.ymin + j * mid_y;
            float y_max = this->coord.ymax - (1.f-j) * mid_y;
            this->children.emplace_back(new CellTree(x_min, x_max, y_min, y_max, coord.a00min,coord.a00max,coord.a01min,coord.a01min,coord.a10min,coord.a10max,coord.a11min,coord.a11max,i1,i2,i3,i4,i5,i6, this));
        }
    }
}

void CellTree::displayMe(){

    std::cout << "Me :" << std::endl;
    this->printCoordinate();

    if (!hasChild) return;

    std::cout << "My children :" << std::endl;
    for(uint i = 0; i < this->children.size(); i++)
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
