#include "Unit.h"
#include "Bullet.h"
#include "MBullet.h"
Unit::Unit()
{

}



Unit::Unit(LTexture* image, float x, float y) //x and y are points where object would be created
{
    spriteSheetTexture = image;  //will render this ltexture sheet

    //clipping images saved in L_texture
    //Frame 0
    spriteClips[ 0 ].x =   0; //start point x
    spriteClips[ 0 ].y =   0; //start point y
    spriteClips[ 0 ].w = 128; //width of clip
    spriteClips[ 0 ].h = 96;  //height of clip

    //Frame 1
    spriteClips[ 1 ].x = 128;
    spriteClips[ 1 ].y =   0;
    spriteClips[ 1 ].w = 128;
    spriteClips[ 1 ].h = 96;

    //Frame 2
    spriteClips[ 2 ].x = 256;
    spriteClips[ 2 ].y = 0;
    spriteClips[ 2 ].w = 128;
    spriteClips[ 2 ].h = 96;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;  //constant friction
    speedx = 0;
    speedy = 0;
    degrees= 0;
    alive  = true;

    //Explosion frames

    expSpriteClips[ 0 ].x=0;
    expSpriteClips[ 0 ].y=138;
    expSpriteClips[ 0 ].w=30;
    expSpriteClips[ 0 ].h=30;

    expSpriteClips[ 1 ].x=35;
    expSpriteClips[ 1 ].y=133;
    expSpriteClips[ 1 ].w=40;
    expSpriteClips[ 1 ].h=40;

    expSpriteClips[ 2 ].x=75;
    expSpriteClips[ 2 ].y=130;
    expSpriteClips[ 2 ].w=42;
    expSpriteClips[ 2 ].h=42;

    expSpriteClips[ 3 ].x=117;
    expSpriteClips[ 3 ].y=130;
    expSpriteClips[ 3 ].w=40;
    expSpriteClips[ 3 ].h=42;

    expSpriteClips[ 4 ].x=157;
    expSpriteClips[ 4 ].y=130;
    expSpriteClips[ 4 ].w=40;
    expSpriteClips[ 4 ].h=42;

    expSpriteClips[ 5 ].x=195;
    expSpriteClips[ 5 ].y=130;
    expSpriteClips[ 5 ].w=42;
    expSpriteClips[ 5 ].h=42;

    expSpriteClips[ 6 ].x=235;
    expSpriteClips[ 6 ].y=130;
    expSpriteClips[ 6 ].w=42;
    expSpriteClips[ 6 ].h=42;

    expFrame=0;
}


Unit::~Unit()
{
    spriteSheetTexture = NULL;
}

void Unit::set_alive(bool alive)
{
    this->alive = alive;
}

bool Unit::get_alive()
{
    return alive;
}

void Unit::Move(int direction)  //Using enum for direction types
{
    if(!alive) return;
    if(direction==LEFT)
    {
        speedx = -5;
        x+=speedx;
    }

    if(direction==RIGHT)
    {
        speedx = 5;
        x+=speedx;
    }

    if(direction==UP)
    {
        speedy = -5;
        y+=speedy;
    }

    if(direction==DOWN)
    {
        speedy = 5;
        y+=speedy;
    }

}

void Unit::Move(Unit* plane)//responsible for the smooth movement after releasing arrow key
{
    speedx = speedx * friction;
    speedy = speedy * friction;
    if(x<800 && x>-1 && y<600 && y>-1)
    {
    x = x + speedx;
    y = y + speedy;
    }
}

Unit* Unit::Fire()  //returning bullet for player
{
    Bullet* bullet=NULL;
    if(alive)
        bullet=new Bullet(spriteSheetTexture, this);  //Initializing bullet
    return bullet;
}

Unit* Unit::Fire2(LTexture* Mtexture) //returning Mbullet for player
{
    Sheet = Mtexture;
    MBullet* bullet2=NULL;
    if(alive)
        bullet2=new MBullet(Sheet, this);
    return bullet2;
}

void Unit::Render(long int& frame, SDL_Renderer* gRenderer)  //takes frame for clip gRenderer
{

    if(alive)  //if objects alive it will be render
        spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], degrees, NULL, SDL_FLIP_NONE, gRenderer );
    else  //else explosion will appears on screen
    {
        if(expFrame < 7){

            spriteSheetTexture->Render( x- width/2 + 30, y- height/2, &expSpriteClips[ expFrame ], degrees, NULL, SDL_FLIP_VERTICAL, gRenderer );
            expFrame++;
        }
        else {return;}  //rendering ends after explosion
    }
}
void Unit::Render(Unit* plane,long int& frame, SDL_Renderer* gRenderer)
{
    cout<<"Health render"<<endl;
}

void Unit::Render(Unit* plane,int a, long int& frame, SDL_Renderer* gRenderer)
{
    cout<<"Icon render"<<endl;
}

void Unit::Render(string c,long int& frame, SDL_Renderer* gRenderer)
{
    cout<<"Score render"<<endl;
}


bool Unit::Clean()  //deallocating objects after passing screen
{
    return (y<0);
}



