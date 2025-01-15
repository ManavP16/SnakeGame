#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "stdlib.h"
#include "time.h"

class Food
{
    private:
        objPos foodPos; //Tracks the position of food

        GameMechs* mainGameMechsRef; // reference to main game mechanisms (if needed)
        objPosArrayList* foodBucket;
        

    public:
        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(objPosArrayList* blockOff);
        void generateBonusFood(objPosArrayList* blockOff);
        objPos getFoodPos() const;


};

#endif