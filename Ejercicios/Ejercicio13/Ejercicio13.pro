QT += core gui widgets network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
CONFIG += c++11
SOURCES += main.cpp \
           login.cpp \
           ventana.cpp
HEADERS += login.h \
           ventana.h
