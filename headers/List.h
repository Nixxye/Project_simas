#pragma once

#include <iostream>

using namespace std;

template <class TYPE>
class List //provavelmente ta tudo errado
{
public:
    template <class TE>
    class Element
    {
    private:
        TE* data;
        Element<TE>* next;
    public:   
        Element():data(NULL), next(NULL){}
        void set_next(Element<TE>* n) {next = n;}
        void set_data (TE* d) {data = d;}
        TE* get_data() {return data;}
        Element<TE>* get_next() {return next;}
        ~Element() {set_data(NULL);}

    };

private:
    Element<TYPE>* first;
    Element<TYPE>* last;
    int size;

public:
    List():first(NULL),last(NULL),size (0) {}
    Element<TYPE>* get_first() {return first;}
    Element<TYPE>* get_last() {return last;}
    int get_size() {return size;}
    void remove(TYPE* dt)
    {
        Element<TYPE>* pAux = first;
        Element<TYPE>* prev = NULL;
        while (pAux != last) 
        {
            if (pAux->get_data() == dt) 
            {
                if (pAux == first) {
                    first = pAux->get_next();
                } 
                else if (pAux == last) {
                    last = prev;
                    prev->set_next(NULL);
                } 
                else
                {
                    prev->set_next(pAux->get_next());
                }
                pAux->~Element();
                delete (pAux);
                size--;

            }

            prev = pAux;
            pAux = pAux->get_next();
        }
    }
    void remove_front()
    {
        Element<TYPE>* pAux = first;
        pAux = first->get_next();
        first->~Element();
        delete first;
        first = pAux;    
    }
    void clear()
    {
        while (first != last)
        {
            remove_front();
        }
    }
    void push(TYPE* dt)
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
                last = new_elem;
            }
            new_elem->set_next(NULL);
            size++;
        }
    }
    ~List()
    {
        //printf("%d", size);
        while(first!=last)
        {
            remove_front();
        }
    }
};

