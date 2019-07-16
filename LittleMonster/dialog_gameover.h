#ifndef DIALOG_GAMEOVER_H
#define DIALOG_GAMEOVER_H

#include <QDialog>

namespace Ui {
class dialog_gameover;
}

class dialog_gameover : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_gameover(QWidget *parent = nullptr);
    ~dialog_gameover();

private slots:
    void on_pushButton_clicked();//返回

    void on_pushButton_2_clicked();//重玩

    void receive_gameover();//游戏失败
 signals:
    void returntochoose();
    void returntomain();
private:
    Ui::dialog_gameover *ui;
};

#endif // DIALOG_GAMEOVER_H
