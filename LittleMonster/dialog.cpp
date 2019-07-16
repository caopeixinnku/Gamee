#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
     this->setWindowIcon(QIcon(":/monster/pic/favicon-happymonster.ico"));

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::get_first_signal()
{
    this->show();//显示选关界面
}
void Dialog:: get_pause_signal()
{
    this->show();
}
void Dialog::get_victory_signal()
{
    this->show();
}


void Dialog::on_pushButton_2_clicked()
{
      this->hide();
        emit firscene();
}

void Dialog::on_pushButton_3_clicked()
{

}

void Dialog::on_pushButton_4_clicked()
{

}

void Dialog::on_pushButton_clicked()//返回键
{
    this->hide();
    emit backtofirst();
}
void Dialog::receivegameover()
{
    this->show();
}
