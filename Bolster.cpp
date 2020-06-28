
#include "Bolster.h"

Bolster::Bolster()
{

}

Bolster::~Bolster()
{
    cout<<"Bolster deallocated"<<endl;
}

Bolster::Bolster(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;
    //Frame 0
    spriteClips[ 0 ].x = 75;
    spriteClips[ 0 ].y = 88;
    spriteClips[ 0 ].w = 72;
    spriteClips[ 0 ].h = 73;

    //Frame 1
    spriteClips[ 1 ].x = 75;
    spriteClips[ 1 ].y = 166;
    spriteClips[ 1 ].w = 72;
    spriteClips[ 1 ].h = 73;

    //Frame 2
    spriteClips[ 2 ].x = 75;
    spriteClips[ 2 ].y = 88;
    spriteClips[ 2 ].w = 72;
    spriteClips[ 2 ].h = 73;

    expSpriteClips[ 0 ].x = 240;
    expSpriteClips[ 0 ].y = 80;
    expSpriteClips[ 0 ].w = 40;
    expSpriteClips[ 0 ].h = 80;

    //Frame 2
    expSpriteClips[ 1 ].x = 320;
    expSpriteClips[ 1 ].y = 80;
    expSpriteClips[ 1 ].w = 40;
    expSpriteClips[ 1 ].h = 80;

    expSpriteClips[ 2 ].x = 400;
    expSpriteClips[ 2 ].y = 80;
    expSpriteClips[ 2 ].w = 40;
    expSpriteClips[ 2 ].h = 80;

    expSpriteClips[ 3 ].x = 480;
    expSpriteClips[ 3 ].y = 80;
    expSpriteClips[ 3 ].w = 40;
    expSpriteClips[ 3 ].h = 80;

    expSpriteClips[ 4 ].x = 560;
    expSpriteClips[ 4 ].y = 80;
    expSpriteClips[ 4 ].w = 40;
    expSpriteClips[ 4 ].h = 80;

    expSpriteClips[ 5 ].x = 640;
    expSpriteClips[ 5 ].y = 80;
    expSpriteClips[ 5 ].w = 40;
    expSpriteClips[ 5 ].h = 80;

    expSpriteClips[ 6 ].x = 720;
    expSpriteClips[ 6 ].y = 80;
    expSpriteClips[ 6 ].w = 40;
    expSpriteClips[ 6 ].h = 80;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    if(x<400){
    speedx = 1;
    }
    else{
    speedx = -1;
    }
    //speedx = 0;
    speedy = 2;
    alive  = true;
}

void Bolster::Move(Unit* plane)
{
    x += speedx;
    y += speedy;


}

void Bolster::Render(long int& frame, SDL_Renderer* gRenderer)
{
    if(alive)
        spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[frame%2 ], degrees, NULL, SDL_FLIP_VERTICAL, gRenderer );//flipping sprite vertically
    else
    {
        if(expFrame < 7){

            spriteSheetTexture->Render( x- width/2 + 30, y- height/2, &expSpriteClips[ expFrame ], degrees, NULL, SDL_FLIP_VERTICAL, gRenderer );
            expFrame++;
        }
        else {return;}
    }
}


bool Bolster::Clean()
{
    return (y>768);// || alive==0);
}
