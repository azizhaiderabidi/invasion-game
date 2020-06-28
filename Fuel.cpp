
#include "Fuel.h"

Fuel::Fuel()
{

}

Fuel::~Fuel()
{
    cout<<"Fuel deallocated"<<endl;
}

Fuel::Fuel(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;
    //Frame 0
    spriteClips[ 0 ].x = 71;
    spriteClips[ 0 ].y = 96;
    spriteClips[ 0 ].w = 25;
    spriteClips[ 0 ].h = 36;

    //Frame 1
    spriteClips[ 1 ].x = 72;
    spriteClips[ 1 ].y = 96;
    spriteClips[ 1 ].w = 36;
    spriteClips[ 1 ].h = 36;

    //Frame 2
    spriteClips[ 2 ].x = 100;
    spriteClips[ 2 ].y = 96;
    spriteClips[ 2 ].w = 36;
    spriteClips[ 2 ].h = 36;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
}

void Fuel::Move(Unit* plane)
{
    speedy = 5;
    //speedx = 2;
    y+=speedy;


}

void Fuel::Render(long int& frame, SDL_Renderer* gRenderer)
{
    if(alive)
        spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[0], degrees, NULL, SDL_FLIP_NONE, gRenderer );//flipping sprite vertically
//    else
//    {
//
//        spriteSheetTexture->Render( x- width/2 + 30, y- height/2, &spriteClips[2], degrees, NULL, SDL_FLIP_NONE, gRenderer );
//    }
}

bool Fuel::Clean()
{
    return (y>768);// || alive==0);
}
