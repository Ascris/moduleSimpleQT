######################################################################
# Automatically generated by qmake (3.0) ven. mars 11 14:48:00 2016
######################################################################

TEMPLATE = app
TARGET = "Projet 2015-2016"
INCLUDEPATH += .
QT += widgets
LIBS += -lfl
QMAKE_CC = g++
CONFIG += c++11


# Input
HEADERS += global.h monDessin.h parser.tab.hpp Figure.hpp Option.hpp Rectangle.hpp Cercle.hpp Ligne.hpp
SOURCES += lex.yy.c parser.tab.cpp main.cpp monDessin.cpp Figure.cpp Option.cpp Rectangle.cpp Cercle.cpp Ligne.cpp