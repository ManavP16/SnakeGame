#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    foodRef = thisFoodRef;
    myDir = STOP;

    // more actions to be included
    playerPosList = new objPosArrayList;
    playerPosList -> insertHead(objPos(mainGameMechsRef -> getBoardSizeX()/2, mainGameMechsRef -> getBoardSizeY()/2, '*'));         //<-- Will change this
    // playerPosList -> insertHead(objPos(16, 7, '*'));
    // playerPosList -> insertHead(objPos(17, 7, '*'));
    // playerPosList -> insertHead(objPos(18, 7, '*'));
    // playerPosList -> insertHead(objPos(19, 7, '*'));

    head = playerPosList -> getHeadElement();
}


Player::~Player()
{
    delete playerPosList;
    playerPosList = nullptr;
    // delete any heap members here         <-- Will change this
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;
    // return the reference to the playerPos array list <-- Will change this
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input;
    input = mainGameMechsRef -> getInput();

    if(input != 0)
    {   
        switch(input)
        {
            case 'W':
            case 'w':
                if(myDir == RIGHT || myDir == LEFT || myDir == STOP)
                {
                    myDir = UP;
                }
                break;

            case 'A':
            case 'a':
                if(myDir == UP || myDir == DOWN || myDir == STOP)
                {
                    myDir = LEFT;
                }
                break;

            case 'S':
            case 's':
                if(myDir == RIGHT || myDir == LEFT || myDir == STOP)
                {
                    myDir = DOWN;
                }
                break;

            case 'D':
            case 'd':
                if(myDir == UP || myDir == DOWN || myDir == STOP)
                {
                    myDir = RIGHT;
                }
                break;
            
            case 27:
                mainGameMechsRef -> setExitTrue();
                break;
            
            case 'L':
            case 'l':
                mainGameMechsRef -> setLoseFlag();
                break;
            
            case 'P':
            case 'p':
                mainGameMechsRef -> incrementScore();
                break;

            default:
                break;
        }
    }     
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    int len, wid;
    len = mainGameMechsRef -> getBoardSizeY();
    wid = mainGameMechsRef -> getBoardSizeX();
    objPos foodTemp = foodRef->getFoodPos();

    //objPos head = playerPosList -> getHeadElement();
    // symbol = head.getSymbol();
    // xPos = head.getX(); //I3
    // yPos = head.getY(); //I3

    switch (myDir){
        case STOP:
            return;
        
        case UP:
            head.changeY(-1); //changed to be more modular
            break;
        
        case DOWN:
            head.changeY(1);
            break;

        case LEFT:
            head.changeX(-1);
            break;
        
        case RIGHT:
            head.changeX(1);
            break;
        
        default:
            break;

    }

    if (head.getY() < 1){
        //player.y = bHEIGHT - 2;
        //playerPosList -> setY(len - 2);
        head.setY(len-2);
    }
    else if (head.getY() > (len - 2))
    {
        //player.y = 1;
        //playerPosList -> setY(1);
        head.setY(1);
    }
    else if (head.getX() < 1){
        //player.x = bWIDTH - 2;
        //playerPosList -> setX(wid - 2);
        head.setX(wid-2);
    }
    else if (head.getX() > (wid - 2)){
        //player.x = 1;
        //playerPosList -> setX(1);
        head.setX(1);
    }
    playerPosList -> insertHead(head);
    // playerPosList -> removeTail();
    if (!checkFoodConsumption()){
        playerPosList -> removeTail();
    }
}

// More methods to be added

char Player::getDirection() {
    switch(myDir){
        case STOP:
            return 'S';
            
        case UP:
            return 'U';
        
        case DOWN:
            return 'D';

        case LEFT:
            return 'L';
        
        case RIGHT:
            return 'R';
        
        default:
            return 'F';
    }
}

bool Player::checkFoodConsumption(){
    objPos foodTemp = foodRef->getFoodPos();
    if (head.isPosEqual(&foodTemp)) {
        foodRef -> generateFood(getPlayerPos());
        mainGameMechsRef -> incrementScore();
        return true;
    }
    return false;
    // objPos foodTemp = foodRef -> getFoodPos();
    // if (head.isPosEqual(&foodTemp)){
    //     return true;
    // }
    // return false;
}

bool Player::checkSelfCollision(){
    int i, size;
    playerPosList->getSize();
    for (i = 1; i < size; i++){
        if (head.getX() == playerPosList->getElement(i).getX() && head.getY() == playerPosList->getElement(i).getY())  //<-- when you finish objPosArrayList, change this method
        {
            mainGameMechsRef -> setLoseFlag();
            break;
        }
    }
}

void Player::increasePlayerLength(){

}

//Getter Method for X and Y
int Player:: playX(){
    return playerPosList -> getHeadElement().getX();
}

int Player:: playY() {
    return playerPosList -> getHeadElement().getY();
}