#pragma once


class Menu
{
    private:
        bool active;
    public:
        Menu();
        ~Menu();
        bool is_active () const; 

};