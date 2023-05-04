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
    Element<TYPE>* begin() { return first; }

    void add(TYPE* elem);
    bool empty(){return first? false: true;}
    const int get_size () const {return size;};
    TYPE& operator [] (const int idx);
private:
    Element<TYPE> *first;
    int size;
};

template <class TYPE>
List<TYPE>::List():
first(NULL), 
size(0)
{

}

template <class TYPE>
List<TYPE>::~List()
{
    Element<TYPE>* aux = first;
    Element<TYPE>* aux_data = NULL;
    while(!empty())
    {
        if (first)
        {
            aux_data = first->get_data();
            delete aux_data;
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
    size++;
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

template <class TYPE>
TYPE& List<TYPE>::operator[](const int idx) {
    Element<TYPE> * pAux = first;
    
    for (int i = 0 ; i < idx && i < size; i++)
    {
        pAux = first->get_next();
    }

    return *(pAux->data);

}




