QT += core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
CONFIG += c++11
SOURCES += main.cpp \
           login.cpp \
           formulario.cpp
HEADERS += login.h \
           formulario.h
