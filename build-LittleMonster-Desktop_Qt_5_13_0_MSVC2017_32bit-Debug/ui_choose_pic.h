/********************************************************************************
** Form generated from reading UI file 'choose_pic.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSE_PIC_H
#define UI_CHOOSE_PIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_choose_pic
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *choose_pic)
    {
        if (choose_pic->objectName().isEmpty())
            choose_pic->setObjectName(QString::fromUtf8("choose_pic"));
        choose_pic->resize(800, 600);
        choose_pic->setCursor(QCursor(Qt::UpArrowCursor));
        centralwidget = new QWidget(choose_pic);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 521, 321));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/thefirstone.png);"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(60, 40, 421, 271));
        textBrowser->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/choose_which.png);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 280, 51, 21));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/return_back.png);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 150, 60, 60));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/1.png);"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 150, 60, 60));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/2.png);"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(360, 150, 60, 60));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/3.png);"));
        choose_pic->setCentralWidget(centralwidget);
        menubar = new QMenuBar(choose_pic);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        choose_pic->setMenuBar(menubar);
        statusbar = new QStatusBar(choose_pic);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        choose_pic->setStatusBar(statusbar);

        retranslateUi(choose_pic);

        QMetaObject::connectSlotsByName(choose_pic);
    } // setupUi

    void retranslateUi(QMainWindow *choose_pic)
    {
        choose_pic->setWindowTitle(QCoreApplication::translate("choose_pic", "MainWindow", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class choose_pic: public Ui_choose_pic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSE_PIC_H
