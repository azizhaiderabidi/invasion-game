#include "Point.h"
#include <iostream>
Point::Point():x(0),y(0)
{

}

Point::Point(float x,float y):x(x),y(y)
{

}
Point::show()
{
std::cout << x << "  " << y << std::endl;
}
