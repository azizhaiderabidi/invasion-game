#ifndef BOLSTER_H
#define BOLSTER_H

#include "Unit.h"

class Bolster :public Unit
{
public:
    Bolster(LTexture* image, float x, float y);
    Bolster();
    virtual ~Bolster();
    void Move(Unit*);  //Moves randomly along xy plane
    void Render(long int& frame, SDL_Renderer* gRenderer);
    bool Clean();

};

#endif // BOLSTER_H

