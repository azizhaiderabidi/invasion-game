
#include "Health.h"

Health::Health()
{

}

Health::~Health()
{
    cout<<"Health deallocated"<<endl;
}

Health::Health(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;
    //Frame 0
    spriteClips[ 0 ].x = 420;
    spriteClips[ 0 ].y = 100;
    spriteClips[ 0 ].w = 110;
    spriteClips[ 0 ].h = 70;

    //Frame 1
    spriteClips[ 1 ].x = 525;
    spriteClips[ 1 ].y = 100;
    spriteClips[ 1 ].w = 110;
    spriteClips[ 1 ].h = 70;

    //Frame 2
    spriteClips[ 2 ].x = 632;
    spriteClips[ 2 ].y = 100;
    spriteClips[ 2 ].w = 110;
    spriteClips[ 2 ].h = 70;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
}


void Health::Render(Unit* plane,long int& frame, SDL_Renderer* gRenderer)
{
    if(plane->get_alive())
    {
        if(plane->myHealth==3)
            spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[0], degrees, NULL, SDL_FLIP_NONE, gRenderer );//flipping sprite vertically
        else if(plane->myHealth==2)
            spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[1], degrees, NULL, SDL_FLIP_NONE, gRenderer );
        else if(plane->myHealth==1)
            spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[2], degrees, NULL, SDL_FLIP_NONE, gRenderer );
    }
}

