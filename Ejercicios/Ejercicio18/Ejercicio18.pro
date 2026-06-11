QT += core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
CONFIG += c++11
SOURCES += main.cpp \
           trex.cpp \
           pajaro.cpp \
           juego.cpp
HEADERS += trex.h \
           pajaro.h \
           juego.h
