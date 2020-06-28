#include "Screen.h"
Screen::Screen()
{
}

Screen::~Screen()
{
    ScreenTexture = NULL;
}

Screen::Screen(LTexture* image,float x,float y)
{
    ScreenTexture = image;

    ScreenClip.x =   0;
    ScreenClip.y =   0;
    ScreenClip.w =   0;
    ScreenClip.h =   0;

    show = true;
    //degrees = 0;

    this->x = x;
    this->y = y;
    this->width = ScreenClip.w;
    this->height = ScreenClip.h;
}

void Screen::Render(SDL_Renderer* renderer)
{
        ScreenTexture->Render( x - width/2, y - height/2, &ScreenClip, 0, NULL, SDL_FLIP_NONE, renderer );

}

void Screen::Render(int a,SDL_Renderer* renderer)
{
       std::cout<<"Virtual"<<std::endl;

}
