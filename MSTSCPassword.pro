#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T12:02:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MSTSCPassword
TEMPLATE = app

HEADERS  += passwordgeneratorwin.h

SOURCES += main.cpp\
        passwordgeneratorwin.cpp

FORMS    += passwordgeneratorwin.ui

LIBS +=  -lCrypt32
