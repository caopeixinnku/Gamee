#ifndef DIALOG_PAUSE_H
#define DIALOG_PAUSE_H

#include <QDialog>

namespace Ui {
class Dialog_pause;
}

class Dialog_pause : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_pause(QWidget *parent = nullptr);
    ~Dialog_pause();

private slots:
    void on_pushButton_return_clicked();

    void on_pushButton_goon_clicked();

    void reveivethepause();
signals:
    void returntothemain();
    void returntothechoose();
    void closemain();
private:
    Ui::Dialog_pause *ui;
};

#endif // DIALOG_PAUSE_H
