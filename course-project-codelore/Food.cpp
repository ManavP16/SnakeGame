#include "Food.h"

Food::Food(GameMechs* thisGMRef)
{
    foodPos = objPos(); //Default instance
    mainGameMechsRef = thisGMRef;
    foodBucket = new objPosArrayList;
    insertHead(objPos(mainGameMechsRef -> getBoardSizeX()/2, mainGameMechsRef -> getBoardSizeY()/2, '*'));
}

Food::~Food()
{
    // if required
    delete foodBucket;
    foodBucket = nullptr;
}

void Food::generateFood(objPosArrayList* blockOff)
//void Food::generateFood(objPosArrayList* blockOff) //<--Another change to make when you update player class
{
    int randomX, randomY, i, bLength, bWidth, size;
    bool validPosition = false;
    //For seeding random number generation (PPA3)
    srand(time(NULL));
    bLength = mainGameMechsRef -> getBoardSizeY();
    bWidth = mainGameMechsRef -> getBoardSizeX();
    size = blockOff -> getSize();
    while (!validPosition){
        validPosition = true;
        randomX = (rand() % (bWidth - 2)) + 1;
        randomY = (rand() % (bLength - 2)) + 1; 
        for (i = 0; i < size; i++){
            if (randomX == blockOff->getElement(i).getX() && randomY == blockOff->getElement(i).getY())  //<-- when you finish objPosArrayList, change this method
            {
                validPosition = false;
                break;
            }
        }
    }
    foodPos.pos -> x = randomX;
    foodPos.pos -> y = randomY;

}
void Food::generateBonusFood(objPosArrayList* blockoff){
    // int i;
    // for(i=0; i < 5; i++){
    //     generateFood(blockoff);
    // }
}

objPos Food::getFoodPos() const
{
    return foodPos;
}