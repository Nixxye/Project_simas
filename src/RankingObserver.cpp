#include "../observers/RankingObserver.h"
#include "../menus/Ranking.h"

namespace Observers
{
    RankingObserver::RankingObserver():
    Observer()
    {
        pEM->attach(this);


    }
    RankingObserver::~RankingObserver()
    {
        pRanking = nullptr;
    }
    void RankingObserver::update(sf::Keyboard::Key key_code)
    {
        if (!pRanking)
        {
            return;
        }
        if (pSM->get_CurrentStateID() != 4)
            return;
        if (key_code == sf::Keyboard::Up)
            pRanking->move_up();
        if (key_code == sf::Keyboard::Down)
            pRanking->move_down();
        if (key_code == sf::Keyboard::Enter)
            pRanking->select();

    }
}