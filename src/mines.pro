#-------------------------------------------------
#
# Project created by QtCreator 2013-12-04T12:35:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mines
TEMPLATE = app


SOURCES += main.cpp\
    GameControl.cpp \
    MainWindow.cpp \
    GameView.cpp \
    MinesModel.cpp

HEADERS  += \
    Mines.h \
    MinesModel.h \
    GameControl.h \
    MainWindow.h \
    GameView.h

OTHER_FILES +=

RESOURCES += \
    mines.qrc
