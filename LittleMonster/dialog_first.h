#ifndef DIALOG_FIRST_H
#define DIALOG_FIRST_H

#include <QDialog>

namespace Ui {
class Dialog_first;
}

class Dialog_first : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_first(QWidget *parent = nullptr);
    ~Dialog_first();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void receivesignal();//收到选关界面的信号
    void receivehelpsignal();//收到帮助界面的信号

signals:
    void showchoose();//与选关卡界面相连接的信号
    void showhelper();//与帮助界面相连接的信号
private:
    Ui::Dialog_first *ui;
};

#endif // DIALOG_FIRST_H
