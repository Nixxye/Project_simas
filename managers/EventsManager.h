#include "GraphicsManager.h"
#include "StateManager.h"
#include "../entities/Player1.h"
#include "../entities/Player.h"
#include "../entities/Player2.h"
#include "../menu/Menu.h"


namespace Managers
{
    class EventsManager
    {
        private:
            GraphicsManager* pGM;
            StateManager* pSM;
            Player* pPlayer1;
            Player* pPlayer2;
            Menu* pMainMenu;
            Menu* pPauseMenu;

        public:
            EventsManager();
            ~EventsManager();
            void run ();
            void move_players(sf :: Keyboard :: Key key_code);
            void notify_menu(sf :: Keyboard :: Key key_code, Menu* menu);
    };
}