#pragma once

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

            TE* operator*()
            {
                return current->get_data();
            }
        };
    private:
        Element<TYPE>* pfirst;
        Element<TYPE>* plast;
    public:
        Iterator<TYPE> get_first(){return Iterator<TYPE>(pfirst);}
        Element<TYPE>* get_last(){return plast;}
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
        int get_size()
        {
            Element<TYPE>* aux = pfirst;
            int n = 0;
            while (aux)
            {
                n++;
                aux = aux->get_next();
            }
            return n;
        }
        void push(TYPE* elem)
        {
            if (!elem)
                return;
            Element<TYPE>* aux = new Element<TYPE>();
            aux->set_data(elem);
            aux->set_next(pfirst);
            pfirst = aux;
        }
    };
}