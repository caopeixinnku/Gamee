#include "dialog_help.h"
#include "ui_dialog_help.h"

Dialog_help::Dialog_help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_help)
{
    ui->setupUi(this);
     this->setWindowIcon(QIcon(":/monster/pic/favicon-happymonster.ico"));
}

Dialog_help::~Dialog_help()
{
    delete ui;
}

void Dialog_help::turntohelper()
{
  this->show();//显示帮助界面
}
void Dialog_help::on_pushButton_clicked()
{
    this->hide();
    emit turnbacktofir();
}

