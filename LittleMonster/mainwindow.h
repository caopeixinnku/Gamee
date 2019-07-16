#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "myscenen.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MyScene* getsc();

private slots:
    void catch_choose_signal();//接受到选关界面的信号
    void catch_gameover_signal();//接收到失败界面的信号
    void updatescore();//后加的，加分的槽函数
    void catch_victory_signal();//接收到胜利界面的信号
    void on_pushButton_clicked();
    void catch_pause_signal();


  signals:
    void sendpause();
private:
    Ui::MainWindow *ui;
    MyScene *sc;
    int score;//这个是后加的
};

#endif // MAINWINDOW_H
