#ifndef RECT_H
#define RECT_H
#include <iostream>

struct Rect
{
    Rect(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4);  //making rectangle
    float x1,y1,x2,y2,x3,y3,x4,y4,w,h; //all four points of rectangle
    bool ComesIn(float& x, float& y);  //if given points comes within rectangle
    bool CollidesWith(Rect&);  //if rectangle collides with another rectangle

};

#endif // RECT_H
