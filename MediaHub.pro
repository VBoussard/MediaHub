#-------------------------------------------------
#
# Project created by QtCreator 2016-10-03T10:20:30
#
#-------------------------------------------------

QT       += core gui
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MediaHub
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addstream.cpp \
    engine.cpp \
    stream.cpp \
    serverwin.cpp \
    thumbnail.cpp \
    player.cpp

HEADERS  += mainwindow.h \
    addstream.h \
    engine.h \
    stream.h \
    serverwin.h \
    thumbnail.h \
    player.h

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

RESOURCES += \
    Src.qrc
