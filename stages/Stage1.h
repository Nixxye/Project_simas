#pragma once 

#include "../stages/Stage1"

namespace Stages
{
    class Stage1: public Stage1
    {
    private:
        
    public:
        Stage1();
        ~Stage1();
        void run() = 0;
        void create_enemies();
        void create_obstacles();
    };
}