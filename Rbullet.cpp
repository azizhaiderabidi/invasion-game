
#include "RBullet.h"
#include <iostream>

RBullet::RBullet()
{

}

RBullet::RBullet(LTexture* image, Unit* plane):Unit(image,plane->x,plane->y)
{
    spriteSheetTexture = image;
    //Frame 0, player bullets
     spriteClips[ 0 ].x =   40;
    spriteClips[ 0 ].y =   0;
    spriteClips[ 0 ].w = 40;
    spriteClips[ 0 ].h = 40;

    //Frame 1, enemy bullets
    spriteClips[ 1 ].x = 36;
    spriteClips[ 1 ].y =   96;
    spriteClips[ 1 ].w = 36;
    spriteClips[ 1 ].h = 36;

    //Frame 2
    spriteClips[ 2 ].x = 36;
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
RBullet::~RBullet()
{
    std::cout << "Bullet deallocated.\n";
}
void RBullet::Move(Unit* plane)
{
    speedy = 6;
    y+=speedy;
}

void RBullet::Render(long int& toLoad, SDL_Renderer* gRenderer)
{
    if(alive)
        spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ 0 ], 0, NULL, SDL_FLIP_NONE, gRenderer );//flipping sprite vertically
    else
    {
        return;
    }
}
