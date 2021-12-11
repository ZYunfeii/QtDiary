#-------------------------------------------------
#
# Project created by QtCreator 2020-10-16T19:49:12
#
#-------------------------------------------------

QT       += core gui\
            sql

RC_FILE = exe_ico.rc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyDiary
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    userwindow.cpp \
    editwindow.cpp \
    diarylog.cpp \
    detailwindow.cpp \
    timelistwindow.cpp

HEADERS  += mainwindow.h \
    userwindow.h \
    editwindow.h \
    diarylog.h \
    detailwindow.h \
    timelistwindow.h

FORMS    += mainwindow.ui \
    userwindow.ui \
    editwindow.ui \
    diarylog.ui \
    detailwindow.ui \
    timelistwindow.ui

CONFIG += C++11

RESOURCES += \
    res.qrc

DISTFILES += \
    images/IMG_2.jpg

