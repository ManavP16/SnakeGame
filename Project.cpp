#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "player.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000
#define BOARD_H 15
#define BOARD_W 30

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

//Global Scope
GameMechs *game;   //Created a GameMech object with default board size
Player *snake;     //Created the snake for game
Food *snakeFood;
//objPos *symbolTest;    //Check for iteration 1A


int main(void)
{

    Initialize();

    while(!game -> getExitFlagStatus() && !game -> getLoseFlagStatus())  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
        //For memory leak testing
        //game -> setExitTrue();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;
    game = new GameMechs();
    snakeFood = new Food(game);
    snake = new Player(game, snakeFood);

    snakeFood -> generateFood(snake->getPlayerPos());
    //snakeFood -> generateBonusFood(snake->getPlayerPos());
    //symbolTest = new objPos(15, 7, '*');

}

void GetInput(void)
{
    if (MacUILib_hasChar())
    {
        game -> setInput(MacUILib_getChar());
    }
   
}

void RunLogic(void)
{
    snake -> updatePlayerDir();
    snake -> movePlayer();
    snake -> checkSelfCollision();
    game -> clearInput();

    //For Testing
    if ((game -> getScore()) == 69){
        game -> setExitTrue();
    }

    // For Iteration 2B check
    //snakeFood -> generateFood(snake->getPlayerPos());
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    int x, y, i, length, width, playerX, playerY, size;
    char playerSymbol, directionChar;
    length = game -> getBoardSizeY();
    width = game -> getBoardSizeX();
    // playerX = snake -> playX();
    // playerY = snake -> playY();
    
    bool isSnake = false;
    objPosArrayList* player = snake -> getPlayerPos();

    directionChar = snake -> getDirection();
    size = player->getSize();

    //Temporary variables
    //playerX = symbolTest -> getX();
    //playerY = symbolTest -> getY();
    //playerSymbol = symbolTest -> getSymbol();


    //Player Direction
    MacUILib_printf("Player Direction: %c\n", directionChar);
    //MacUILib_printf("Player Position: x:%d, y:%d\n", playerX, playerY);
    MacUILib_printf("Player Score: %d\n", game -> getScore());


    //Iteration 0, drawing the board
    for(y = 0; y < length; y++){
        for(x = 0; x < width; x++){
            if(x == 0 || x == (width - 1) || y == 0 || y == (length - 1)){
                MacUILib_printf("#");
                continue;
            }
            isSnake = false;
            for (i = 0; i < size; i++){
                if (x == player->getElement(i).getX() && y == player->getElement(i).getY()) {
                MacUILib_printf("%c", player->getElement(i).getSymbol());
                isSnake = true;
                break;
                }
            }
            if (isSnake) continue;
            if (x == snakeFood -> getFoodPos().pos -> x && y == snakeFood -> getFoodPos().pos -> y)
                {
                    MacUILib_printf("@");
                    continue;
                }
            else{
                MacUILib_printf(" ");
            }
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
    
    //End-game messages
    if (game -> getLoseFlagStatus()) 
    {
        MacUILib_printf("You lose bruh.\nYour final score was %d.", game -> getScore());
    }

    // Check if the player won based on the score
    else if (game -> getScore() > 10) 
    {
        MacUILib_printf("Congratulations you win, here's a cookie, tryhard.\nYour final score was %d.", game -> getScore());
    }

    // Check if the game ended early without losing or winning
    else if (game -> getExitFlagStatus()) 
    {
        MacUILib_printf("Why did you quit?\nYour final score was %d.", game -> getScore());
    } 

    MacUILib_uninit();
    delete game;
    delete snake;
    delete snakeFood;
    //delete symbolTest;
}
