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



void Food::generateFood(objPosArrayList* blockOff)
{
    objPos snakePos;
    srand(static_cast<unsigned int>(time(nullptr)));
        do{
            foodPos.x = rand() % ((gameMechsPtr->getBoardSizeX()) - 2) + 1;
            foodPos.y = rand() % ((gameMechsPtr->getBoardSizeY()) - 2) + 1;
            foodPos.symbol = 'o';

            for(int i=0; i< blockOff->getSize(); i++){
                blockOff->getElement(snakePos,i);

            }

        }while(!(snakePos.isPosEqual(&foodPos)) && foodPos.x != 0 && foodPos.y!=0 && foodPos.x !=gameMechsPtr->getBoardSizeX() && foodPos.y !=gameMechsPtr->getBoardSizeY())
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}