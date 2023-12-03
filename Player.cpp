#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{ 
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2, '$');
    // more actions to be included
    
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{ 
    // PPA3 input processing logic   
    switch (mainGameMechsRef->getInput()){
        case 'w':
            if(myDir != UP || myDir != DOWN){
                myDir = UP;
                break;
            }
        case 'a':
            if(myDir != LEFT || myDir != RIGHT){
                myDir = LEFT;
                break;
            }
        case 's':
            if(myDir != UP || myDir != DOWN){
                myDir = DOWN;
                break;
            }
        case 'd':
            if(myDir != LEFT || myDir != RIGHT){
                myDir = RIGHT;
                break;
        default:
            break;
            }   
    } 
        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(myDir){

        case LEFT:
            playerPos.x--;
            break;

        case RIGHT:
            playerPos.x++;
            if (playerPos.x >= mainGameMechsRef->getBoardSizeX() - 1) {
                playerPos.x = 1;      
            }
            break;

        case DOWN:
            playerPos.y++;
            break;

        case UP:
            playerPos.y--;
            break;

        default:
            break;
        }
        if (playerPos.x < 1){
        playerPos.x = mainGameMechsRef->getBoardSizeX() - 2;
    }
    else if (playerPos.x >= mainGameMechsRef->getBoardSizeX() - 1){
        playerPos.x = 1;
    }

    if (playerPos.y >= mainGameMechsRef->getBoardSizeY() - 1) {
        playerPos.y = 1;
    }
    else if (playerPos.y < 1){
        playerPos.y = mainGameMechsRef->getBoardSizeY() - 2;
    }
}


