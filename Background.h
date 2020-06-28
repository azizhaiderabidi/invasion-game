#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Unit.h"
class Background :public Unit
{
public:
    Background(LTexture* image, float x, float y);
    Background();
    virtual ~Background();
    void Render(Unit*,long int& frame, SDL_Renderer* gRenderer);
    void Move(Unit*);  //for scrolling background
    bool Clean();

};

#endif // BACKGROUND_H

