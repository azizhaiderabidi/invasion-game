#include"Enemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
    cout<<"Enemy Deallocated"<<endl;
}

Enemy::Enemy(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;
    //Frame 0
    spriteClips[ 0 ].x =   384;
    spriteClips[ 0 ].y =   0;
    spriteClips[ 0 ].w = 128;
    spriteClips[ 0 ].h = 96;

    //Frame 1
    spriteClips[ 1 ].x = 512;
    spriteClips[ 1 ].y =   0;
    spriteClips[ 1 ].w = 128;
    spriteClips[ 1 ].h = 96;

    //Frame 2
    spriteClips[ 2 ].x = 640;
    spriteClips[ 2 ].y = 0;
    spriteClips[ 2 ].w = 128;
    spriteClips[ 2 ].h = 96;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
}


void Enemy::Move(Unit* player)
{
    float px=player->get_x();
    float py=player->get_y(); //x and y coordinates of player plane
    speedx = 2;
    speedy = 2;
    //If we drop a perpendicular from the enemy to the player, it makes a right angle triangle
    //From enemy we can use cosine angle for the angle towards player
    //base = py-y and hypotenuse is calculated using Pythagoras theorem
    if(y <= py && player->get_alive())
    {
        degrees = acos(((py-y))/ ( sqrt(  pow((y-py),2) + pow((x-px),2)   ) ) ) *  (180 / M_PI) ;
        if(x<px) degrees *= -1; //to balance the rotation on both sides
    }
    else if (player->get_alive())
    {

        y+=speedy;  //just moves vertically down
    }
    //Enemy moves accordingly to plane using cosine and sine functions
    if(player->get_alive() == 0)
    {
        if(degrees==0)  //in case plane is directly below enemy
            y+=speedy;
        else
        {
        speedx=speedx*cos(degrees);
        speedy=speedy*sin(degrees);
        x += speedx;
        y += speedy;
        x += speedx*0.80f;
        y += speedy*0.80f;
        }
    }
    else
    {
        speedx=speedx*cos(degrees);
        speedy=speedy*sin(degrees);
        x += speedx;
        y += speedy;
        x += speedx*0.80f;
        y += speedy*0.80f;
    }

}

void Enemy::Render(long int& frame, SDL_Renderer* gRenderer)
{
    if(alive)
        spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], degrees, NULL, SDL_FLIP_VERTICAL, gRenderer );//flipping sprite vertically
    else
    {
        if(expFrame < 7){

            spriteSheetTexture->Render( x- width/2 + 30, y- height/2, &expSpriteClips[ expFrame ], degrees, NULL, SDL_FLIP_VERTICAL, gRenderer );
            expFrame++;
        }
        else {return;}
    }
}

bool Enemy::Clean()
{
    return (y>768);// || alive==0);
}
