
#include "Screen.h"


class shade : public Screen
{
public:
    shade();
    virtual ~shade();
    shade(LTexture* image,float x,float y);
    virtual void Render(SDL_Renderer* renderer);

};
