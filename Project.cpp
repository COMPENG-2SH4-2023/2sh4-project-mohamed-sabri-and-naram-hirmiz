#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"  


using namespace std;

#define DELAY_CONST 100000


// all global variabes to be removed
GameMechs* gameMechsPtr;

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

    //exitflag = false
}

void GetInput(void)
{
    char input;
    
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
        gameMechsPtr->setInput(input); 
    }
}

void RunLogic(void)
{
    char input = gameMechsPtr->getInput();
/*
    if (input != 0) // if not null character
    {
        switch (input)
        {
            case '/': // exit
                gameMechsPtr->setExitTrue();
                break; 

            case 'w':
                if (movement != DOWN)
                {
                    movement = UP;
                }
                break;

            case 's':
                if (movement != UP)
                {
                    movement = DOWN;
                }
                break;

            case 'a':
                if (movement != right)
                {
                    movement = left;
                }
                break;

            case 'd':
                if (movement != left)
                {
                    movement = right;
                }
                break;

            default:
                break;

            case '=':
                if (speed < 5)
                {
                    speed++;
                }
                break;

            case '-':
                if (speed > 0)
                {
                    speed--;
                }                
                break;
        }

        gameMechsPtr->clearInput();
    }
*/
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    objPos map(0, 0, '#');

    // Draw the top and bottom borders
   for(int i =0; i<gameMechsPtr->getBoardSizeY(); i++){
    for(int j = 0; j<gameMechsPtr->getBoardSizeX(); j++){
        if(i == 0){
            map.setObjPos(i, 0, '#');
        }
        else if(i ==  gameMechsPtr->getBoardSizeY() -1){
            map.setObjPos(i,  gameMechsPtr->getBoardSizeX()-1, '#');
        }
        else if(j == 0){
            map.setObjPos(0, j, '#');
        }
        else if(j ==  gameMechsPtr->getBoardSizeX() -1){
            map.setObjPos( gameMechsPtr->getBoardSizeY()-1,j,'#');
        }else{
            map.setObjPos(i,j,' ');
        }
        map.getObjPos(map);
        MacUILib_printf("%c", map.getSymbol());
    }
    MacUILib_printf("\n");
   }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    delete gameMechsPtr;
    MacUILib_uninit();
}
