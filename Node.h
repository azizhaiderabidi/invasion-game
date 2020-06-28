#pragma once
#include "Unit.h"

struct Node
{
    Unit* unit;
    Node* next;
    Node* prev;
    Node()
    {
        unit=NULL;next=NULL;prev=NULL;
    }
    ~Node()
    {
        delete unit;
    }
};
