#include "../stages/Stage.h"
#include "Stage.h"

namespace Stages
{
    Stage::Stage():
    obstacles(),
    enemies(),
    players()
    {
    }

    Stages::Stage::~Stage()
    {
    }
    void Stage::create_enemies()
    {
    }
    void Stage::create_obstacles()
    {
    }
    void Stage::save()
    {
        ofstream file(filename);
        if (!filename)
            cout<<"ERROR"<<endl;
        
        file << enemies.get_size() << endl;

        for ()
    }
    void Stage::load()
    {
    }
}
