QT += core
QT -= gui

CONFIG += c++11

TARGET = ArvoreBinariaProjeto
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    No.cpp \
    ArvoreBinaria.cpp

HEADERS += \
    No.h \
    ArvoreBinaria.h \
    iarvorebinaria.h
