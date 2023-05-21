#include "GraphicsManager.h"
#include "StateManager.h"
#include "../entities/Player1.h"
#include "../entities/Player.h"
#include "../entities/Player2.h"
#include "../menu/Menu.h"

//incluído para testes:
#include <iostream>
using namespace std;

using namespace characters;

namespace Managers
{
    class EventsManager
    {
        private:
            GraphicsManager* pGM;
            StateManager* pSM;
            Entity* pPlayer1;
            Entity* pPlayer2;
            Menu* pMainMenu;
            Menu* pPauseMenu;

        public:
            EventsManager();
            ~EventsManager();
            void run ();
            void move_players(sf::Event key_code);
            void notify_menu(sf :: Keyboard :: Key key_code, Menu* menu);

            //Funções criadas para fazer o programa rodar;
            void set_player (Entity* player)
            { 
                if (!pPlayer1)
                    pPlayer1 = player;
                else if (!pPlayer2)
                    pPlayer2 = player;
                else
                    cout<<"Seu burro, já tem 2 jogadores!"<<endl;
            }
        
            const int n_players ()
            {
                if (pPlayer2)
                    return 2;
                if (pPlayer1)
                    return 1;
                return 0;
            }
    };
}