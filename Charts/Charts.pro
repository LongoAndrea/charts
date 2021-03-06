#-------------------------------------------------
#
# Project created by QtCreator 2022-01-10T15:45:53
#
#-------------------------------------------------

QT       += core gui
QT += charts
QT += xml


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Charts
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    matrix.cpp \    
    myareachart.cpp \
    mybarchart.cpp \
    mycontroller.cpp \
    mylinebarchart.cpp \
    mylinechart.cpp \
    myradarchart.cpp \    
    xmlloader.cpp \
    mymodel.cpp \
    myview.cpp \
    standardinputdialog.cpp \
    dateinputdialog.cpp \
    drilldownchart.cpp \
    drilldownslice.cpp \
    mypiechart.cpp

HEADERS += \
    matrix.h \
    myabstractchart.h \
    myabstractdatechart.h \
    myareachart.h \
    mybarchart.h \
    mycontroller.h \
    mylinebarchart.h \
    mylinechart.h \
    myradarchart.h \
    loader.h \
    xmlloader.h \
    mymodel.h \
    myview.h \
    standardinputdialog.h \
    dateinputdialog.h \
    drilldownchart.h \
    drilldownslice.h \
    mypiechart.h
