#pragma once

#include <iostream>

using namespace std;

namespace list
{
    template <class TYPE>
    class List {
    public:
        template <class TE>
        class Element {
        private:
            TE* data;
            Element<TE>* next;
        public:
            Element() : data(NULL), next(NULL) {}
            ~Element() {}

            void set_next(Element<TE>* n) {this->next = n;}
            void set_data(TE* d) {this->data = d;}

            TE* get_data() {return data;}
            Element<TE>* get_next() {return next;}
        };

    private:
        Element<TYPE>* first;
        Element<TYPE>* last;
        int size;

    public:
        List() : first(NULL), last(NULL), size(0) {}

        ~List() {
            clear();
        }

        Element<TYPE>* get_first(){return first;}
        Element<TYPE>* get_last(){return last;}
        void clear() {
            Element<TYPE>* aux = NULL;
            while (first) {
                aux = first;
                first = first->get_next();
                delete aux->get_data();
                delete aux;
            }
            first = NULL;
            last = NULL;
            size = 0;
        }

        void push(TYPE* data) {
            if (data) {
                Element<TYPE>* new_elem = new Element<TYPE>();
                new_elem->set_data(data);
                if (!first) {
                    first = new_elem;
                    last = new_elem;
                } else {
                    last->set_next(new_elem);
                    last = new_elem;
                }
                size++;
            }
        }

        void print() {
            Element<TYPE>* aux = first;
            while (aux) {
                cout << *(aux->get_data()) << " ";
                aux = aux->get_next();
            }
            cout << endl;
        }

        int get_size() {return size;}

        void remove(TYPE* dt)
        {
            Element<TYPE>* aux = first;
            Element<TYPE>* prev = NULL;
            prev = first;
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
                        last = prev;
                        last->set_next(NULL);
                    }
                    else
                    {
                        prev->set_next(aux->get_next());
                    }
                    delete aux;
                    size--;
                    return;
                }
                prev = aux;
                aux = aux->get_next();
            }
        }

    };

}