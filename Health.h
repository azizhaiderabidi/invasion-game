#ifndef HEALTH_H
#define HEALTH_H


#include"Unit.h"


class Health :public Unit
{
public:
    Health(LTexture* image, float x, float y);
    Health();
    virtual ~Health();
    void Render(Unit*,long int& frame,SDL_Renderer* gRenderer);  //check player health

};

#endif // HEALTH_H

