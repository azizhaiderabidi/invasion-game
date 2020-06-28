#include "Background1.h"

Background1::Background1()
{

}

Background1::~Background1()
{
    cout<<"Background deallocated"<<endl;
}

Background1::Background1(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;
    //Frame 0
    spriteClips[ 0 ].x = 0;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = 800;
    spriteClips[ 0 ].h = 600;

    //Frame 1
    spriteClips[ 1 ].x = 0;
    spriteClips[ 1 ].y = 0;
    spriteClips[ 1 ].w = 800;
    spriteClips[ 1 ].h = 600;

    //Frame 2
    spriteClips[ 2 ].x = 0;
    spriteClips[ 2 ].y = 0;
    spriteClips[ 2 ].w = 800;
    spriteClips[ 2 ].h = 600;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
}


void Background1::Render(Unit* plane,long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x, y, &spriteClips[0], degrees, NULL, SDL_FLIP_NONE, gRenderer );

}
void Background1::Move(Unit*)
{
    if(y == 0)
    y = -600;
    speedy = 1;
    y += speedy;
}

bool Background1::Clean()
{
    return (y>768);// || alive==0);
}



