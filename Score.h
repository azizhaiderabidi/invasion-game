#include"Unit.h"


class Score :public Unit
{
public:
    Score(LTexture* image, float x, float y);
    Score();
    SDL_Rect Numberclips[10]; //for clipping 0 to 9 digits
    virtual ~Score();
    void Render(string,long int& frame,SDL_Renderer* gRenderer); //takes numbers as string in argument
    bool Clean();

};
