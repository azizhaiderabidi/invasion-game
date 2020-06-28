#ifndef FUEL_H
#define FUEL_H

#include "Unit.h"

class Fuel :public Unit  //power up for player health
{
public:
    int quantity = 3;
    Fuel(LTexture* image, float x, float y);
    Fuel();
    virtual ~Fuel();
    void Move(Unit*);
    void Render(long int& frame, SDL_Renderer* gRenderer);
    bool Clean();

};

#endif // FUEL_H

