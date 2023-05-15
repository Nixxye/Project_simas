#include "GraphicsManager.h"
#include "../entities/Player.h"
#include "../main/Menu.h"


namespace Managers
{
    class EventsManager
    {
        private:
            GraphicsManager* pGM;
            Player* pPlayer1;
            Player* pPlayer2;
            Menu* pMenu;

        public:
            EventsManager();
            ~EventsManager();
            void run ();
    };
}