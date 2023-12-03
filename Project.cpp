#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"  
#include "Player.h"  


using namespace std;

#define DELAY_CONST 100000


// all global variabes to be removed
GameMechs* gameMechsPtr;
Player* PlayerPtr;
// const int width = 30;
// const int height = 15;
// bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(!gameMechsPtr->getExitFlagStatus())  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    gameMechsPtr = new GameMechs(30, 15);
    PlayerPtr = new Player(gameMechsPtr);

    

    objPos playerPos;
    PlayerPtr->getPlayerPos(playerPos);
    gameMechsPtr->generateFood(playerPos);

    //exitflag = false
}

void GetInput(void)
{
    gameMechsPtr->getInput();
}

void RunLogic(void)
{
    PlayerPtr->updatePlayerDir(); //else continue the game
    PlayerPtr->movePlayer();
    //DrawScreen();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    objPos map;
    objPos foodPos;

    // Draw the top and bottom borders
    for (int i = 0; i < gameMechsPtr->getBoardSizeY(); i++) {
        for (int j = 0; j < gameMechsPtr->getBoardSizeX(); j++) {
            if (i == 0 || i == gameMechsPtr->getBoardSizeY() - 1 || j == 0 || j == gameMechsPtr->getBoardSizeX() - 1) {
                map.setObjPos(i, j, '#');
            } else {
                objPos playerPos;
                

                PlayerPtr->getPlayerPos(playerPos);
                gameMechsPtr->getFoodPos(foodPos);

                if (i == playerPos.y && j == playerPos.x) {
                    map.setObjPos(i, j, '$');
                } else if (i == foodPos.y && j == foodPos.x) {
                    map.setObjPos(i, j, 'o');
                } else {
                    map.setObjPos(i, j, ' ');
                }
            }

            MacUILib_printf("%c", map.getSymbol());
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("%c", gameMechsPtr->getFoodPos(foodPos));
}
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    delete gameMechsPtr;
    delete PlayerPtr;
    MacUILib_uninit();
}
