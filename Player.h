#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"


class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {STOP, UP, DOWN, LEFT, RIGHT};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFoodRef);

        ~Player();

        objPosArrayList* getPlayerPos() const; // Upgrade this in iteration 3.  <-- Will change this     
        void updatePlayerDir();
        void movePlayer(); //Player Position update algorithm

        // More methods to be added here
        char getDirection();
        int playX();
        int playY();

        bool checkFoodConsumption();
        bool checkSelfCollision();
        void increasePlayerLength();

    private:
        //objPos playerPos; // Upgrade this in iteration 3.    <-- Will change this   
        objPosArrayList* playerPosList;
        objPos head;
        
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* foodRef;
};

#endif