#pragma once 

#include "../stages/Stage.h"

namespace Stages
{
    class Stage1: public Stage, public States :: State
    {
    public:
        Stage1();
        ~Stage1();
        void run();
        void create_enemies();
        void create_obstacles();
    };
}