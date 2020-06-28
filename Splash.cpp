#include "Splash.h"
Splash::Splash()
{
}

Splash::~Splash()
{

}

Splash::Splash(LTexture* image,float x,float y):Screen(image, x, y)
{
    ScreenTexture = image;

    ScreenClip.x =   0;
    ScreenClip.y =   0;
    ScreenClip.w =   0;
    ScreenClip.h =   0;

    Splashclips[0].x = 0;
    Splashclips[0].y = 0;
    Splashclips[0].w = 800;
    Splashclips[0].h = 600;

    Splashclips[1].x = 800;
    Splashclips[1].y = 0;
    Splashclips[1].w = 800;
    Splashclips[1].h = 600;

    Splashclips[2].x = 1600;
    Splashclips[2].y = 0;
    Splashclips[2].w = 800;
    Splashclips[2].h = 600;

    Splashclips[3].x = 2400;
    Splashclips[3].y = 0;
    Splashclips[3].w = 800;
    Splashclips[3].h = 600;

    Splashclips[4].x = 0;
    Splashclips[4].y = 600;
    Splashclips[4].w = 800;
    Splashclips[4].h = 600;

    Splashclips[5].x = 800;
    Splashclips[5].y = 600;
    Splashclips[5].w = 800;
    Splashclips[5].h = 600;

    Splashclips[6].x = 1600;
    Splashclips[6].y = 600;
    Splashclips[6].w = 800;
    Splashclips[6].h = 600;

    Splashclips[7].x = 2400;
    Splashclips[7].y = 600;
    Splashclips[7].w = 800;
    Splashclips[7].h = 600;

    show = true;
    //degrees = 0;

    this->x = x;
    this->y = y;
    this->width = ScreenClip.w;
    this->height = ScreenClip.h;
}

void Splash::Render(int a,SDL_Renderer* renderer)
{
        ScreenTexture->Render( x - width/2, y - height/2, &Splashclips[a], 0, NULL, SDL_FLIP_NONE, renderer );

}

