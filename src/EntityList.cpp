#include "../lists/EntityList.h"

namespace Lists
{
    EntityList::EntityList():
    list()
    {

    }

    EntityList::~EntityList()
    {

    }

    void EntityList::execute()
    {
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> aux = list.get_first();
        while(aux != nullptr)
        {
            (*aux)->execute();
            aux++;        
        }
    }

    void EntityList::draw()
    {
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> aux = list.get_first();
        while(aux != nullptr)
        {
            (*aux)->draw();
            aux++; 
        }
    }   

    void EntityList::add(Entes::Entity* ent)
    {
        list.push(ent);
    }
    void EntityList::clear()
    {
        list.clear();
    }
    void EntityList::set_position(sf::Vector2f pos)
    {
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> aux = list.get_first();
        while(aux != nullptr)
        {
            (*aux)->set_position(pos);
            aux++;        
        }    
    }
    void EntityList::set_alive(bool a)
    {
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> aux = list.get_first();
        while(aux != nullptr)
        {
            (*aux)->set_alive(a);
            aux++;       
        }    
    }    
}


