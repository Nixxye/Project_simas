#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "../entities/Ent.h"
#include "../managers/EventsManager.h"
#include "../observers/MenuObserver.h"
#include "../menus/Button.h"
#include "../menus/Text.h"
#include "../states/State.h"

namespace Menus
{
    class Menu: public Ent, public States::State
    {
        protected:
            const int MAX_BUTTONS;
            std::vector<Button*> buttons;
            int selected_index;
           // Managers::EventsManager* pEventsManager;
            Text title;
        public:
            Menu(int n_buttons = 0, int id = -1, std:: string t = "0");
            ~Menu();
            virtual void draw();
            void move_up();
            void move_down();
            virtual void move_horizontally(int i = 0) = 0;
            virtual void select() = 0;
            void execute();
    };    
}
