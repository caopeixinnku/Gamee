#include "myscenen.h"

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent)
{
    this->t = -1;
    this->bg = new Background;
    this->addItem(this->bg);

    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++){
            this->flr[i][j] = new floor;
            this->flr[i][j]->setPos(i*flr[i][j]->boundingRect().width(),j*flr[i][j]->boundingRect().height());
            this->addItem(this->flr[i][j]);
        }

    this->ai[0] = new AI(0,0);
    this->ai[1] = new AI(14,0);
    this->ai[2] = new AI(0,14);
    for(int i=0;i<3;i++){
        this->ai[i]->setPos(this->ai[i]->getX()*40,this->ai[i]->getY()*40);
        this->addItem(this->ai[i]);
        this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(true);
    }
    this->AINum = 3;

    this->stone[0] = new Stone(3,0);
    this->stone[1] = new Stone(11,0);
    this->stone[2] = new Stone(0,3);
    this->stone[3] = new Stone(14,3);
    this->stone[4] = new Stone(0,11);
    this->stone[5] = new Stone(14,11);
    this->stone[6] = new Stone(3,14);
    this->stone[7] = new Stone(11,14);
    this->stone[8] = new Stone(5,5);
    this->stone[9] = new Stone(5,6);
    this->stone[10] = new Stone(5,7);
    this->stone[11] = new Stone(5,8);
    this->stone[12] = new Stone(6,5);
    this->stone[13] = new Stone(6,8);
    this->stone[14] = new Stone(7,5);
    this->stone[15] = new Stone(7,8);
    this->stone[16] = new Stone(8,5);
    this->stone[17] = new Stone(8,6);
    this->stone[18] = new Stone(8,7);
    this->stone[19] = new Stone(8,8);
    for(int i=0;i<20;i++){
        this->stone[i]->setPos(this->stone[i]->getX()*this->stone[i]->boundingRect().width(),this->stone[i]->getY()*this->stone[i]->boundingRect().height());
        this->addItem(this->stone[i]);
        this->flr[this->stone[i]->getX()][this->stone[i]->getY()]->setStone(true);
    }

    this->mstr = new myMonster;
    this->mstr->setPos(6*40,6*40);
    this->addItem(this->mstr);
    this->mstr->setFocus();

    this->food[0] = new Food;
    this->food[1] = new Food(9,4);
    this->food[2] = new Food(4,9);
    this->food[3] = new Food(9,9);
    for(int i=0;i<4;i++){
        this->food[i]->setPos(this->food[i]->getX()*40,this->food[i]->getY()*40);
        this->addItem(this->food[i]);
        this->flr[this->food[i]->getX()][this->food[i]->getY()]->setFood(true);
    }

    this->timerAI = new QTimer;
    connect(this->timerAI,SIGNAL(timeout()),this,SLOT(AIMove()));
    this->timerAI->start(500);

    this->timerStone = new QTimer;

    for(int i=0;i<3;i++)
        this->time[i] = new QTime;
}

int MyScene::stoneIndex(int x, int y)
{
    for(int i=0;i<20;i++){
        if(this->stone[i]->getX() == x && this->stone[i]->getY() == y)
            return i;
    }
}

int MyScene::foodIndex(int x, int y)
{
    for(int i=0;i<4;i++){
        if(this->food[i]->getX() == x && this->food[i]->getY() == y)
            return i;
    }
}

int MyScene::AIIndex(int x, int y)
{
    for(int i=0;i<3;i++){
        if(this->ai[i]->getX() == x && this->ai[i]->getY() == y)
            return i;
    }
}

void MyScene::mShrink()
{
    this->mstr->shrink();
}

void MyScene::sMoveUp()
{
    if(this->stone[t]->getY() == 0 || this->flr[this->stone[t]->getX()][this->stone[t]->getY()-1]->isStone() || this->flr[this->stone[t]->getX()][this->stone[t]->getY()-1]->isFood()) {
        this->stone[t]->setStill(true);
        this->timerStone->stop();
        disconnect(this->timerStone,SIGNAL(timeout()),this,SLOT(sMoveUp()));
        return;
    }
    else {
        this->stone[t]->setStill(false);
        this->flr[this->stone[t]->getX()][this->stone[t]->getY()]->setStone(false);
        this->stone[t]->setY(this->stone[t]->getY()-1);
        this->flr[this->stone[t]->getX()][this->stone[t]->getY()]->setStone(true);
        this->stone[t]->moveBy(0,-40);
        for(int i=0;i<3;i++){
            if(this->ai[i]->getX() == this->stone[t]->getX() && this->ai[i]->getY() == this->stone[t]->getY()){
                this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(false);
                this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setDizzyAI(true);
                this->ai[i]->setDizzy(true);
                this->time[i]->restart();
            }
        }
    }
}

void MyScene::sMoveLeft()
{
    if(this->stone[t]->getX() == 0 || this->flr[this->stone[t]->getX()-1][this->stone[t]->getY()]->isStone() || this->flr[this->stone[t]->getX()-1][this->stone[t]->getY()]->isFood()) {
        this->stone[t]->setStill(true);
        this->timerStone->stop();
        disconnect(this->timerStone,SIGNAL(timeout()),this,SLOT(sMoveLeft()));
        return;
    }
    else {
        this->stone[t]->setStill(false);
        this->flr[this->stone[t]->getX()][this->stone[t]->getY()]->setStone(false);
        this->stone[t]->setX(this->stone[t]->getX()-1);
        this->flr[this->stone[t]->getX()][this->stone[t]->getY()]->setStone(true);
        this->stone[t]->moveBy(-40,0);
        for(int i=0;i<3;i++){
            if(this->ai[i]->getX() == this->stone[t]->getX() && this->ai[i]->getY() == this->stone[t]->getY()){
                this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(false);
                this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setDizzyAI(true);
                this->ai[i]->setDizzy(true);
                this->time[i]->restart();
            }
        }
    }
}

void MyScene::sMoveDown()
{
    if(this->stone[t]->getY() == 14 || this->flr[this->stone[t]->getX()][this->stone[t]->getY()+1]->isStone() || this->flr[this->stone[t]->getX()][this->stone[t]->getY()+1]->isFood()) {
        this->stone[t]->setStill(true);
        this->timerStone->stop();
        disconnect(this->timerStone,SIGNAL(timeout()),this,SLOT(sMoveDown()));
        return;
    }
    else {
        this->stone[t]->setStill(false);
        this->flr[this->stone[t]->getX()][this->stone[t]->getY()]->setStone(false);
        this->stone[t]->setY(this->stone[t]->getY()+1);
        this->flr[this->stone[t]->getX()][this->stone[t]->getY()]->setStone(true);
        this->stone[t]->moveBy(0,40);
        for(int i=0;i<3;i++){
            if(this->ai[i]->getX() == this->stone[t]->getX() && this->ai[i]->getY() == this->stone[t]->getY()){
                this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(false);
                this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setDizzyAI(true);
                this->ai[i]->setDizzy(true);
                this->time[i]->restart();
            }
        }
    }
}

void MyScene::sMoveRight()
{
    if(this->stone[t]->getX() == 14 || this->flr[this->stone[t]->getX()+1][this->stone[t]->getY()]->isStone() || this->flr[this->stone[t]->getX()+1][this->stone[t]->getY()]->isFood()) {
        this->stone[t]->setStill(true);
        this->timerStone->stop();
        disconnect(this->timerStone,SIGNAL(timeout()),this,SLOT(sMoveRight()));
        return;
    }
    else {
        this->stone[t]->setStill(false);
        this->flr[this->stone[t]->getX()][this->stone[t]->getY()]->setStone(false);
        this->stone[t]->setX(this->stone[t]->getX()+1);
        this->flr[this->stone[t]->getX()][this->stone[t]->getY()]->setStone(true);
        this->stone[t]->moveBy(40,0);
        for(int i=0;i<3;i++){
            if(this->ai[i]->getX() == this->stone[t]->getX() && this->ai[i]->getY() == this->stone[t]->getY()){
                this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(false);
                this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setDizzyAI(true);
                this->ai[i]->setDizzy(true);
                this->time[i]->restart();
            }
        }
    }
}

void MyScene::AIMove()
{
    for(int i=0;i<3;i++){
        if(!this->ai[i]->isDead()){
            if(!this->ai[i]->isDizzy()){
            if(this->ai[i]->getFaceDirection() == "back"){
                if(this->ai[i]->getY() == 0 || (this->flr[this->ai[i]->getX()][this->ai[i]->getY()-1]->isStone() && this->stone[this->stoneIndex(this->ai[i]->getX(),this->ai[i]->getY()-1)]->isStill()) || this->flr[this->ai[i]->getX()][this->ai[i]->getY()-1]->isFood() || this->flr[this->ai[i]->getX()][this->ai[i]->getY()-1]->isAI())
                    this->ai[i]->turn();
                else {
                    this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(false);
                    this->ai[i]->moveUp();
                    this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(true);
                }
            }
            if(this->ai[i]->getFaceDirection() == "left"){
                if(this->ai[i]->getX() == 0 || (this->flr[this->ai[i]->getX()-1][this->ai[i]->getY()]->isStone() && this->stone[this->stoneIndex(this->ai[i]->getX()-1,this->ai[i]->getY())]->isStill())|| this->flr[this->ai[i]->getX()-1][this->ai[i]->getY()]->isFood() || this->flr[this->ai[i]->getX()-1][this->ai[i]->getY()]->isAI())
                    this->ai[i]->turn();
                else {
                    this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(false);
                    this->ai[i]->moveLeft();
                    this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(true);
                }
            }
            if(this->ai[i]->getFaceDirection() == "front"){
                if(this->ai[i]->getY() == 14 || (this->flr[this->ai[i]->getX()][this->ai[i]->getY()+1]->isStone() && this->stone[this->stoneIndex(this->ai[i]->getX(),this->ai[i]->getY()+1)]->isStill()) || this->flr[this->ai[i]->getX()][this->ai[i]->getY()+1]->isFood() || this->flr[this->ai[i]->getX()][this->ai[i]->getY()+1]->isAI())
                    this->ai[i]->turn();
                else {
                    this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(false);
                    this->ai[i]->moveDown();
                    this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(true);
                }
            }
            if(this->ai[i]->getFaceDirection() == "right"){
                if(this->ai[i]->getX() == 14 || (this->flr[this->ai[i]->getX()+1][this->ai[i]->getY()]->isStone() && this->stone[this->stoneIndex(this->ai[i]->getX()+1,this->ai[i]->getY())]->isStill()) || this->flr[this->ai[i]->getX()+1][this->ai[i]->getY()]->isFood() || this->flr[this->ai[i]->getX()+1][this->ai[i]->getY()]->isAI())
                    this->ai[i]->turn();
                else {
                    this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(false);
                    this->ai[i]->moveRight();
                    this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(true);
                }
            }
        }
            else {
                this->ai[i]->getDizzy();
                if(this->time[i]->elapsed() >= 5000) {
                    this->ai[i]->wakeUp();
                    this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setDizzyAI(false);
                    this->flr[this->ai[i]->getX()][this->ai[i]->getY()]->setAI(true);
                    this->time[i]->restart();
                }
            }
        }
    }
    this->mDie();
}

bool MyScene::checkStongUp()
{
    if(this->mstr->getY()-1 < 0) return false;
    else {
        if(this->flr[this->mstr->getX()][this->mstr->getY()-1]->isStone()) return true;
        else return false;
    }
}

bool MyScene::checkStongLeft()
{
    if(this->mstr->getX()-1 < 0) return false;
    else {
        if(this->flr[this->mstr->getX()-1][this->mstr->getY()]->isStone()) return true;
        else return false;
    }
}

bool MyScene::checkStongDown()
{
    if(this->mstr->getY()+1 > 14) return false;
    else {
        if(this->flr[this->mstr->getX()][this->mstr->getY()+1]->isStone()) return true;
        else return false;
    }
}

bool MyScene::checkStongRight()
{
    if(this->mstr->getX()+1 > 14) return false;
    else {
        if(this->flr[this->mstr->getX()+1][this->mstr->getY()]->isStone()) return true;
        else return false;
    }
}

bool MyScene::checkFoodUp()
{
    if(this->mstr->getY()-1 < 0) return false;
    else {
        if(this->flr[this->mstr->getX()][this->mstr->getY()-1]->isFood()) return true;
        else return false;
    }
}

bool MyScene::checkFoodLeft()
{
    if(this->mstr->getX()-1 < 0) return false;
    else {
        if(this->flr[this->mstr->getX()-1][this->mstr->getY()]->isFood()) return true;
        else return false;
    }
}

bool MyScene::checkFoodDown()
{
    if(this->mstr->getY()+1 > 14) return false;
    else {
        if(this->flr[this->mstr->getX()][this->mstr->getY()+1]->isFood()) return true;
        else return false;
    }
}

bool MyScene::checkFoodRight()
{
    if(this->mstr->getX()+1 > 14) return false;
    else {
        if(this->flr[this->mstr->getX()+1][this->mstr->getY()]->isFood()) return true;
        else return false;
    }
}

bool MyScene::checkDizzyAIUp()
{
    if(this->mstr->getY()-1 < 0) return false;
    else {
        if(this->flr[this->mstr->getX()][this->mstr->getY()-1]->isDizzyAI()) return true;
        else return false;
    }
}

bool MyScene::checkDizzyAILeft()
{
    if(this->mstr->getX()-1 < 0) return false;
    else {
        if(this->flr[this->mstr->getX()-1][this->mstr->getY()]->isDizzyAI()) return true;
        else return false;
    }
}

bool MyScene::checkDizzyAIDown()
{
    if(this->mstr->getY()+1 > 14) return false;
    else {
        if(this->flr[this->mstr->getX()][this->mstr->getY()+1]->isDizzyAI()) return true;
        else return false;
    }
}

bool MyScene::checkDizzyAIRight()
{
    if(this->mstr->getX()+1 > 14) return false;
    else {
        if(this->flr[this->mstr->getX()+1][this->mstr->getY()]->isDizzyAI()) return true;
        else return false;
    }
}

void MyScene::mEat()
{
    handler*hand=handler::getInstance();
    if(this->mstr->getFaceDirection() == "back"){
        if(!this->checkStongUp() && !this->checkFoodUp() && !this->checkDizzyAIUp()){
            this->mstr->spitOut();
            QTimer::singleShot(400,this,SLOT(mShrink()));
        }
        else if(this->checkStongUp()){
            this->mstr->eatingStone();
            this->stone[this->stoneIndex(this->mstr->getX(),this->mstr->getY()-1)]->setPic(":/bg/pic/floor.png");
            this->t = this->stoneIndex(this->mstr->getX(),this->mstr->getY()-1);
            qDebug() << t;
            this->flr[this->mstr->getX()][this->mstr->getY()-1]->setStone(false);
            this->mstr->setWithStone(true);
            QTimer::singleShot(400,this,SLOT(mShrink()));
        }
        else if(this->checkFoodUp()){
            emit this->signal_eatFood();
            hand->addscore();
            this->mstr->spitOut();
            this->flr[this->mstr->getX()][this->mstr->getY()-1]->setFood(false);
            delete food[this->foodIndex(this->mstr->getX(),this->mstr->getY()-1)];
            QTimer::singleShot(400,this,SLOT(mShrink()));
        }
        else {
            emit this->signal_eatAI();
            hand->addscore();
            this->mstr->spitOut();
            this->flr[this->mstr->getX()][this->mstr->getY()-1]->setDizzyAI(false);
            this->ai[this->AIIndex(this->mstr->getX(),this->mstr->getY()-1)]->die();
            this->AINum--;
            if(this->AINum == 0) {
                emit signal_victory();
                this->mstr->setPic(":/monster/pic/victory.png");
            }
        }
    }
    if(this->mstr->getFaceDirection() == "left"){
        if(!this->checkStongLeft() && !this->checkFoodLeft() && !this->checkDizzyAILeft()){
            this->mstr->spitOut();
            QTimer::singleShot(400,this,SLOT(mShrink()));
        }
        else if(this->checkStongLeft()){
            this->mstr->eatingStone();
            this->stone[this->stoneIndex(this->mstr->getX()-1,this->mstr->getY())]->setPic(":/bg/pic/floor.png");
            this->t = this->stoneIndex(this->mstr->getX()-1,this->mstr->getY());
            qDebug() << t;
            this->flr[this->mstr->getX()-1][this->mstr->getY()]->setStone(false);
            this->mstr->setWithStone(true);
            QTimer::singleShot(400,this,SLOT(mShrink()));
        }
        else if(this->checkFoodLeft()){
            emit this->signal_eatFood();
            hand->addscore();
            this->mstr->spitOut();
            this->flr[this->mstr->getX()-1][this->mstr->getY()]->setFood(false);
            delete food[this->foodIndex(this->mstr->getX()-1,this->mstr->getY())];
            QTimer::singleShot(400,this,SLOT(mShrink()));
        }
        else {
            emit this->signal_eatAI();
            hand->addscore();
            this->mstr->spitOut();
            this->flr[this->mstr->getX()-1][this->mstr->getY()]->setDizzyAI(false);
            this->ai[this->AIIndex(this->mstr->getX()-1,this->mstr->getY())]->die();
            this->AINum--;
            if(this->AINum == 0) {
                emit signal_victory();
                this->mstr->setPic(":/monster/pic/victory.png");
            }
        }
    }
    if(this->mstr->getFaceDirection() == "front"){
        if(!this->checkStongDown() && !this->checkFoodDown() && !this->checkDizzyAIDown()){
            this->mstr->spitOut();
            QTimer::singleShot(400,this,SLOT(mShrink()));
        }
        else if(this->checkStongDown()){
            this->mstr->eatingStone();
            this->stone[this->stoneIndex(this->mstr->getX(),this->mstr->getY()+1)]->setPic(":/bg/pic/floor.png");
            this->t = this->stoneIndex(this->mstr->getX(),this->mstr->getY()+1);
            qDebug() << t;
            this->flr[this->mstr->getX()][this->mstr->getY()+1]->setStone(false);
            this->mstr->setWithStone(true);
            QTimer::singleShot(400,this,SLOT(mShrink()));
        }
        else if(this->checkFoodDown()){
            emit this->signal_eatFood();
            hand->addscore();
            this->mstr->spitOut();
            this->flr[this->mstr->getX()][this->mstr->getY()+1]->setFood(false);
            delete food[this->foodIndex(this->mstr->getX(),this->mstr->getY()+1)];
            QTimer::singleShot(400,this,SLOT(mShrink()));
        }
        else {
            emit this->signal_eatAI();
            hand->addscore();
            this->mstr->spitOut();
            this->flr[this->mstr->getX()][this->mstr->getY()+1]->setDizzyAI(false);
            this->ai[this->AIIndex(this->mstr->getX(),this->mstr->getY())+1]->die();
            this->AINum--;
            if(this->AINum == 0) {
                emit signal_victory();
                this->mstr->setPic(":/monster/pic/victory.png");
            }
        }
    }
    if(this->mstr->getFaceDirection() == "right"){
        if(!this->checkStongRight() && !this->checkFoodRight() && !this->checkDizzyAIRight()){
            this->mstr->spitOut();
            QTimer::singleShot(400,this,SLOT(mShrink()));
        }
        else if(this->checkStongRight()){
            this->mstr->eatingStone();
            this->stone[this->stoneIndex(this->mstr->getX()+1,this->mstr->getY())]->setPic(":/bg/pic/floor.png");
            this->t = this->stoneIndex(this->mstr->getX()+1,this->mstr->getY());
            qDebug() << this->t;
            this->flr[this->mstr->getX()+1][this->mstr->getY()]->setStone(false);
            this->mstr->setWithStone(true);
            QTimer::singleShot(400,this,SLOT(mShrink()));
        }
        else if(this->checkFoodRight()){
            emit this->signal_eatFood();
            hand->addscore();
            this->mstr->spitOut();
            this->flr[this->mstr->getX()+1][this->mstr->getY()]->setFood(false);
            delete food[this->foodIndex(this->mstr->getX()+1,this->mstr->getY())];
            QTimer::singleShot(400,this,SLOT(mShrink()));
        }
        else {
            emit this->signal_eatAI();
            hand->addscore();
            this->mstr->spitOut();
            this->flr[this->mstr->getX()+1][this->mstr->getY()]->setDizzyAI(false);
            this->ai[this->AIIndex(this->mstr->getX()+1,this->mstr->getY())]->die();
            QTimer::singleShot(400,this,SLOT(mShrink()));
            this->AINum--;
            if(this->AINum == 0) {
                emit signal_victory();
                this->mstr->setPic(":/monster/pic/victory.png");
            }
        }
    }
}

void MyScene::mSpitOutStone()
{
    if(this->mstr->getFaceDirection() == "back"){
        if(this->mstr->getY() == 0 || this->checkStongUp()) return;
        else {
            qDebug() << t;
            this->stone[t]->setX(this->mstr->getX());
            this->stone[t]->setY(this->mstr->getY()-1);
            this->stone[t]->setPos(this->stone[t]->getX()*this->stone[t]->boundingRect().width(),this->stone[t]->getY()*this->stone[t]->boundingRect().height());
            this->flr[this->stone[t]->getX()][this->stone[t]->getY()]->setStone(true);
            this->stone[t]->setPic(":/bg/pic/stone_one_a.png");
            this->mstr->setWithStone(false);
            this->mstr->shrink();
            connect(this->timerStone,SIGNAL(timeout()),this,SLOT(sMoveUp()));
            this->timerStone->start(100);
        }
    }
    if(this->mstr->getFaceDirection() == "left"){
        if(this->mstr->getX() == 0 || this->checkStongLeft()) return;
        else {
            qDebug() << t;
            this->stone[t]->setX(this->mstr->getX()-1);
            this->stone[t]->setY(this->mstr->getY());
            this->stone[t]->setPos(this->stone[t]->getX()*this->stone[t]->boundingRect().width(),this->stone[t]->getY()*this->stone[t]->boundingRect().height());
            this->flr[this->stone[t]->getX()][this->stone[t]->getY()]->setStone(true);
            this->stone[t]->setPic(":/bg/pic/stone_one_a.png");
            this->mstr->setWithStone(false);
            this->mstr->shrink();
            connect(this->timerStone,SIGNAL(timeout()),this,SLOT(sMoveLeft()));
            this->timerStone->start(100);
        }
    }
    if(this->mstr->getFaceDirection() == "front"){
        if(this->mstr->getY() == 14 || this->checkStongDown()) return;
        else {
            qDebug() << t;
            this->stone[t]->setX(this->mstr->getX());
            this->stone[t]->setY(this->mstr->getY()+1);
            this->stone[t]->setPos(this->stone[t]->getX()*this->stone[t]->boundingRect().width(),this->stone[t]->getY()*this->stone[t]->boundingRect().height());
            this->flr[this->stone[t]->getX()][this->stone[t]->getY()]->setStone(true);
            this->stone[t]->setPic(":/bg/pic/stone_one_a.png");
            this->mstr->setWithStone(false);
            this->mstr->shrink();
            connect(this->timerStone,SIGNAL(timeout()),this,SLOT(sMoveDown()));
            this->timerStone->start(100);
        }
    }
    if(this->mstr->getFaceDirection() == "right"){
        if(this->mstr->getX() == 14 || this->checkStongRight()) return;
        else {
            qDebug() << t;
            this->stone[t]->setX(this->mstr->getX()+1);
            this->stone[t]->setY(this->mstr->getY());
            this->stone[t]->setPos(this->stone[t]->getX()*this->stone[t]->boundingRect().width(),this->stone[t]->getY()*this->stone[t]->boundingRect().height());
            this->flr[this->stone[t]->getX()][this->stone[t]->getY()]->setStone(true);
            this->stone[t]->setPic(":/bg/pic/stone_one_a.png");
            this->mstr->setWithStone(false);
            this->mstr->shrink();
            connect(this->timerStone,SIGNAL(timeout()),this,SLOT(sMoveRight()));
            this->timerStone->start(100);
        }
    }
}

void MyScene::mDie()
{
    if(this->flr[this->mstr->getX()][this->mstr->getY()]->isAI()){
        emit signal_defeat();
        this->mstr->setPic(":/monster/pic/defeat.png");
        this->mstr->setDead(true);
        disconnect(this->timerAI,SIGNAL(timeout()),this,SLOT(AIMove()));
    }

}

void MyScene::keyPressEvent(QKeyEvent *event)
{
    if(this->AINum != 0 && !this->mstr->isDead()){
        switch(event->key()) {
        case Qt::Key_Space:
            if(!this->mstr->isWithStone()) this->mEat();
            else this->mSpitOutStone();
            break;
        case Qt::Key_W:
            if(this->checkStongUp() || this->checkFoodUp() || this->checkDizzyAIUp()) this->mstr->turnUp();
            else this->mstr->moveUp();
            this->mDie();
            break;
        case Qt::Key_A:
            if(this->checkStongLeft() || this->checkFoodLeft() || this->checkDizzyAILeft()) this->mstr->turnLeft();
            else this->mstr->moveLeft();
            this->mDie();
            break;
        case Qt::Key_S:
            if(this->checkStongDown() || this->checkFoodDown() || this->checkDizzyAIDown()) this->mstr->turnDown();
            else this->mstr->moveDown();
            this->mDie();
            break;
        case Qt::Key_D:
            if(this->checkStongRight() || this->checkFoodRight() || this->checkDizzyAIRight()) this->mstr->turnRight();
            else this->mstr->moveRight();
            this->mDie();
            break;
        }
    }
    else event->ignore();
}
