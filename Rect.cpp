#include "Rect.h"

Rect::Rect(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
    this->x1 = x1;
    this->x2 = x2;
    this->x3 = x3;
    this->x4 = x4;
    this->y1 = y1;
    this->y2 = y2;
    this->y3 = y3;
    this->y4 = y4;
    w=x2-x1;
    h=y3-y1;
}

bool Rect::ComesIn(float& x, float& y)
{
    //std::cout<<"here45"<<std::endl;
    return (x >= x1 && x <= x2 && y >= y1 && y <=y3);
}
bool Rect::CollidesWith(Rect& R)
{
    //std::cout<<"here567"<<std::endl;
    return (ComesIn(R.x1, R.y1) || ComesIn(R.x2,R.y2) || ComesIn(R.x3,R.y3) || ComesIn(R.x4,R.y4));
}
