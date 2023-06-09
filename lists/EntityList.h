#pragma once

#include "../entities/Entity.h"
#include "../lists/List.h"

namespace Lists
{
    class EntityList
    {
    private:
        Lists::List<Entes::Entity> list;
    public:
        EntityList();
        ~EntityList();

        void run();
        void draw();
        void add(Entes::Entity* ent);

        void clear();

        void set_position(sf::Vector2f pos);
        void set_alive(bool a);

        const int get_size() const { return list.get_size();}
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> get_first(){ return list.get_first();}
    };    
}
