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

        void execute();
        void draw();
        void add(Entes::Entity* ent);

        void clear();
        void save(std::ofstream& file);

        void set_position(sf::Vector2f pos);

        const int get_size() const { return list.get_size();}
        const int get_nkilled();
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> get_first(){ return list.get_first();}
    };    
}
