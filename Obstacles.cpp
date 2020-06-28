
#include "Obstacles.h"

Obstacles::Obstacles()
{

}

Obstacles::~Obstacles()
{
    cout<<"Obstacle deallocated"<<endl;
}

Obstacles::Obstacles(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;
    //Frame 0
    spriteClips[ 0 ].x = 292;
    spriteClips[ 0 ].y = 110;
    spriteClips[ 0 ].w = 38;
    spriteClips[ 0 ].h = 56;

    //Frame 1
    spriteClips[ 1 ].x = 341;
    spriteClips[ 1 ].y = 110;
    spriteClips[ 1 ].w = 38;
    spriteClips[ 1 ].h = 56;

    //Frame 2
    spriteClips[ 2 ].x = 292;
    spriteClips[ 2 ].y = 110;
    spriteClips[ 2 ].w = 38;
    spriteClips[ 2 ].h = 56;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
}

void Obstacles::Move(Unit* plane)
{
    speedy = 5;
    //speedx = 2;
    y+=speedy;


}

void Obstacles::Render(long int& frame, SDL_Renderer* gRenderer)
{
    if(alive)
        spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], degrees, NULL, SDL_FLIP_NONE, gRenderer );//flipping sprite vertically
    else
    {
        if(expFrame < 7){

            spriteSheetTexture->Render( x- width/2 + 30, y- height/2, &expSpriteClips[ expFrame ], degrees, NULL, SDL_FLIP_VERTICAL, gRenderer );
            expFrame++;
        }
        else {return;}
    }
}

bool Obstacles::Clean()
{
    return (y>768);// || alive==0);
}
