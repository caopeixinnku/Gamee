#ifndef DIALOG_HELP_H
#define DIALOG_HELP_H

#include <QDialog>

namespace Ui {
class Dialog_help;
}

class Dialog_help : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_help(QWidget *parent = nullptr);
    ~Dialog_help();

private slots:
    void on_pushButton_clicked();
    void turntohelper();

signals:
    void turnbacktofir();//从帮助返回到开始界面
private:
    Ui::Dialog_help *ui;
};

#endif // DIALOG_HELP_H
