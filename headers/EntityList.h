#pragma once

#include "../headers/Entity.h"
#include "../headers/List.h"

class EntityList
{
private:
    List<Entity> list;
public:
    EntityList();
    ~EntityList();
    void move();
    void draw(sf::RenderWindow* window);
    void add(Entity* ent);
};