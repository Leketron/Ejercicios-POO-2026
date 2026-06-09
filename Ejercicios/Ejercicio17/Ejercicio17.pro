QT += core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
CONFIG += c++11
SOURCES += main.cpp \
           boton.cpp \
           ventana.cpp
HEADERS += boton.h \
           ventana.h
