#include "dialog_pause.h"
#include "ui_dialog_pause.h"

Dialog_pause::Dialog_pause(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_pause)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
}

Dialog_pause::~Dialog_pause()
{
    delete ui;
}

void Dialog_pause::on_pushButton_return_clicked()
{
  this->hide();
    emit  returntothechoose();
    emit returntothemain();
}

void Dialog_pause::on_pushButton_goon_clicked()
{
  this->hide();
    emit returntothemain();

}
void Dialog_pause::reveivethepause()
{
    this->show();//暂停界面显示
}
