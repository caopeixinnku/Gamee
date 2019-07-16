#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsPixmapItem>

class Food : public QGraphicsPixmapItem
{
private:
    int posX,posY;

public:
    Food(int x=4,int y=4);
    int getX();
    int getY();
};

#endif // FOOD_H
