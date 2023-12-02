#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

#define DELAY_CONST 100000

const int width = 30;
const int height = 15;
bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    objPos map(0, 0, '#');

    // Draw the top and bottom borders
   for(int i =0; i<height; i++){
    for(int j = 0; j<width; j++){
        if(i == 0){
            map.setObjPos(i, 0, '#');
        }
        else if(i == height -1){
            map.setObjPos(i, width-1, '#');
        }
        else if(j == 0){
            map.setObjPos(0, j, '#');
        }
        else if(j == width -1){
            map.setObjPos(height-1,j,'#');
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
  
    MacUILib_uninit();
}
