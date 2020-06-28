

#ifndef BOOST_H
#define BOOST_H
#include "Unit.h"

class Boost :public Unit  //Power up for getting Mbullets back
{
public:
    Boost(LTexture* image, float x, float y);
    Boost();
    virtual ~Boost();
    void Move(Unit*);
    void Render(long int& frame, SDL_Renderer* gRenderer);
    bool Clean();

};

#endif // BOOST_H
