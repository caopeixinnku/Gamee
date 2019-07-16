#include "dialog_victory.h"
#include "ui_dialog_victory.h"

Dialog_victory::Dialog_victory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_victory)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
}

Dialog_victory::~Dialog_victory()
{
    delete ui;
}

void Dialog_victory::on_pushButton_clicked()//返回
{
    this->hide();
    emit returntothechoosepic();
}

void Dialog_victory::on_pushButton_2_clicked()//重玩
{
    this->hide();
    emit replaythegame();
}
void Dialog_victory::receive_victory()//接收到胜利的信号
{
    this->show();
}
