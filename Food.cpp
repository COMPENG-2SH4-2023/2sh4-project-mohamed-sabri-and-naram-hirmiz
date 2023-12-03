#include "Food.h"
#include "MacUILib.h"

Food::Food()
{
    foodPos.setObjPos(-1,-1,'o');
}

Food::~Food()
{

}


void Food::generateFood(objPos blockOff)
{
    GameMechs globalGameMechs;
    do{
        foodPos.x = rand() % ((globalGameMechs.getBoardSizeX())-2)+1;
        foodPos.y = rand() % ((globalGameMechs.getBoardSizeY())-2)+1;
        foodPos.symbol = 'o';
    }while(foodPos.isPosEqual(&blockOff) == false);
    
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}