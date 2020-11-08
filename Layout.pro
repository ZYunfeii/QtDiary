#-------------------------------------------------
#
# Project created by QtCreator 2020-10-16T19:49:12
#
#-------------------------------------------------

QT       += core gui\
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Layout
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    userwindow.cpp \
    editwindow.cpp \
    diarylog.cpp

HEADERS  += mainwindow.h \
    userwindow.h \
    editwindow.h \
    diarylog.h

FORMS    += mainwindow.ui \
    userwindow.ui \
    editwindow.ui \
    diarylog.ui

CONFIG += C++11

RESOURCES += \
    res.qrc

DISTFILES += \
    images/IMG_2.jpg

