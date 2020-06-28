
#include "Word.h"
#include <iostream>
#include "string.h"
#include "Character.h"
#include <ctype.h>

using namespace std;

Word::Word()
{

}
Word::Word(LTexture* image,int SCREEN_WIDTH, int yposition, char const* text)
{
    NoLetters=strlen(text);
    charr = new Character[NoLetters];

        int shift = -(NoLetters/2); //access every element

        for(int i=0; i<NoLetters; i++)
        {
            charr[i].display(image, SCREEN_WIDTH + (shift*26), yposition, text[i]); //setting position of the clips
            //cout<<"here"<<endl;
            shift++;
        }

}
Word::~Word()
{
    delete[] charr;
}
void Word::Render(SDL_Renderer* gRenderer)
{
    for(int i=0; i<NoLetters;i++)
    {
        //charr[i].display(image, SCREEN_WIDTH + (shift*44), yposition, text[i]);
        //cout<<"here2"<<endl;
        charr[i].Render(gRenderer); // display the clips
        //cout<<"here3"<<endl;

    }

}

