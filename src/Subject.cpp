#include "../managers/Subject.h"
#include "../observers/Observer.h"


namespace Managers 
{

    Subject :: Subject ()
    {
        list_observers.clear();
    }
   Subject:: ~Subject ()
    {
        for (it = list_observers.begin(); it != list_observers.end(); it++)
        {
            delete(*it);
        }
        list_observers.clear();

    }
    void  Subject :: attach(Observers::Observer* pObserver)
    {
        list_observers.push_back(pObserver);
    }

    void Subject :: detach (Observers::Observer* pObserver)
    {
        list_observers.remove(pObserver);
    } 
    void Subject ::notify(sf::Keyboard::Key key_code)
    {
        for (it = list_observers.begin(); it != list_observers.end(); it++)
        {
            (*it)->update((key_code));
        } 
    }
}