#-------------------------------------------------
#
# Project created by QtCreator 2014-10-02T21:22:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WRGui
TEMPLATE = app
CONFIG += c++17


SOURCES += main.cpp\
        mainwindow.cpp \
    ../WRTest/rabbit.cpp \
    ../WRTest/field.cpp \
    ../WRTest/creature.cpp \
    ../WRTest/coords.cpp \
    ../WRTest/cell.cpp \
    ../WRTest/randomgenerator.cpp \
    ../WRTest/wolf.cpp

HEADERS  += mainwindow.hpp \
    ../WRTest/field.hpp \
    ../WRTest/defs.hpp \
    ../WRTest/creature.hpp \
    ../WRTest/coords.hpp \
    ../WRTest/cell.hpp \
    ../WRTest/rabbit.hpp \
    ../WRTest/randomgenerator.hpp \
    ../WRTest/wolf.hpp

FORMS    += mainwindow.ui

#QMAKE_CXXFLAGS += -std=c++17
