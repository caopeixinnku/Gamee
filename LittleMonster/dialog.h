#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void get_first_signal();

    void receivegameover();//收到失败界面的返回信号

    void get_pause_signal();

    void get_victory_signal();//接收到胜利界面的信号
signals:
    void backtofirst();//返回到开始界面的信号
    void  firscene();//跳转到第一界面的信号
    void  secscene();//跳转到第二界面的信号
    void  thiscene();//跳转到第三界面的信号

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
