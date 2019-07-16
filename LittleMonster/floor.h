#ifndef FLOOR_H
#define FLOOR_H

#include <QGraphicsPixmapItem>
#include <QString>

class floor : public QGraphicsPixmapItem
{
private:
    bool stone;
    bool AI;
    bool food;
    bool dizzyAI;

public:
    floor();  
    bool isStone();
    bool isAI();
    bool isFood();
    bool isDizzyAI();
    void setStone(bool b);
    void setAI(bool b);
    void setFood(bool b);
    void setDizzyAI(bool b);
};

#endif // FLOOR_H
