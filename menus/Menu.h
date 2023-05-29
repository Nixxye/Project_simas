#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "../entities/GameObject.h"
#include "../managers/EventsManager.h"
#include "../observers/MenuObserver.h"
#include "../menus/Button.h"
#include "../states/State.h"

namespace Menus
{
    class Menu: public GameObject//, public States::State
    {
        protected:
            const int MAX_BUTTONS;
            std::vector<Button*> buttons;
            int selected_index;
            Observers::MenuObserver* pMenuObserver;
            Managers::EventsManager* pEventManager;
        public:
            Menu(int n_buttons = 0);
            ~Menu();
            void draw();
            void move_up();
            void move_down();
            virtual void select() = 0;
            void run();
    };    
}
