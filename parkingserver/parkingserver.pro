#-------------------------------------------------
#
# Project created by QtCreator 2016-09-19T23:04:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += widgets serialport
QT += location
QT += qml

TARGET = parkingserver
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

RESOURCES += qml.qrc \
    qml.qrc

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RC_ICONS += 327984.ico

DISTFILES += \
    main.qml
