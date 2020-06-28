#include "LTexture.h"


class Button //for Screens
{
private:
    float x,y,w,h;   //button size and position
    bool pressed;  //pressing effect
    SDL_Rect ButtonClip[2];  //2 clips one for normal rendering and other for mouse effect
    LTexture* ButtonTexture; // saves image for buttons
public:
    Button(); //constructor
    ~Button();  //destructor
    Button(LTexture* image,float x,float y);
    void Render(int a,SDL_Renderer* renderer);  //rendering button
    bool get_pressed(){return pressed;} //setter and getter for pressing effect
    void setPressed(bool a){this->pressed = a;}
    bool selected = false;  //used for mouse button effect



};

