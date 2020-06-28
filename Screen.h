#pragma once
#include "LTexture.h"


class Screen{  //Base class for screens from which all other screens will be inherited

protected:
    bool show;
    float x,y;
    float width,height;
    SDL_Rect ScreenClip;  //clipping screen as window screen
    LTexture* ScreenTexture;

public:
    Screen();  //constructor
    virtual ~Screen();  //destructor
    Screen(LTexture* image,float x,float y);  //initializing screen
    float get_x(){return x;}  //getters
    float get_y(){return y;}
    float get_width(){return width;}
    float get_height(){return height;}
//    bool get_show(){return show;}
//    void set_show(bool a){this->show = a;}
    virtual void Render(SDL_Renderer* renderer);  //to render all other screens
    virtual void Render(int,SDL_Renderer* renderer); //to render splash screens





};
