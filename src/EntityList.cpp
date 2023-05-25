#include "../lists/EntityList.h"
#include "../entities/Enemy.h"


#include <iostream>

using namespace std;
EntityList::EntityList():
list()
{

}

EntityList::~EntityList()
{

}

void EntityList::run()
{
    List<Entity>::Iterator<Entity> aux = list.get_first();
    while(aux != nullptr)
    {
        (*aux)->run();
        aux++;        
    }
}

void EntityList::draw()
{
    List<Entity>::Iterator<Entity> aux = list.get_first();
    while(aux != nullptr)
    {
        (*aux)->draw();
        aux++; 
    }
 }   

void EntityList::add(Entity* ent)
{
    list.push(ent);
}
void EntityList::set_position(sf::Vector2f pos)
{
    List<Entity>::Iterator<Entity> aux = list.get_first();
    while(aux != nullptr)
    {
        (*aux)->set_position(pos);
        aux++;        
    }    
}
void EntityList::set_alive(bool a)
{
    List<Entity>::Iterator<Entity> aux = list.get_first();
    while(aux != nullptr)
    {
        (*aux)->set_alive(a);
        aux++;       
    }    
}

