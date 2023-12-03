#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    exitFlag = false;
    foodPos.setObjPos(-1,-1,'o');
}

GameMechs::GameMechs(int boardX, int boardY)
{
    exitFlag = false; 
    boardSizeX = boardX; 
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
//     Perform cleanup if needed
}


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {
        char input = MacUILib_getChar();
        setInput(input);

        if(input == '/') 
        {
            setExitTrue();
        }

    }

        return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::generateFood(objPos blockoff)
{
    srand((unsigned int)time( NULL ));
    do
    {
        foodPos.x = rand() % ((boardSizeX) - 2) + 1;
        foodPos.y = rand() % ((boardSizeY) - 2) + 1;
        foodPos.symbol = 'o';
    } while (foodPos.isPosEqual(&blockoff) == false && foodPos.x != 0 && foodPos.y !=0 && foodPos.x != boardSizeX && foodPos.y!= boardSizeY);
}
void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}
