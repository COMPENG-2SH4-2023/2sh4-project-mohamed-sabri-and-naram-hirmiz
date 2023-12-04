#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "Food.h"
#include "objPosArrayList.h"

class Food;
class Player
{
    public:
        enum Dir { UP, DOWN, LEFT, RIGHT, STOP };  // This is the direction state

        Player(GameMechs* thisGMRef, Food* foodPtr);
        ~Player();

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();

    private:
        objPosArrayList* playerPosList;   // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* FoodPtr;
};

#endif
