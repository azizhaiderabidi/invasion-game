#ifndef BULLET_H
#define BULLET_H
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"
#include "Unit.h"

class Bullet:public Unit
{
    public:
        Bullet();
        Bullet(LTexture* image, Unit*);// float x, float y of plane);
        virtual ~Bullet();
        void Move(Unit* = NULL);  //Since fired by player
        void Render(long int&, SDL_Renderer*);


};

#endif // BULLET_H
