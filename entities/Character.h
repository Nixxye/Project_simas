#pragma once
#include "Entity.h"

namespace entes

{
    namespace character
    {
    class Character : public Entity
    {
        protected:

            int lives;
            bool alive;

        public:
            Character();
            ~Character();
    };
    }
}