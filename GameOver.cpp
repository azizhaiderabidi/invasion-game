#include "GameOver.h"
GameOver::GameOver()
{
}

GameOver::~GameOver()
{

}

GameOver::GameOver(LTexture* image,float x,float y):Screen(image, x, y)
{
    ScreenTexture = image;

    ScreenClip.x =   0;
    ScreenClip.y =   0;
    ScreenClip.w =   800;
    ScreenClip.h =   600;

    show = true;
    //degrees = 0;

    this->x = x;
    this->y = y;
    this->width = ScreenClip.w;
    this->height = ScreenClip.h;
}

void GameOver::Render(SDL_Renderer* renderer)
{
        ScreenTexture->Render( x , y, &ScreenClip, 0, NULL, SDL_FLIP_NONE, renderer );

}
