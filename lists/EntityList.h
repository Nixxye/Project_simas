#pragma once

#include "../entities/Entity.h"
#include "../lists/List.h"

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
    void stress_test();

    auto get_first(){ return list.get_first()->get_data();}
};