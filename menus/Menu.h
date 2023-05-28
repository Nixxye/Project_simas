#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../entities/GameObject.h"
#include "../observers/MenuObserver.h"

namespace Menus
{
    class Menu: public Entes::GameObject;
    {
        private:
            const int MAX_BUTTONS;
            sf::Text buttons[MAX_BUTTONS];
            int selected_index;
            Observers::MenuObserver* pMenuObserver;
        public:
            Menu(int n_buttons = 0);
            ~Menu();
            void draw();
            void move_up();
            void move_down();
            void select() = 0;
            void run();
    };    
}
