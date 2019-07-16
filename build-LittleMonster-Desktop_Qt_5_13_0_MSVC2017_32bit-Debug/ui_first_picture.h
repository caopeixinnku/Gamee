/********************************************************************************
** Form generated from reading UI file 'first_picture.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRST_PICTURE_H
#define UI_FIRST_PICTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_first_picture
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *first_picture)
    {
        if (first_picture->objectName().isEmpty())
            first_picture->setObjectName(QString::fromUtf8("first_picture"));
        first_picture->resize(800, 600);
        first_picture->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(first_picture);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 421, 231));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/thefirstone.png);"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 181, 61, 20));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/start.png);"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 180, 61, 21));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/monster/pic/help.png);"));
        first_picture->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(first_picture);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 17));
        first_picture->setMenuBar(menuBar);
        mainToolBar = new QToolBar(first_picture);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        first_picture->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(first_picture);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        first_picture->setStatusBar(statusBar);

        retranslateUi(first_picture);

        QMetaObject::connectSlotsByName(first_picture);
    } // setupUi

    void retranslateUi(QMainWindow *first_picture)
    {
        first_picture->setWindowTitle(QCoreApplication::translate("first_picture", "first_picture", nullptr));
#if QT_CONFIG(whatsthis)
        first_picture->setWhatsThis(QCoreApplication::translate("first_picture", "<html><head/><body><p><img src=\":/wtf_pictures/thefirstone.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class first_picture: public Ui_first_picture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRST_PICTURE_H
