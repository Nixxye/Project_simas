#pragma once

#include <iostream>
using namespace std;

template <typename TN>
class List
{
public:
    template <typename TE>
    class Element
    {
    private:
        Element<TE>* next;
        Element<TE>* prev;
        TE* data;
    public:
        Element(TE* elem = NULL):next(NULL), prev(NULL), data(elem){};
        ~Element(){next = NULL; prev = NULL; data = NULL;};
        const Element<TE>*get_next(Element<TE>* current) const {return next;}
        const Element<TE>*get_prev(Element<TE>* current) const {return prev;}
        void set_next(Element<TE>* n){next = n;}
        void set_prev(Element<TE>* p){prev = p;}
        void set_data(TE* d){data = d;}
    };

    List();
    ~List();

    void add(TN* elem);
    void remove(TN* elem);

    bool empty();
private:
    Element<TN>* first;
};