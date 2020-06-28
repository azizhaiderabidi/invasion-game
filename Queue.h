#pragma once
#include"Node.h"

class Queue  //list used for adding different game objects //separate lists for each
{
private:
    Node* head;
    Node* tail;
public:
    Queue();
    ~Queue();
    void Clear();//empties current queue,deallocates all nodes and associated data
    void Enqueue(Unit*);  //add unit to queue
    void Dequeues();
    void Render(long int& frame, SDL_Renderer* gRenderer); //render each unit present in queue
    void Move(Unit* = NULL);  //moves each of the unit present in queue
    int length();  //return size of list
    friend class Collisions;  //collision and game can access this class
    friend class Game;
};
