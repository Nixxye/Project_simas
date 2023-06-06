#include "../observers/RankingObserver.h"
#include "../menus/Ranking.h"

namespace Observers
{
    RankingObserver::RankingObserver():
    Observer()
    {
        pEM->add_observer(this);


    }
    RankingObserver::~RankingObserver()
    {
        pRanking = nullptr;
    }
    void RankingObserver::notify(sf::Keyboard::Key key_code)
    {
        //std::cout<<"EITAAAAAAAAAAA Ranking"<<std::endl;
        if (!pRanking)
        {
            //std::cout<<"EITAAAAAAAAAAA"<<std::endl;
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