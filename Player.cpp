#include "Player.h"

Player::Player(GameMechs* thisGMRef, Food* foodPtr)
{ 
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2, '$');
    // more actions to be included
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
    FoodPtr = foodPtr;
    
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
    delete FoodPtr;
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{ 
    // PPA3 input processing logic   
    switch (mainGameMechsRef->getInput()){
                case 'w':
            if (myDir != DOWN)
            {
                myDir = UP;
            }
            break;

        case 's':
            if (myDir != UP)
            {
                myDir = DOWN;
            }
            break;

        case 'a':
            if (myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;

        case 'd':
            if (myDir != LEFT )
            {
                myDir = RIGHT;
            }
            break;

        default:
            break;  
    } 
        
}

void Player::movePlayer()
{
    objPos Head;
    playerPosList->getHeadElement(Head);
    // PPA3 Finite State Machine logic
    switch(myDir){

        case LEFT:
            Head.x--;
            break;

        case RIGHT:
            Head.x++;
            break;

        case DOWN:
            Head.y++;
            break;

        case UP:
            Head.y--;
            break;

        default:
            break;
        }
        if (Head.x < 1){
        Head.x = mainGameMechsRef->getBoardSizeX() - 2;
        }
        else if (Head.x >= mainGameMechsRef->getBoardSizeX()-1){
            Head.x = 1;
        }

        if (Head.y >= mainGameMechsRef->getBoardSizeY()-1) {
            Head.y = 1;
        }
        else if (Head.y < 1){
            Head.y = mainGameMechsRef->getBoardSizeY() - 2;
        
        }

    
    objPos FoodPos;
    FoodPtr->getFoodPos(FoodPos);
    if (Head.isPosEqual(&FoodPos)) {
        playerPosList->insertHead(Head);
        FoodPtr->generateFood(mainGameMechsRef, Head);
    }
    else{
    playerPosList->insertHead(Head);
    playerPosList-> removeTail();
    }

}


