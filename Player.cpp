#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{ /*
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.setObjPos(width/2,height/2, '$');
    // more actions to be included
    */
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
{ /*
    // PPA3 input processing logic   
    switch (input){
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
    */    
}

void Player::movePlayer()
{/*
    // PPA3 Finite State Machine logic
    switch(myDir){

        case LEFT:
            oldx = playerPos.x;
            playerPos.x--;
            break;

        case RIGHT:
            oldx = playerPos.x;
            playerPos.x++;
            if (playerPos.x >= width - 1) {
                playerPos.x = 1;      
            }
            break;

        case DOWN:
            oldy = playerPos.y;
            playerPos.y++;
            break;

        case UP:
            oldy = playerPos.y;
            playerPos.y--;
            break;

        default:
            break;
        }
    */
}

