
#include "Collision.h"
#include "Rect.h"

Collisions::Collisions()
{
    //ctor
}

Collisions::~Collisions()
{
    //dtor
}

void Collisions::collision(Unit* object,Queue* enemies)
{

    Rect first(object->get_x(),object->get_y(),(object->get_x()+object->get_width()),object->get_y(),object->get_x(),(object->get_y()+object->get_height()),(object->get_x()+object->get_width()),(object->get_y()+object->get_height()));
    Node* s=enemies->head;
    while(s)
    {
        Rect second(s->unit->get_x(),s->unit->get_y(),(s->unit->get_x()+s->unit->get_width()),s->unit->get_y(),s->unit->get_x(),(s->unit->get_y()+s->unit->get_height()),(s->unit->get_x()+s->unit->get_width()),(s->unit->get_y()+s->unit->get_height()));
        if (second.CollidesWith(first))
        {
            if (s->unit->get_alive() && object->get_alive())
            {
                object->set_alive(false);
                s->unit->set_alive(false);
            }
        }
        s=s->prev;
    }

}

void Collisions::collision(int status, Unit* object,Queue* enemies)
{

    Rect first(object->get_x(),object->get_y(),(object->get_x()+object->get_width()),object->get_y(),object->get_x(),(object->get_y()+object->get_height()),(object->get_x()+object->get_width()),(object->get_y()+object->get_height()));
    Node* s=enemies->head;
    while(s)
    {
        bool collide = true;
        Rect second(s->unit->get_x(),s->unit->get_y(),(s->unit->get_x()+s->unit->get_width()),s->unit->get_y(),s->unit->get_x(),(s->unit->get_y()+s->unit->get_height()),(s->unit->get_x()+s->unit->get_width()),(s->unit->get_y()+s->unit->get_height()));
        if (second.CollidesWith(first) && collide == true)
        {
            if (s->unit->get_alive() && object->get_alive())
            {
                if(object->myHealth==1){
                object->set_alive(false);
            }
            s->unit->set_alive(false);
            collide=false;
            object->myHealth = object->myHealth - 1;
            }
        }
        s=s->prev;
    }

}

void Collisions::collision(int status,int &temp, Unit* object,Queue* enemies)
{

    Rect first(object->get_x(),object->get_y(),(object->get_x()+object->get_width()),object->get_y(),object->get_x(),(object->get_y()+object->get_height()),(object->get_x()+object->get_width()),(object->get_y()+object->get_height()));
    Node* s=enemies->head;
    while(s)
    {
        Rect second(s->unit->get_x(),s->unit->get_y(),(s->unit->get_x()+s->unit->get_width()),s->unit->get_y(),s->unit->get_x(),(s->unit->get_y()+s->unit->get_height()),(s->unit->get_x()+s->unit->get_width()),(s->unit->get_y()+s->unit->get_height()));

        if (second.CollidesWith(first))
        {
            if (s->unit->get_alive() && object->get_alive())
            {
                if(object->myHealth==300)
                {
                object->set_alive(false);
                }
            s->unit->set_alive(false);
            temp=0;
            }
        }
        s=s->prev;
    }

}

void Collisions::collision(bool status, Unit* object,Queue* enemies)
{
    Rect first(object->get_x(),object->get_y(),(object->get_x()+object->get_width()),object->get_y(),object->get_x(),(object->get_y()+object->get_height()),(object->get_x()+object->get_width()),(object->get_y()+object->get_height()));
    Node* s=enemies->head;
    while(s)
    {
        bool collide = true;
        Rect second(s->unit->get_x(),s->unit->get_y(),(s->unit->get_x()+s->unit->get_width()),s->unit->get_y(),s->unit->get_x(),(s->unit->get_y()+s->unit->get_height()),(s->unit->get_x()+s->unit->get_width()),(s->unit->get_y()+s->unit->get_height()));

        if (second.CollidesWith(first) && collide == true)
        {
            //Mix_PlayChannel(-1,game.gBoost_s,0);
            if (s->unit->get_alive() && object->get_alive())
            {
            s->unit->set_alive(false);
            collide=false;
            if(object->myHealth < 3)
                {
                object->myHealth = object->myHealth + 1;
                }
            }
        }
        s=s->prev;
    }

}

void Collisions::collision(Queue* bullets,Queue* enemies)
{
    Node*s = bullets->head;
    while(s)
    {
        if(s->unit->get_alive())
            collision(s->unit,enemies);
        s=s->prev;
    }


}
