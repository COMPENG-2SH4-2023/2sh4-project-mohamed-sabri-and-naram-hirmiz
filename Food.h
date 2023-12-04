#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <ctime>
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

class Player;  // Forward declaration

class Food
{
private:
    objPos foodPos;
    GameMechs* gameMechsPtr;

public:
    Food();
    ~Food();
    void generateFood(GameMechs* gameMechs, objPosArrayList* playerPosList);
    void getFoodPos(objPos& returnPos);
    void setGameMechs(GameMechs* gameMechs);
};

#endif
