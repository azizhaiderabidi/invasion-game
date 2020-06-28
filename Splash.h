
#include "LTexture.h"
#include "Screen.h"

class Splash : public Screen
{
public:
    Splash();
    virtual ~Splash();
    SDL_Rect Splashclips[8];
    Splash(LTexture* image,float x,float y);
    void Render(int,SDL_Renderer* renderer);

};
