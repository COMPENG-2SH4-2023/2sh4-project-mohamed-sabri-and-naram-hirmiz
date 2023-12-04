#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    exitFlag = false;
    loseFlag = false;
    score = 0;
    input = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    exitFlag = false;
    loseFlag = false;
    input =0;
    boardSizeX = boardX; 
    boardSizeY = boardY;
    snakeBody = new objPosArrayList();
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    delete snakeBody;
//     Perform cleanup if needed
}

objPosArrayList* GameMechs::getSnakeBody()
{
    return snakeBody;
}


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
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
int GameMechs::getScore()
{
    return score;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}
void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}
void GameMechs::incrementScore()
{
    
    score+=1;
}