#pragma once

#include "../entities/Entity.h"
#include "../lists/List.h"
using namespace entes;
using namespace list;
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
    //void stress_test();

    List<Entity>::Element<Entity>* get_first(){ return list.get_first();}
};