#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;
    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
    aList = nullptr;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    int i;

    if (listSize < arrayCapacity){
        listSize++;

        for(i=listSize; i > 0; i--){
            aList[i] = aList[i-1];
        }
        
    aList[0] = thisPos;
    }

    
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize < arrayCapacity){
        aList[listSize] = thisPos;
        listSize++;
    }
}

void objPosArrayList::removeHead()
{
    int i;

    if (listSize > 0){
        for(i = 0; i < listSize - 1; i++){
            aList[i] = aList[i+1];
        }
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    if (listSize > 0){
        listSize--;
    }
    
}

objPos objPosArrayList::getHeadElement() const
{
    if (listSize > 0){
        return aList[0];
    }
}

objPos objPosArrayList::getTailElement() const
{
    if (listSize > 0){
        return aList[(listSize-1)];
    }
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}