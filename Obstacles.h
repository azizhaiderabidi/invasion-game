#ifndef OBSTACLE_H
#define OBSTACLE_H

#include"Unit.h"


class Obstacles :public Unit  //it will not be destroyed by bullets
{
public:
    Obstacles(LTexture* image, float x, float y);
    Obstacles();
    virtual ~Obstacles();
    void Move(Unit*);
    void Render(long int& frame, SDL_Renderer* gRenderer);
    bool Clean();

};

#endif // OBSTACLE1_H
