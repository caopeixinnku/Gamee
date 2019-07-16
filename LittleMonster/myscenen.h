#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "background.h"
#include "mymonster.h"
#include "floor.h"
#include "stone.h"
#include "ai.h"
#include "food.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QKeyEvent>
#include "handler.h"

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyScene(QObject *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    bool checkStongUp();
    bool checkStongLeft();
    bool checkStongDown();
    bool checkStongRight();
    bool checkFoodUp();
    bool checkFoodLeft();
    bool checkFoodDown();
    bool checkFoodRight();
    bool checkDizzyAIUp();
    bool checkDizzyAILeft();
    bool checkDizzyAIDown();
    bool checkDizzyAIRight();
    void mEat();
    void mSpitOutStone();
    void mDie();
    int stoneIndex(int x,int y);
    int foodIndex(int x,int y);
    int AIIndex(int x,int y);
    int t;

signals:
    void signal_eatFood();
    void signal_eatAI();
    void signal_victory();
    void signal_defeat();

public slots:
    void mShrink();
    void sMoveUp();
    void sMoveLeft();
    void sMoveDown();
    void sMoveRight();
    void AIMove();

private:
    myMonster *mstr;
    Background *bg;
    Stone *stone[20];
    floor *flr[15][15];
    QTimer *timerStone;
    QTimer *timerAI;
    QTime *time[3];
    AI *ai[3];
    Food *food[4];
    int AINum;
};

#endif // MYSCENE_H
