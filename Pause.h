#include "LTexture.h"
#include "Screen.h"

class Pause : public Screen
{
public:
    Pause();
    virtual ~Pause();
    Pause(LTexture* image,float x,float y);
    void Render(SDL_Renderer* renderer);

};

