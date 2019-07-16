/********************************************************************************
** Form generated from reading UI file 'dialog_gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_GAMEOVER_H
#define UI_DIALOG_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_dialog_gameover
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *dialog_gameover)
    {
        if (dialog_gameover->objectName().isEmpty())
            dialog_gameover->setObjectName(QString::fromUtf8("dialog_gameover"));
        dialog_gameover->resize(421, 271);
        textBrowser = new QTextBrowser(dialog_gameover);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 421, 271));
        textBrowser->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/gameover_dialog.png);"));
        pushButton = new QPushButton(dialog_gameover);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 240, 41, 16));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/return_back.png);"));
        pushButton_2 = new QPushButton(dialog_gameover);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(315, 240, 41, 16));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/replay.png);"));

        retranslateUi(dialog_gameover);

        QMetaObject::connectSlotsByName(dialog_gameover);
    } // setupUi

    void retranslateUi(QDialog *dialog_gameover)
    {
        dialog_gameover->setWindowTitle(QCoreApplication::translate("dialog_gameover", "Dialog", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dialog_gameover: public Ui_dialog_gameover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_GAMEOVER_H
