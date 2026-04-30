#-------------------------------------------------
#
# Project created by QtCreator 2022-10-18T23:30:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = embdADCDataGatheringQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    adc.h

FORMS    += mainwindow.ui

RESOURCES += \
    pic.qrc
