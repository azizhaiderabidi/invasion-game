
#include "Character.h"
#include <iostream>
#include "LTexture.h"

using namespace std;
Character :: Character(){
}

Character::~Character()
{
    this->positionx=0;
    this->positiony=0;
    this->width=0; //of character
    this->height=0;
    this->pos=NULL;
    this->SpriteSheetTexture=NULL;
}

Character:: Character (Character & a){ //copy constructor
	this->positionx=a.positionx;
	this->positiony=a.positiony;
	this->width=a.width;
	this->height=a.height;
	this->text=a.text;
	this->pos=a.pos;
	this->SpriteSheetTexture=a.SpriteSheetTexture;
	this->spriteClips=a.spriteClips;
}

int Character::ASCII(char text){
    char capital=toupper(text);//all alphabets in capital
    //cout<<capital<<endl;
    int its_ascii= int (capital);
    return its_ascii-65;//keeping A's ascii as 0(reference)
}

void Character::display(LTexture* image, int x, int y, char text ){
    this->positionx = x;
    this->positiony = y;
    SpriteSheetTexture =image;
    if (ASCII(text)>=0 && ASCII(text)<=25){ //constant clip size for the alphabhets
            spriteClips.w=44;
            spriteClips.h=48;
    }
    if (ASCII(text)>= 0 && ASCII(text)<= 11){ //checking if ascii in first row
        spriteClips.x=ASCII(text)*44;
        spriteClips.y=0;
    }
    if(ASCII(text) > 11 && ASCII(text) <= 22){ //check if in 2nd row
        spriteClips.x = (ASCII(text) -11)* 44;
        spriteClips.y = 48;
    }
    if(ASCII(text) > 22 && ASCII(text) <= 25){ //check if in 3rd
        spriteClips.x = (ASCII(text)-22) *44;
        spriteClips.y = 48*2;
    }
    if (ASCII(text)== -33){//for space
        spriteClips.w = 44;
        spriteClips.h = 48;
        spriteClips.x = 44*(ASCII(text)-22);
        spriteClips.y = 96;
    }
    this->width = spriteClips.w;
    this->height = spriteClips.h;
}

void Character::Render(SDL_Renderer* gRenderer)
{
    SpriteSheetTexture->Render( positionx, positiony-height/2, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

