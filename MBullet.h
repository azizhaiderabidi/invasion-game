#ifndef MBULLET_H
#define MBULLET_H
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"
#include "Unit.h"

class MBullet:public Unit
{
    public:
        MBullet();
        MBullet(LTexture* image, Unit*);// float x, float y of plane);
        virtual ~MBullet();
        void Move(Unit* = NULL); //Since fired by player
        void Render(long int&, SDL_Renderer*);


};

#endif // MBULLET_H

