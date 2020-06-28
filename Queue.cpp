#include"Queue.h"
#include<iostream>

using namespace std;

Queue::Queue()
{
    head=NULL;
    tail=NULL;
}

Queue::~Queue()
{
    while(head)
    {
        std::cout<< "Queue destroyed.\n";
        Node* temp=head;
        head=head->prev;
        delete temp;
    }
}

void Queue::Enqueue(Unit* unit)
{
    if (head==NULL && tail ==NULL)//if there are no elements in the queue
    {
        Node* temp= new Node;
        temp->unit=unit;
        head=temp;
        tail=temp;
        std::cout << "Unit added to queue.\n";
    }
    else
    {
        Node* temp = new Node;
        temp->unit=unit;
        tail->prev=temp;
        tail=temp;
        tail->next=head;
        std::cout << "Unit added to queue.\n";
    }


}

int Queue::length()
{
    Node* s=head;
    int Size=0;
    while(s)
    {
        Size++;
        s=s->prev;
    }
    return Size;

}

void Queue::Clear()
{
    Node* temp=head;
    while(temp)
    {
        delete head->unit;//deleting object
        delete head;//deleting start node, the unit is deleted with the node
        temp=temp->prev;
        head=temp;
    }
    head=NULL;
    tail=NULL;
}

void Queue::Dequeues()//Dequeues first in object of the queue depending on if it's been used completely
{
    if (length()>1)
    {
        if(head->unit->Clean())//For deallocating enemies
        {
            Node* temp=head;
            head=head->prev;
            delete temp->unit;
            delete temp;
        }
    }
    else if(length()==1)
    {
        if(head->unit->Clean())
        {
            delete head->unit;
            delete head;
            head=NULL;
            tail=NULL;
        }

    }
}

void Queue::Render(long int& frame, SDL_Renderer* gRenderer)
{
    Node* s=head;
    while(s)
    {
        s->unit->Render(frame,gRenderer);
        s=s->prev;
    }


}

void Queue::Move(Unit* object)//moving all enemies
{
    Node* s=head;
    while(s)
    {
        s->unit->Move(object);
        s=s->prev;
    }

}


