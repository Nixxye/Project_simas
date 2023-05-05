#pragma once

#include <iostream>

using namespace std;

template <class TYPE>
class List
{
public:
    template <class TE>
    class Element
    {
    private:
        TE* data;
        Element<TE>* next;
        Element<TE>* prev;
    public:
        Element():
        data(NULL), next(NULL), prev(NULL)
        {

        }
        ~Element()
        {
            delete data;            //delete aux->get_data();
            data = NULL;
            next = NULL;
            prev = NULL;
        }

        void set_next(Element<TE>* n) {this->next = n;}
        void set_prev(Element<TE>* p) {this->prev = p;}
        void set_data(TE* d) {this->data = d;}

        TE* get_data() {return data;}
        Element<TE>* get_next() {return next;}
        Element<TE>* get_prev() {return prev;}
    };

private:
    Element<TYPE>* first;
    Element<TYPE>* last;
    int size;

public:
    List();
    ~List();

    void clear();
    void push(TYPE* data);

    Element<TYPE>* get_first() {return first;}
    Element<TYPE>* get_last() {return last;}
    int get_size() {return size;}
    void remove(TYPE* dt);
    
    //TYPE* operator[](int x);    
};

template <class TYPE>
List<TYPE>::List():
first(NULL), last(NULL), size(0)
{

}

template <class TYPE>
List<TYPE>::~List()
{
    clear();    
}

 
template <class TYPE>
void List<TYPE>::clear()
{
    Element<TYPE>* aux = NULL;
    while (first)
    {
        aux = first;
        first = first->get_next();
        delete aux;
    }
    first = NULL;
    last = NULL;
    size = 0;
}

template <class TYPE>
void List<TYPE>::push(TYPE *dt)
{
    if (dt)
    {
        Element<TYPE>* new_elem = new Element<TYPE>();
        new_elem->set_data(dt);
        if (!first)
        {
            first = new_elem;
            last = new_elem;
        }
        else
        {
            last->set_next(new_elem);
            new_elem->set_prev(last);
            last = new_elem;
        }
        size++;
    }
    else
    {
        cout<<"Burro";
        return;
    }
}
template <class TYPE>
void List<TYPE>::remove(TYPE* dt)
{
    Element<TYPE>* aux = first;
    while (aux)
    {
        if (aux->get_data() == dt)
        {
            if (aux == first)
            {
                first = first->get_next();
            }
            else if (aux == last)
            {
                last = last->get_prev();
                last->set_next(NULL);
            }
            else
            {
                aux->get_prev()->set_next(aux->get_next());
                aux->get_next()->set_prev(aux->get_prev());
            }
            delete aux;
            size--;
            return;
        }
        aux = aux->get_next();
    }
}