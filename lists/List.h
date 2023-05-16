#pragma once

#include <iostream>
using namespace std;

namespace list
{
    template<class TYPE>
    class List
    {
    public:
        List():
        pfirst(NULL),
        size(0)
        //, plast(NULL)
        {}
        ~List()
        {
            clear();
            pfirst = NULL;
            //plast = NULL;
        }
        template <class TE>
        class Element
        {
        private:
            TE* data;
            Element<TE>* pnext;
        public:
            Element():data(NULL), pnext(NULL)
            {}
            ~Element()
            {
                //Colocar isso se for usar o delete
                /*
                if (data)
                {
                    //delete &data;
                }
                */
                data = NULL;
                pnext = NULL;
            }
            TE* get_data() {return data;}
            Element<TE>* get_next() {return pnext;}

            void set_data(TE* dt){data = dt;}
            void set_next(Element<TE>* next){pnext = next;}
        };
        template <class TE>
        class Iterator
        {
        private:
            Element<TE>* current;
        public:
            Iterator(Element<TE>* c = nullptr):
            current(c){}
            ~Iterator(){}

            Iterator& operator++()
            {
                current = current->next;
                return *this;
            }
            Iterator& operator++(int)
            {
                current = current->get_next();
                return *this;  
            }
            bool operator==(const Element<TE>* other) const
            {
                return current == other;
            }

            bool operator!=(const Element<TE>* other) const
            {
                return !(current == other);
            }
            void operator=(const Element<TE>* other)
            {
                current = other;
            }
            TE* operator*()
            {
                return current->get_data();
            }
            const Element<TE>* get_current() const {return current;}
        };
    private:
        Element<TYPE>* pfirst;
        int size;
    public:
        Iterator<TYPE> get_first(){return Iterator<TYPE>(pfirst);}
        void clear()
        {
            Element<TYPE>* aux = NULL;
            while(pfirst)
            {
                aux = pfirst;
                pfirst = pfirst->get_next();
                if (aux)
                    delete aux;
            }
            size = 0;
        }
        int get_size()
        {
            return size;
        }
        void push(TYPE* elem)
        {
            if (!elem)
                return;
            Element<TYPE>* aux = new Element<TYPE>();
            aux->set_data(elem);
            aux->set_next(pfirst);
            pfirst = aux;
            size++;
        }
    };
}