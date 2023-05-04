#include "../headers/Entity.h"

int Entity::speed(0);
int Entity::count(0);
sf::Vector2f Entity::player_position(200.f, 200.f);

Entity::Entity():
id(count++),
body(sf::Vector2f(50.f, 50.f)),
position(200.f, 200.f),
lives(1),
vel(0.f, 0.f)
{
    
    body.setFillColor(sf::Color::White);
}

Entity::~Entity()
{
}

void Entity::draw(sf::RenderWindow *wd)
{
    wd->draw(body);
}
