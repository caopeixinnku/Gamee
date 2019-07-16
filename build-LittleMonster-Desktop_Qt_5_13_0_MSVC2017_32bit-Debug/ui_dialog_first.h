/********************************************************************************
** Form generated from reading UI file 'dialog_first.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FIRST_H
#define UI_DIALOG_FIRST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_first
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog_first)
    {
        if (Dialog_first->objectName().isEmpty())
            Dialog_first->setObjectName(QString::fromUtf8("Dialog_first"));
        Dialog_first->resize(640, 520);
        graphicsView = new QGraphicsView(Dialog_first);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(30, 30, 521, 421));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/thefirstone.png);"));
        pushButton = new QPushButton(Dialog_first);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 360, 76, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/start.png);"));
        pushButton_2 = new QPushButton(Dialog_first);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 360, 76, 41));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/help.png);"));

        retranslateUi(Dialog_first);

        QMetaObject::connectSlotsByName(Dialog_first);
    } // setupUi

    void retranslateUi(QDialog *Dialog_first)
    {
        Dialog_first->setWindowTitle(QCoreApplication::translate("Dialog_first", "Dialog", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog_first: public Ui_Dialog_first {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FIRST_H
