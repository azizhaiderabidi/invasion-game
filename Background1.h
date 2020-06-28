

#include "Unit.h"
class Background1 :public Unit
{
public:
    Background1(LTexture* image, float x, float y);
    Background1();
    virtual ~Background1();
    void Render(Unit*,long int& frame, SDL_Renderer* gRenderer);
    void Move(Unit*); //for scrolling background
    bool Clean();

};



