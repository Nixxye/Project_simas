#include "GraphicsManager.h"
#include "../entities/Player.h"

namespace Managers
{
    class EventsManager
    {
        private:
            GraphicsManager* pGM;
            Player* pPlayer;

        public:
            EventsManager();
            ~EventsManager();
            void run ();



    };
}