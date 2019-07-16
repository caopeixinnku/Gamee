#include "floor.h"

floor::floor()
{
    this->setPixmap(QPixmap(""));
    this->stone = false;
    this->AI = false;
    this->food = false;
    this->dizzyAI = false;
}

bool floor::isStone()
{
    return this->stone;
}

bool floor::isAI()
{
    return this->AI;
}

bool floor::isFood()
{
    return this->food;
}

bool floor::isDizzyAI()
{
    return this->dizzyAI;
}

void floor::setStone(bool b)
{
    this->stone = b;
}

void floor::setAI(bool b)
{
    this->AI = b;
}

void floor::setFood(bool b)
{
    this->food = b;
}

void floor::setDizzyAI(bool b)
{
    this->dizzyAI = b;
}
