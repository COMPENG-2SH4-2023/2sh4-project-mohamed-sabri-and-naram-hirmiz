#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <ctime>
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"
#include "MacUILib.h"

class Food
{
    private:
        objPos foodPos;

    public:
        Food();
        ~Food();
        void generateFood(objPosArrayList* blockOff);
        void getFoodPos(objPos& returnPos);
        void setGameMechs(GameMechs* gameMechs);
};

#endif
