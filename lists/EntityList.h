#pragma once

#include "../entities/Entity.h"
#include "../lists/List.h"
#
using namespace entes;
using namespace list;
class EntityList
{
private:
    List<Entity> list;
public:
    EntityList();
    ~EntityList();

    void run();
    void draw();
    void add(Entity* ent);

    void set_position(sf::Vector2f pos);
    void set_alive(bool a);

    const int get_size() const { return list.get_size();}
    List<Entity>::Iterator<Entity> get_first(){ return list.get_first();}
};