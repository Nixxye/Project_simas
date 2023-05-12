#include "../lists/EntityList.h"
#include "../entities/Enemy.h"
#include <iostream>

EntityList::EntityList():
list()
{

}

EntityList::~EntityList()
{
    
}

void EntityList::move()
{
    List<Entity>::Element<Entity>* aux = list.get_first();
    while(aux)
    {
        aux->get_data()->move();
        aux = aux->get_next();        
    }
}

void EntityList::draw(sf::RenderWindow* window)
{
    List<Entity>::Element<Entity>* aux = list.get_first();
    while(aux)
    {
        aux->get_data()->draw(window);
        aux = aux->get_next();        
    }
}

void EntityList::add(Entity* ent)
{
    list.push(ent);
}
/*
void EntityList::stress_test()
{
    int n = list.get_size();
    int x = rand()%1000;
    int y = rand()%1000;
    
    if (n < 20 && list.get_first()->get_data()->get_speed() > 0)
    {
        Enemy* aux = new Enemy();
        aux->set_position(sf::Vector2f(x, y));
        add(aux);
    }
    if (n > 15)
    {
        if ((bool) rand() % 2)
            list.remove(list.get_first()->get_next()->get_data());
    }
    std::cout<<list.get_first()->get_data()->get_speed()<<std::endl;
}
*/

