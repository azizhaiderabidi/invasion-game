#pragma once
#include "SDL.h"
#include "string"
#include "Character.h"
#include "LTexture.h"

class Word
{
    Character* charr;
    int NoLetters;
public:
    Word();
    ~Word();
    Word(LTexture* image, int x,int yposition, char const* text);
    void Render(SDL_Renderer* gRenderer);
};

