#-------------------------------------------------
#
# Project created by QtCreator 2016-07-11T16:52:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += warn_off
TARGET = testwinhid
TEMPLATE = app

LIBS += -L$$PWD/./

LIBS += -lhid -lsetupapi
SOURCES += main.cpp\
        mainwindow.cpp \
    hiddevice.cpp \
    ../../signal11/windows/hid.c

HEADERS  += mainwindow.h \
    hiddevice.h \
    ../../signal11/hidapi/hidapi.h

FORMS    += \
    mainwindow.ui
