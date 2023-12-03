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

    objPosArrayList* snakeBody = gameMechsPtr->getSnakeBody();

    bool spawnOnSnake;

    do {
        spawnOnSnake = false;  // Initialize to false at the beginning of each iteration

        // Generate a random position for the food
        foodPos.x = rand() % (gameMechsPtr->getBoardSizeX() - 2) + 1;
        foodPos.y = rand() % (gameMechsPtr->getBoardSizeY() - 2) + 1;
        foodPos.symbol = 'o';

        // Check if the food position coincides with blockOff or any position in the snake's body
        if (foodPos.isPosEqual(&blockOff)) {
            spawnOnSnake = true;
            continue;  // Skip the rest of the checks and generate a new random position
        }

        for (int i = 0; i < snakeBody->getSize(); ++i) {
            objPos tempBody;
            snakeBody->getElement(tempBody, i);
            if (foodPos.isPosEqual(&tempBody)) {
                spawnOnSnake = true;
                break;
            }
        }
    } while (spawnOnSnake);

    // At this point, the loop ensures that foodPos is a valid position
}
void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}