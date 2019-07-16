#include "mymonster.h"

myMonster::myMonster()
{
    this->setPixmap(QPixmap(":/monster/pic/zheng_a.png"));
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->dead = false;
    this->posX = 6;
    this->posY = 6;
    this->withStone = false;
    this->faceDirection = "front";
}

void myMonster::turnUp()
{
    if(!this->withStone){
        if(this->faceDirection != "back"){
            this->setPic(":/monster/pic/fan_a.png");
            this->faceDirection = "back";
        }
        else return;
    }
    else {
        if(this->faceDirection != "back"){
            this->setPic(":/monster/pic/fan_tun_a.png");
            this->faceDirection = "back";
        }
        else return;
    }
}

void myMonster::turnLeft()
{
    if(!this->withStone){
        if(this->faceDirection != "left"){
            this->setPic(":/monster/pic/left_a.png");
            this->faceDirection = "left";
        }
        else return;
    }
    else {
        if(this->faceDirection != "left"){
            this->setPic(":/monster/pic/left_tun_a.png");
            this->faceDirection = "left";
        }
        else return;
    }
}

void myMonster::turnDown()
{
    if(!this->withStone){
        if(this->faceDirection != "front"){
            this->setPic(":/monster/pic/zheng_a.png");
            this->faceDirection = "front";
        }
        else return;
    }
    else {
        if(this->faceDirection != "front"){
            this->setPic(":/monster/pic/zheng_tun_a.png");
            this->faceDirection = "front";
        }
        else return;
    }
}

void myMonster::turnRight()
{
    if(!this->withStone){
        if(this->faceDirection != "right"){
            this->setPic(":/monster/pic/right_a.png");
            this->faceDirection = "right";
        }
        else return;
    }
    else {
        if(this->faceDirection != "right"){
            this->setPic(":/monster/pic/right_tun_a.png");
            this->faceDirection = "right";
        }
        else return;
    }
}

void myMonster::moveUp()
{
    if(!this->withStone){
        if(this->faceDirection == "back"){
            if(this->posY <= 0) return;
            else {
                this->moveBy(0,-40);
                this->posY--;
            }
        }
        else {
            this->setPic(":/monster/pic/fan_a.png");
            this->faceDirection = "back";
        }
    }
    else {
        if(this->faceDirection == "back"){
            if(this->posY <= 0) return;
            else {
                this->moveBy(0,-40);
                this->posY--;
            }
        }
        else {
            this->setPic(":/monster/pic/fan_tun_a.png");
            this->faceDirection = "back";
        }
    }
}

void myMonster::moveLeft()
{
    if(!this->withStone){
        if(this->faceDirection == "left"){
            if(this->posX <= 0) return;
            else {
                this->moveBy(-40,0);
                this->posX--;
            }
        }
        else {
            this->setPic(":/monster/pic/left_a.png");
            this->faceDirection = "left";
        }
    }
    else {
        if(this->faceDirection == "left"){
            if(this->posX <= 0) return;
            else {
                this->moveBy(-40,0);
                this->posX--;
            }
        }
        else {
            this->setPic(":/monster/pic/left_tun_a.png");
            this->faceDirection = "left";
        }
    }
}

void myMonster::moveDown()
{
    if(!this->withStone){
        if(this->faceDirection == "front"){
            if(this->posY >= 14) return;
            else {
                this->moveBy(0,40);
                this->posY++;
            }
        }
        else {
            this->setPic(":/monster/pic/zheng_a.png");
            this->faceDirection = "front";
        }
    }
    else {
        if(this->faceDirection == "front"){
            if(this->posY >= 14) return;
            else {
                this->moveBy(0,40);
                this->posY++;
            }
        }
        else {
            this->setPic(":/monster/pic/zheng_tun_a.png");
            this->faceDirection = "front";
        }
    }
}

void myMonster::moveRight()
{
    if(!this->withStone){
        if(this->faceDirection == "right"){
            if(this->posX >= 14) return;
            else {
                this->moveBy(40,0);
                this->posX++;
            }
        }
        else {
            this->setPic(":/monster/pic/right_a.png");
            this->faceDirection = "right";
        }
    }
    else {
        if(this->faceDirection == "right"){
            if(this->posX >= 14) return;
            else {
                this->moveBy(40,0);
                this->posX++;
            }
        }
        else {
            this->setPic(":/monster/pic/right_tun_a.png");
            this->faceDirection = "right";
        }
    }
}

void myMonster::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}

void myMonster::shrink()
{
    if(!this->withStone){
        if(this->faceDirection == "left") this->setPic(":/monster/pic/left_a.png");
        if(this->faceDirection == "right") this->setPic(":/monster/pic/right_a.png");
        if(this->faceDirection == "front") this->setPic(":/monster/pic/zheng_a.png");
        if(this->faceDirection == "back") this->setPic(":/monster/pic/fan_a.png");
    }
    else {
        if(this->faceDirection == "left") this->setPic(":/monster/pic/left_tun_a.png");
        if(this->faceDirection == "right") this->setPic(":/monster/pic/right_tun_a.png");
        if(this->faceDirection == "front") this->setPic(":/monster/pic/zheng_tun_a.png");
        if(this->faceDirection == "back") this->setPic(":/monster/pic/fan_tun_a.png");
    }
}

void myMonster::spitOut()
{
    if(this->faceDirection == "left") this->setPic(":/monster/pic/left_tu_a.png");
    if(this->faceDirection == "right") this->setPic(":/monster/pic/right_tu_a.png");
    if(this->faceDirection == "front") this->setPic(":/monster/pic/zheng_tu_a.png");
    if(this->faceDirection == "back") this->setPic(":/monster/pic/fan_tu_a.png");
}

void myMonster::eatingStone()
{
    if(this->faceDirection == "left") this->setPic(":/monster/pic/left_tian_a.png");
    if(this->faceDirection == "right") this->setPic(":/monster/pic/right_tian_a.png");
    if(this->faceDirection == "front") this->setPic(":/monster/pic/zheng_tian_a.png");
    if(this->faceDirection == "back") this->setPic(":/monster/pic/fan_tian_a.png");
}

int myMonster::getX()
{
    return this->posX;
}

int myMonster::getY()
{
    return this->posY;
}

bool myMonster::isDead()
{
    return this->dead;
}

void myMonster::setDead(bool b)
{
    this->dead = b;
}

bool myMonster::isWithStone()
{
    return  this->withStone;
}

void myMonster::setWithStone(bool b)
{
    this->withStone = b;
}

QString myMonster::getFaceDirection()
{
    return this->faceDirection;
}

void myMonster::setFaceDirection(QString str)
{
    this->faceDirection = str;
}
