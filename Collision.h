#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "Rect.h"
#include "Queue.h"


class Collisions //class for checking collision
{
    public:
        Collisions();
        virtual ~Collisions();
        void collision(Unit*,Queue*); //direct collision of player with list of enemies with decreasing health
        void collision(Queue*,Queue*); //collision of bullets with enemies
        void collision(int, Unit*,Queue*); //collision of player with list of enemies with increasing health
        void collision(bool, Unit*,Queue*); //collision of player with fuel to increase health
        void collision(int,int&, Unit*,Queue*); //collision of player with boost power up
        friend class Game;
};

#endif // COLLISIONS_H
