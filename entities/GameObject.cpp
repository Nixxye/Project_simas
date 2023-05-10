#include "GameObject.h"

int GameObject::count(0);
int GameObject::speed(0);


GameObject::GameObject():
id(count++),
body(sf::Vector2f(50.f, 50.f)),
position(200.f, 200.f)


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
