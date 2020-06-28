
#include "Button.h"
Button::Button()
{
}

Button::~Button()
{
    ButtonTexture=NULL;
}

Button::Button(LTexture* image,float x,float y)
{
    ButtonTexture = image;

    ButtonClip[0].x =   300;
    ButtonClip[0].y =   212;
    ButtonClip[0].w =   200;
    ButtonClip[0].h =   82;

    ButtonClip[1].x =   300;
    ButtonClip[1].y =   335;
    ButtonClip[1].w =   200;
    ButtonClip[1].h =   82;

    pressed = false;
    //degrees = 0;

    this->x = x;
    this->y = y;
    this->w = ButtonClip[0].w;
    this->h = ButtonClip[0].h;
}

void Button::Render(int a, SDL_Renderer* renderer)
{
        ButtonTexture->Render( x , y , &ButtonClip[a], 0, NULL, SDL_FLIP_NONE, renderer );

}

