#include "GameObject.h"

int GameObject::speed(0);
int GameObject::count(0);
sf::Vector2f GameObject::player_position(200.f, 200.f);

GameObject::GameObject():
id(count++),
body(sf::Vector2f(50.f, 50.f)),
position(200.f, 200.f),
lives(1),
vel(0.f, 0.f),
grounded(false)
{
    
    body.setFillColor(sf::Color::White);
}

GameObject::~GameObject()
{
}

void GameObject::draw(sf::RenderWindow *wd)
{
    wd->draw(body);
}
