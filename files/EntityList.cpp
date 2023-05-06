#include "../headers/EntityList.h"
#include "../headers/Enemy.h"
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
    auto aux = list.get_first();
    while(aux)
    {
        aux->get_data()->move();
        aux = aux->get_next();        
    }
}

void EntityList::draw(sf::RenderWindow* window)
{
    auto aux = list.get_first();
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

void EntityList::stress_test()
{
    int n = list.get_size();
    int x = rand()%1000;
    int y = rand()%1000;
    
    if (n < 10 && list.get_first()->get_data()->get_speed() > 0)
    {
        Enemy* aux = new Enemy();
        aux->set_position(sf::Vector2f(x, y));
        add(static_cast<Entity*>(aux));
    }
    if (n > 5)
    {
        if ((bool) rand() % 2)
            list.remove(list.get_last()->get_data());
    }
    std::cout<<list.get_first()->get_data()->get_speed()<<std::endl;
}

