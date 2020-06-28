#include "LTexture.h"
#include "Screen.h"

class GameOver : public Screen
{
public:
    GameOver();
    virtual ~GameOver();
    GameOver(LTexture* image,float x,float y);
    void Render(SDL_Renderer* renderer);

};
