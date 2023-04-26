#pragma once

#include "Entity.h"

class EntityList
{
private:
    class ElementList
    {
    private:
        ElementList* next;
        ElementList* next;
        Entity* data;
    public:
        ElementList(){}
        ~ElementList(){}
    };
    ElementList* head;
    ElementList* tail;
public:
    EntityList();
    ~EntityList();
    void move();
    void draw();
    void add(Entity* ent);

};