#include "Unit.h"

class RBullet:public Unit
{
    public:
        RBullet();
        RBullet(LTexture* image, Unit*);// float x, float y);
        virtual ~RBullet();
        void Move(Unit* = NULL);
        void Render(long int&, SDL_Renderer*);

};
