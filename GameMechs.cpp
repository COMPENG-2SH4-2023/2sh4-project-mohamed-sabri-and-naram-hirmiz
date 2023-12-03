#include "GameMechs.h"

GameMechs::GameMechs()
{
    exitFlag = false;
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

bool GameMechs::ExitButtonPressed()
{
    return getInput() == '/';
}

char GameMechs::getInput()
{
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


