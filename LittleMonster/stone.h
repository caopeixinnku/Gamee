#ifndef STONE_H
#define STONE_H

#include <QGraphicsPixmapItem>

class Stone : public QGraphicsPixmapItem
{
private:
        int posX,posY;
        bool still;

public:
    Stone(int x=1,int y=1);
    int getX();
    int getY();
    bool isStill();
    void setX(int x);
    void setY(int y);
    void setStill(bool b);
    void setPic(QString path);

};

#endif // STONE_H
