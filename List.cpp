#include "List.h"

template <typename TN>
List<TN>::List():
first(NULL)
{

}
template <typename TN>
List<TN>::~List()
{
    Element<TN>* aux = first;
    while(!empty())
    {
        if (first)
        {
            aux = first->get_next();
            delete first;
            first = aux;
        }
    }
}
template <typename TN>
void List<TN>::add(TN* elem)
{
    Element<TN>* aux = new Element<TN>(elem);
    aux->set_next(NULL);
    if (empty())
    {
        first = aux;
        aux->set_prev(NULL);
        return;
    }
    else
    {
        Element<TN>* it = first;
        while(it->next)
        {
            it = it->next;
        }
        it->set_next(aux);
        aux->set_prev(it);
        
    }
}
template <typename TN>
void List<TN>::remove(TN* elem)
{
    //...
}
template <typename TN>
bool List<TN>::empty()
{
    return first? false: true;
}