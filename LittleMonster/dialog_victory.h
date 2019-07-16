#ifndef DIALOG_VICTORY_H
#define DIALOG_VICTORY_H

#include <QDialog>

namespace Ui {
class Dialog_victory;
}

class Dialog_victory : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_victory(QWidget *parent = nullptr);
    ~Dialog_victory();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void receive_victory();
signals:
    void returntothechoosepic();
    void replaythegame();
private:
    Ui::Dialog_victory *ui;
};

#endif // DIALOG_VICTORY_H
