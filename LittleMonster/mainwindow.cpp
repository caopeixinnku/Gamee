#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"handler.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc = new MyScene;
    this->ui->graphicsView->setScene(this->sc);
     this->setWindowIcon(QIcon(":/monster/pic/favicon-happymonster.ico"));

    this->score=0;//后加
    handler *hand=handler::getInstance();
    connect(hand,SIGNAL(eatfoodorai()),this,SLOT(updatescore()));
}
void MainWindow::catch_choose_signal()
{
    this->show();
}
void MainWindow::catch_gameover_signal()
{
    this->show();
}
void MainWindow::catch_victory_signal()
{
    this->show();
}

void MainWindow::updatescore()
{
    this->score+=100;
    this->ui->lcdNumber->display(this->score);
}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()//暂停键
{
    emit sendpause();
}
void MainWindow::catch_pause_signal()
{
    this->hide();
}
MyScene* MainWindow::getsc()
{
    return this->sc;
}
