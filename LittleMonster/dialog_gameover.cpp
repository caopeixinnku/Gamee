#include "dialog_gameover.h"
#include "ui_dialog_gameover.h"

dialog_gameover::dialog_gameover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_gameover)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
}

dialog_gameover::~dialog_gameover()
{
    delete ui;
}

void dialog_gameover::on_pushButton_clicked()//返回
{
    this->hide();
    emit returntochoose();
}

void dialog_gameover::on_pushButton_2_clicked()//重玩
{
    this->hide();
    emit returntomain();
}
void dialog_gameover::receive_gameover()//接受失败的信号
{
    this->show();
}
