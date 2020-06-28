

#pragma once

#include <iostream>
#include "SDL.h"
#include "string"
#include "Point.h"
#include "LTexture.h"


class Character
{
private:
    int positionx;
    int positiony;
    int width; //of character
    int height;
    char text;
    Point* pos;
    LTexture* SpriteSheetTexture;
    SDL_Rect spriteClips;
public:
    Character();
    ~Character();
    Character (Character & a);
    int ASCII(char text);
    void display(LTexture* image, int x, int y, char text );
 //   void SetPosition(Point* pos);
    void Render(SDL_Renderer* gRenderer);

};

