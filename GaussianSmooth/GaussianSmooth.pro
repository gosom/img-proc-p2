#-------------------------------------------------
#
# Project created by QtCreator 2014-12-06T19:19:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GaussianSmooth
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imgloader.cpp \
    fgaussian.cpp \
    utils.cpp \
    imgwarp.cpp \
    warpsettingsdialog.cpp

HEADERS  += mainwindow.h \
    imgloader.h \
    fgaussian.h \
    utils.h \
    imgwarp.h \
    warpsettingsdialog.h

FORMS    += mainwindow.ui \
    warpsettingsdialog.ui

QMAKE_CXXFLAGS += -std=c++11

LIBS += -lfftw3
