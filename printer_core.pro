#-------------------------------------------------
#
# Project created by QtCreator 2016-08-16T20:52:35
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = printer_core
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -L/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/lib -lmraa
LIBS += -L/opt/poky-edison/1.7.3/sysroots/core2-32-poky-linux/usr/lib -lQtDBusE

SOURCES += main.cpp \
    printer_core.cpp \
    core_adaptor.cpp

HEADERS += \
    printer_core.h \
    core_adaptor.h \
    error_num.h

OTHER_FILES += \
    printer_core.xml
