#include "stone.h"

Stone::Stone(int x,int y)
{
    this -> setPixmap (QPixmap(":/bg/pic/stone_one_a.png"));
    this -> posX= x;
    this -> posY= y;
    this->still = true;
}

int Stone::getX()
{
    return this->posX;
}

int Stone::getY()
{
    return this->posY;
}

bool Stone::isStill()
{
    return this->still;
}

void Stone::setX(int x)
{
    this->posX = x;
}

void Stone::setY(int y)
{
    this->posY = y;
}

void Stone::setStill(bool b)
{
    this->still = b;
}

void Stone::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}
