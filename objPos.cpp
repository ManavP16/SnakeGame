#include "objPos.h"

objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule

// First special member function is the destructor.
objPos::~objPos(){
    delete pos; //Deallocates the memory from the heap
    pos = nullptr;
}

//Next special function is the copy constructor
objPos::objPos(const objPos& other){
    pos = new Pos;
    pos -> x = other.pos -> x;
    pos -> y = other.pos -> y;
    symbol = other.symbol;
}

//Last special function is the copy assignment operator
objPos &objPos::operator=(const objPos& other){
    pos -> x = other.pos -> x;
    pos -> y = other.pos -> y;
    symbol = other.symbol;

    return *this;
}

obj3 = obj2;
obj3.operator=(obj2);
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}

// Additional Methods (only for iteration 1 and 2)

int objPos:: getX(){
    return pos->x;
}

    // Getter method for y
int objPos:: getY() {
    return pos->y;
}

void objPos:: setX(int xValue){
    pos->x = xValue;
}

void objPos:: setY(int yValue){
    pos->y = yValue;
}

void objPos::changeX(int direction)
{
    pos -> x += direction;
}

void objPos::changeY(int direction)
{
    pos -> y += direction;
}
