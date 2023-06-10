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
    const int EntityList::get_nkilled()
    {
        int n = 0;
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> aux = list.get_first();
        while(aux != nullptr)
        {
            if (!((*aux)->get_alive()))
                n++;
            aux++;        
        }  
        return n;
    }
    void EntityList::save(std::ofstream& file)
    {
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> aux = list.get_first();
        while(aux != nullptr)
        {
            (*aux)->save(file);
            aux++;        
        }      
    }
}


