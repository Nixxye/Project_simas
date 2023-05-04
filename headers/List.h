#pragma once

#include <iostream>

using namespace std;


template <class TYPE>
class List
{
public:
    List();
    ~List();

    template <typename TE>
    class Element
    {
    private:
        Element<TE> *next;
        Element<TE> *prev;
        TE *data;

    public:
        Element(TE *elem = NULL) : next(NULL), prev(NULL), data(elem) {}
        ~Element()
        {
            next = NULL;
            prev = NULL;
            data = NULL;
        }
        Element<TE> *get_next() const { return next; }
        Element<TE> *get_prev() const { return prev; }
        TE *get_data() const { return data; }
        void set_next(Element<TE> *n) { next = n; }
        void set_prev(Element<TE> *p) { prev = p; }
        void set_data(TE *d) { data = d; }
    };

    void add(TYPE* elem);
    bool empty(){return first? false: true;}
    Element<TYPE>* begin() { return first; }
private:
    Element<TYPE> *first;
};

template <class TYPE>
List<TYPE>::List():
first(NULL)
{

}

template <class TYPE>
List<TYPE>::~List()
{
    Element<TYPE>* aux = first;
    while(!empty())
    {
        if (first)
        {
            aux = first->get_next();
            delete first;
            first = aux;
        }
    }
    first = NULL;
}
template <class TYPE>
void List<TYPE>::add(TYPE* elem)
{
    Element<TYPE>* aux = new Element<TYPE>(elem);
    aux->set_next(NULL);
    if (empty())
    {
        first = aux;
        aux->set_prev(NULL);
        return;
    }
    else
    {
        Element<TYPE>* it = first;
        while(it->get_next())
        {
            it = it->next;
        }
        it->set_next(aux);
        aux->set_prev(it);
        
    }
}