/********************************************************************************
** Form generated from reading UI file 'dialog_victory.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_VICTORY_H
#define UI_DIALOG_VICTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_victory
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog_victory)
    {
        if (Dialog_victory->objectName().isEmpty())
            Dialog_victory->setObjectName(QString::fromUtf8("Dialog_victory"));
        Dialog_victory->resize(421, 271);
        graphicsView = new QGraphicsView(Dialog_victory);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 421, 271));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/victory_2.png);"));
        pushButton = new QPushButton(Dialog_victory);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 240, 41, 16));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/return_back.png);"));
        pushButton_2 = new QPushButton(Dialog_victory);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 240, 41, 16));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/replay.png);"));

        retranslateUi(Dialog_victory);

        QMetaObject::connectSlotsByName(Dialog_victory);
    } // setupUi

    void retranslateUi(QDialog *Dialog_victory)
    {
        Dialog_victory->setWindowTitle(QCoreApplication::translate("Dialog_victory", "Dialog", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog_victory: public Ui_Dialog_victory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_VICTORY_H
