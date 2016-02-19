#-------------------------------------------------
#
# Project created by QtCreator 2016-01-23T17:37:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mynotepad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    about.h

FORMS    += mainwindow.ui \
    about.ui

RESOURCES += \
    res.qrc
RC_FILE = myapp.rc

QT +=  multimedia
CONFIG += qaxcontainer
