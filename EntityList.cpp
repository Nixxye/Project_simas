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
        ElementList* aux = NULL;
    }
}

void EntityList::draw()
{
}

void EntityList::add(Entity *ent)
{
}
