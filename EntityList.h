#pragma once

#include "Entity.h"

class EntityList
{
private:
    class ElementList
    {
    public:
        ElementList* next;
        ElementList* prev;
        Entity* data;
        ElementList(){}
        ~ElementList(){}
    };
    ElementList* head;
    ElementList* tail;
public:
    EntityList();
    ~EntityList();
    void move();
    void draw(sf::RenderWindow* window);
    void add(Entity* ent);

};