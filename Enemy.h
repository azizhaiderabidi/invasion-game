#pragma once

#include"Unit.h"

class Enemy:public Unit
{
public:
    Enemy(LTexture* image, float x, float y);
    Enemy();
    virtual ~Enemy();
    void Move(Unit*);  //moves accordingly with player position
    void Render(long int& frame, SDL_Renderer* gRenderer);
    bool Clean();
};
