#-------------------------------------------------
#
# Project created by QtCreator 2015-06-15T06:09:44
#
#-------------------------------------------------

QT       += core gui network qml quick quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pellegrino
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    httprequest.cpp

HEADERS  += mainwindow.h \
    httprequest.h

FORMS    += mainwindow.ui

DISTFILES += \
    ExplorerQmlForm.qml

RESOURCES += \
    resources.qrc
