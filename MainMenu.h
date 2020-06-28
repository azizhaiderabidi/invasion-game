
#include "Screen.h"


class MainMenu : public Screen
{
public:
    MainMenu();
    virtual ~MainMenu();
    MainMenu(LTexture* image,float x,float y);
    void Render(SDL_Renderer* renderer);


};

