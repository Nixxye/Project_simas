#pragma once

#include <iostream>

namespace list
{
    template<class TYPE>
    class List
    {
    public:
        List():
        pfirst(NULL), plast(NULL)
        {}
        ~List()
        {
            clear();
            pfirst = NULL;
            plast = NULL;
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
    private:
        Element<TYPE>* pfirst;
        Element<TYPE>* plast;
    public:
        Element<TYPE>*get_first(){return pfirst;}
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
        }
        void push(TYPE* elem)
        {
            std::cout<<elem<<std::endl;
            if (!elem)
                return;
            Element<TYPE>* aux = new Element<TYPE>();
            aux->set_data(elem);
            aux->set_next(pfirst);
            pfirst = aux;
        }
    };
}