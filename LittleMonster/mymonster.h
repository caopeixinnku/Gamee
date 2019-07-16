#ifndef MYMONSTER_H
#define MYMONSTER_H

#include <QGraphicsPixmapItem>
#include <QDebug>

class myMonster: public QGraphicsPixmapItem
{
private:
    int posX,posY;
    bool dead;
    bool withStone;
    QString faceDirection;

public:
    myMonster();
    void setPic(QString path);
    void turnLeft();
    void turnRight();
    void turnUp();
    void turnDown();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void spitOut();
    void shrink();
    void eatingStone();
    int getX();
    int getY();
    bool isDead();
    bool isWithStone();
    QString getFaceDirection();
    void setDead(bool b);
    void setWithStone(bool b);
    void setFaceDirection(QString str);
};

#endif // MYMONSTER_H
