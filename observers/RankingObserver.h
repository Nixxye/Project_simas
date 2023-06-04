#pragma once 

#include "../observers/Observer.h"


namespace Menus
{
    class Ranking;
}

namespace Observers
{
    class RankingObserver: public Observer
    {
    private:
        Menus::Ranking* pRanking;
    public:
        RankingObserver();
        ~RankingObserver();
        void notify(sf::Keyboard::Key key_code);
        void set_menu(Menus::Ranking *p) { printf ("Observer\n");pRanking = p; }
    };
}