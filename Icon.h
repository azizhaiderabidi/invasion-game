


#include"Unit.h"


class Icon :public Unit  //different icons appearing on screen
{
public:
    Icon(LTexture* image, float x, float y);
    Icon();
    virtual ~Icon();
    void Render(Unit*,int bullets,long int& frame,SDL_Renderer* gRenderer);

};



