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

SOURCES += main.cpp\
        mainwindow.cpp \
    hiddevice.cpp

HEADERS  += mainwindow.h \
    hiddevice.h \
    ../../signal11/hidapi/hidapi.h

FORMS    += \
    mainwindow.ui
unix {
#sudo apt-get install libudev-dev
LIBS += -L/usr/lib/i386-linux-gnu/ -ludev
SOURCES += ../../signal11/linux/hid.c

}
win32 {
LIBS += -L$$PWD/./
LIBS += -lhid
LIBS +=-lsetupapi
SOURCES += ../../signal11/windows/hid.c
}
