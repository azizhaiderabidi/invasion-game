

#include "Score.h"

Score::Score()
{

}

Score::~Score()
{
    cout<<"Health deallocated"<<endl;
}

Score::Score(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;
    //Frame 0
    spriteClips[ 0 ].x = 225;
    spriteClips[ 0 ].y = 242;
    spriteClips[ 0 ].w = 134;
    spriteClips[ 0 ].h = 36;

    //Frame 1
    spriteClips[ 1 ].x = 225;
    spriteClips[ 1 ].y = 242;
    spriteClips[ 1 ].w = 134;
    spriteClips[ 1 ].h = 36;

    //Frame 2
    spriteClips[ 2 ].x = 225;
    spriteClips[ 2 ].y = 242;
    spriteClips[ 2 ].w = 134;
    spriteClips[ 2 ].h = 36;

    Numberclips[0].x = 284;
    Numberclips[0].y = 172;
    Numberclips[0].w = 15;
    Numberclips[0].h = 20;

    Numberclips[1].x = 300;
    Numberclips[1].y = 172;
    Numberclips[1].w = 15;
    Numberclips[1].h = 20;

    Numberclips[2].x = 316;
    Numberclips[2].y = 172;
    Numberclips[2].w = 15;
    Numberclips[2].h = 20;

    Numberclips[3].x = 333;
    Numberclips[3].y = 172;
    Numberclips[3].w = 20;
    Numberclips[3].h = 20;

    Numberclips[4].x = 300;
    Numberclips[4].y = 194;
    Numberclips[4].w = 15;
    Numberclips[4].h = 20;

    Numberclips[5].x = 317;
    Numberclips[5].y = 194;
    Numberclips[5].w = 15;
    Numberclips[5].h = 20;

    Numberclips[6].x = 337;
    Numberclips[6].y = 194;
    Numberclips[6].w = 15;
    Numberclips[6].h = 20;

    Numberclips[7].x = 300;
    Numberclips[7].y = 217;
    Numberclips[7].w = 15;
    Numberclips[7].h = 20;

    Numberclips[8].x = 319;
    Numberclips[8].y = 217;
    Numberclips[8].w = 15;
    Numberclips[8].h = 20;

    Numberclips[9].x = 337;
    Numberclips[9].y = 217;
    Numberclips[9].w = 15;
    Numberclips[9].h = 24;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
}


void Score::Render(string num,long int& frame, SDL_Renderer* gRenderer)
{
        for(char c : num){
        //spriteSheetTexture->Render( x , y, &spriteClips[0], degrees, NULL, SDL_FLIP_NONE, gRenderer );
        if(c== *"0")
        {
            spriteSheetTexture->Render( x , y, &Numberclips[0], degrees, NULL, SDL_FLIP_NONE, gRenderer );
        }
        if(c== *"1")
        {
            spriteSheetTexture->Render( x , y, &Numberclips[1], degrees, NULL, SDL_FLIP_NONE, gRenderer );
        }
        if(c== *"2")
        {
            spriteSheetTexture->Render( x , y, &Numberclips[2], degrees, NULL, SDL_FLIP_NONE, gRenderer );
        }
        if(c== *"3")
        {
            spriteSheetTexture->Render( x , y, &Numberclips[3], degrees, NULL, SDL_FLIP_NONE, gRenderer );
        }
        if(c== *"4")
        {
            spriteSheetTexture->Render( x , y, &Numberclips[4], degrees, NULL, SDL_FLIP_NONE, gRenderer );
        }
        if(c== *"5")
        {
            spriteSheetTexture->Render( x , y, &Numberclips[5], degrees, NULL, SDL_FLIP_NONE, gRenderer );
        }
        if(c== *"6")
        {
            spriteSheetTexture->Render( x , y, &Numberclips[6], degrees, NULL, SDL_FLIP_NONE, gRenderer );
        }
        if(c== *"7")
        {
            spriteSheetTexture->Render( x , y, &Numberclips[7], degrees, NULL, SDL_FLIP_NONE, gRenderer );
        }
        if(c== *"8")
        {
            spriteSheetTexture->Render( x , y, &Numberclips[8], degrees, NULL, SDL_FLIP_NONE, gRenderer );
        }
        if(c== *"9")
        {
            spriteSheetTexture->Render( x , y, &Numberclips[9], degrees, NULL, SDL_FLIP_NONE, gRenderer );
        }
       this->x += 15;

        }
}

bool Score::Clean()
{
    return (y>768);// || alive==0);
}
