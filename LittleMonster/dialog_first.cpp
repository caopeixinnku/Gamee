#include "dialog_first.h"
#include "ui_dialog_first.h"

Dialog_first::Dialog_first(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_first)
{
    ui->setupUi(this);
     this->setWindowIcon(QIcon(":/monster/pic/favicon-happymonster.ico"));
}

Dialog_first::~Dialog_first()
{
    delete ui;
}

void Dialog_first::on_pushButton_clicked()
{
    this->hide();
     emit showchoose();
}

void Dialog_first::on_pushButton_2_clicked()
{
    this->hide();
     emit showhelper();
}
void Dialog_first::receivesignal()
{
    this->show();
}
void Dialog_first::receivehelpsignal()
{
    this->show();
}
