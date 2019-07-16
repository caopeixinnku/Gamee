/********************************************************************************
** Form generated from reading UI file 'dialog_pause.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_PAUSE_H
#define UI_DIALOG_PAUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_pause
{
public:
    QGraphicsView *graphicsView_pause;
    QPushButton *pushButton_goon;
    QPushButton *pushButton_return;

    void setupUi(QDialog *Dialog_pause)
    {
        if (Dialog_pause->objectName().isEmpty())
            Dialog_pause->setObjectName(QString::fromUtf8("Dialog_pause"));
        Dialog_pause->resize(431, 351);
        graphicsView_pause = new QGraphicsView(Dialog_pause);
        graphicsView_pause->setObjectName(QString::fromUtf8("graphicsView_pause"));
        graphicsView_pause->setGeometry(QRect(0, 0, 431, 351));
        graphicsView_pause->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/pause.png);"));
        pushButton_goon = new QPushButton(Dialog_pause);
        pushButton_goon->setObjectName(QString::fromUtf8("pushButton_goon"));
        pushButton_goon->setGeometry(QRect(321, 314, 41, 16));
        pushButton_goon->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_goon->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/goon.png);"));
        pushButton_return = new QPushButton(Dialog_pause);
        pushButton_return->setObjectName(QString::fromUtf8("pushButton_return"));
        pushButton_return->setGeometry(QRect(43, 314, 41, 16));
        pushButton_return->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_return->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/return_back.png);"));

        retranslateUi(Dialog_pause);

        QMetaObject::connectSlotsByName(Dialog_pause);
    } // setupUi

    void retranslateUi(QDialog *Dialog_pause)
    {
        Dialog_pause->setWindowTitle(QCoreApplication::translate("Dialog_pause", "Dialog", nullptr));
        pushButton_goon->setText(QString());
        pushButton_return->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog_pause: public Ui_Dialog_pause {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_PAUSE_H
