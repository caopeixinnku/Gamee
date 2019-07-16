/********************************************************************************
** Form generated from reading UI file 'playerhelping.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERHELPING_H
#define UI_PLAYERHELPING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playerhelping
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *playerhelping)
    {
        if (playerhelping->objectName().isEmpty())
            playerhelping->setObjectName(QString::fromUtf8("playerhelping"));
        playerhelping->resize(800, 600);
        centralwidget = new QWidget(playerhelping);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 10, 521, 321));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/thefirstone.png);"));
        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(60, 40, 421, 271));
        graphicsView_2->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/playerhelp.png);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 280, 41, 20));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/return_back.png);"));
        playerhelping->setCentralWidget(centralwidget);
        menubar = new QMenuBar(playerhelping);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        playerhelping->setMenuBar(menubar);
        statusbar = new QStatusBar(playerhelping);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        playerhelping->setStatusBar(statusbar);

        retranslateUi(playerhelping);

        QMetaObject::connectSlotsByName(playerhelping);
    } // setupUi

    void retranslateUi(QMainWindow *playerhelping)
    {
        playerhelping->setWindowTitle(QCoreApplication::translate("playerhelping", "MainWindow", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class playerhelping: public Ui_playerhelping {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERHELPING_H
