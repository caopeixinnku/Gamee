#-------------------------------------------------
#
# Project created by QtCreator 2019-07-05T19:46:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LittleMonster
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        ai.cpp \
        background.cpp \
        dialog.cpp \
        dialog_first.cpp \
        dialog_gameover.cpp \
        dialog_help.cpp \
        dialog_pause.cpp \
        dialog_victory.cpp \
        floor.cpp \
        food.cpp \
        handler.cpp \
        main.cpp \
        mainwindow.cpp \
        mymonster.cpp \
        myscenen.cpp \
        stone.cpp

HEADERS += \
        ai.h \
        background.h \
        dialog.h \
        dialog_first.h \
        dialog_gameover.h \
        dialog_help.h \
        dialog_pause.h \
        dialog_victory.h \
        floor.h \
        food.h \
        handler.h \
        mainwindow.h \
        mymonster.h \
        myscenen.h \
        stone.h

FORMS += \
        dialog.ui \
        dialog_first.ui \
        dialog_gameover.ui \
        dialog_help.ui \
        dialog_pause.ui \
        dialog_victory.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
