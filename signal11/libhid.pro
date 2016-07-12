TEMPLATE = lib
CONFIG += console
CONFIG += staticlib

CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    windows/hid.c
HEADERS += \
    hidapi/hidapi.h
