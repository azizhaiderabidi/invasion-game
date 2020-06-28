
#include "Icon.h"

Icon::Icon()
{

}

Icon::~Icon()
{
    cout<<"Icon deallocated"<<endl;
}

Icon::Icon(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;
    //Frame 0
    spriteClips[ 0 ].x = 222;
    spriteClips[ 0 ].y = 172;
    spriteClips[ 0 ].w = 25;
    spriteClips[ 0 ].h = 25;

    //Frame 1
    spriteClips[ 1 ].x = 222;
    spriteClips[ 1 ].y = 195;
    spriteClips[ 1 ].w = 25;
    spriteClips[ 1 ].h = 25;

    //Frame 2
    spriteClips[ 2 ].x = 201;
    spriteClips[ 2 ].y = 242;
    spriteClips[ 2 ].w = 160;
    spriteClips[ 2 ].h = 60;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
}


void Icon::Render(Unit* plane,int bullets,long int& frame, SDL_Renderer* gRenderer)
{
    if(plane->get_alive())
    {
        if(bullets<50)
            spriteSheetTexture->Render( x , y , &spriteClips[0], degrees, NULL, SDL_FLIP_NONE, gRenderer );//flipping sprite vertically
        else if(bullets == 200)
            spriteSheetTexture->Render( x , y , &spriteClips[2], degrees, NULL, SDL_FLIP_NONE, gRenderer );
        else
            spriteSheetTexture->Render( x , y , &spriteClips[1], degrees, NULL, SDL_FLIP_NONE, gRenderer );
    }
    else return;
}

