/********************************************************************************
** Form generated from reading UI file 'dialog_help.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_HELP_H
#define UI_DIALOG_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_help
{
public:
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog_help)
    {
        if (Dialog_help->objectName().isEmpty())
            Dialog_help->setObjectName(QString::fromUtf8("Dialog_help"));
        Dialog_help->resize(640, 520);
        graphicsView_2 = new QGraphicsView(Dialog_help);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(60, 50, 431, 351));
        graphicsView_2->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/playerhelp.png);"));
        graphicsView = new QGraphicsView(Dialog_help);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(30, 30, 521, 421));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/thefirstone.png);"));
        pushButton = new QPushButton(Dialog_help);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(255, 365, 41, 20));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/return_back.png);"));
        graphicsView->raise();
        graphicsView_2->raise();
        pushButton->raise();

        retranslateUi(Dialog_help);

        QMetaObject::connectSlotsByName(Dialog_help);
    } // setupUi

    void retranslateUi(QDialog *Dialog_help)
    {
        Dialog_help->setWindowTitle(QCoreApplication::translate("Dialog_help", "Dialog", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog_help: public Ui_Dialog_help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_HELP_H
