#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include"LTexture.h"
using namespace std;


enum MOTION {RIGHT, LEFT, UP, DOWN};

//Basic parent class from which all games object will be inherited

class Unit
{
    protected:

        bool alive;
        float x;
        float y;
        float speedx;
        float speedy;
        float width;
        float height;
        float friction; //lower speed means more friction
        enum ANIMATION_FRAMES {FLYING_FRAMES = 3};  //assigning value to variable type
        SDL_Rect spriteClips[ FLYING_FRAMES ];  //array of 3 rectangular clips
        LTexture*  spriteSheetTexture;//contains full texture sheet
        LTexture* Sheet;  //additional sheet
        virtual bool Clean();//returns 1 if unit has left screen, for checking deallocation
        friend class Queue; //friend classes have access to all private and public
        friend class Bullet; //attributes and functions of this base class
        friend class MBullet;
        friend class RBullet;
        enum EXPLODING_FRAMES {EXPLODING_FRAMES = 7};
        int expFrame;
        SDL_Rect expSpriteClips[ EXPLODING_FRAMES ]; //for explosion effect 7 rectangular clips are used
        double degrees;//to keep track of the degree rotation, initialized to 0

    public:

        Unit(LTexture* image, float x, float y); //overloaded constructor
        Unit(); //constructor
        virtual ~Unit(); //destructor
        void set_alive(bool); //setter for alive
        bool get_alive();  //getter for alive
        int myHealth=3;  //for health of unit used for player
        virtual void Move(int direction); //moving plane in direction
        virtual void Move(Unit* = NULL);  //Normal movement
        virtual void Render(long int& frame, SDL_Renderer* gRenderer); //to be used for rendering most of the child objects
        virtual void Render(Unit*,long int& frame, SDL_Renderer* gRenderer); //to be used for rendering health of player
        virtual void Render(Unit*,int,long int& frame, SDL_Renderer* gRenderer); //to be used for rendering backgrounds
        virtual void Render(string,long int& frame, SDL_Renderer* gRenderer); //used for rendering game score
        virtual Unit* Fire();  //Generate bullets for playeri
        virtual Unit* Fire2(LTexture*);
        float get_x(){return x;}  //getter and setter for positions
        float get_y(){return y;}
        void set_x(float a){this-> x =a;}
        void set_y(float a){this-> y =a;}
        void set_health(int a){this->myHealth =a;}
        float get_width(){return width;}
        float get_height(){return height;}

};



