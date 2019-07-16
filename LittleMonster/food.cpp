#include "food.h"

Food::Food(int x,int y)
{
    this->posX = x;
    this->posY = y;
    this->setPixmap(QPixmap(":/food/pic/food.png"));
}

int Food::getX()
{
    return this->posX;
}

int Food::getY()
{
    return this->posY;
}
