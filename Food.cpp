#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"


Food::Food()
{
    foodPos.setObjPos(-1,-1,'o');
}

Food::~Food()
{

}



void Food::generateFood(GameMechs* gameMechsPtr, objPos blockOff)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    
    do {
        foodPos.x = rand() % ((gameMechsPtr->getBoardSizeX()) - 2) + 1;
        foodPos.y = rand() % ((gameMechsPtr->getBoardSizeY()) - 2) + 1;
        foodPos.symbol = 'o';
    } while (foodPos.isPosEqual(&blockOff));
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}