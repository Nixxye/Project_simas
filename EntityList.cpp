#include "EntityList.h"

EntityList::EntityList():
head(NULL),
tail(NULL)
{
    
}

EntityList::~EntityList()
{
    if(head)
    {
        ElementList* aux = NULL;
        while(head)
        {
            aux = head;
            head = head->next;
            delete aux->data;
        }
    }
}

void EntityList::move()
{
    if(head)
    {
        ElementList* aux = head;
        while(aux)
        {
            aux->data->move();
            aux = aux->next;
        }
    }
}

void EntityList::draw(sf::RenderWindow* window)
{
    if(head)
    {
        ElementList* aux = head;
        while(aux)
        {
            aux->data->draw(window);
            aux = aux->next;
        }
    }
}

void EntityList::add(Entity *ent)
{
    //TERMINAR AMANHÃ
    if (!head)
    {
        head = ent;
        tail = ent;
        ent->next = NULL;
        ent->prev = NULL;
    }
    else 
    {
        tail->next = ent;

        ent->next = NULL;
        ent->prev = tail;

        tail = ent;
    }
}
