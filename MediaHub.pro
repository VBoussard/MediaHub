#-------------------------------------------------
#
# Project created by QtCreator 2016-10-03T10:20:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MediaHub
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addstream.cpp \
    configin.cpp \
    configout.cpp \
    engine.cpp \
    stream.cpp \
    serverwin.cpp

HEADERS  += mainwindow.h \
    addstream.h \
    configin.h \
    configout.h \
    engine.h \
    stream.h \
    serverwin.h

mac {
    QT += opengl
    SOURCES += glwidget.cpp
    HEADERS += glwidget.h
}
win32 {
    INCLUDEPATH += include/mlt++ include/mlt
    LIBS += -Llib -lmlt++ -lmlt
} else {
    CONFIG += link_pkgconfig
    PKGCONFIG += mlt++
}

FORMS    +=
