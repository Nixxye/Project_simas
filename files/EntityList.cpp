#include "../headers/EntityList.h"

EntityList::EntityList():
list()
{

}

EntityList::~EntityList()
{
    
}

void EntityList::move()
{
    auto aux = list.begin();
    while(aux)
    {
        aux->get_data()->move();
        aux = aux->get_next();        
    }
}

void EntityList::draw(sf::RenderWindow* window)
{

}

void EntityList::add(Entity* ent)
{
    list.add(ent);
}