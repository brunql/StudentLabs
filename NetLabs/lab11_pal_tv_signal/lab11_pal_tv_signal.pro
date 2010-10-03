# -------------------------------------------------
# Project created by QtCreator 2010-04-25T13:55:56
# -------------------------------------------------
QT += guie
CONFIG -= app_bundle
TEMPLATE = app
OBJECTS_DIR = ./obj
MOC_DIR = ./moc
INCLUDEPATH += ./inc
QMAKE_LIBDIR += ./lib
LIBS += -lqserialdevice
DESTDIR = ./build
TARGET = lab11_pal_tv_signal
SOURCES += main.cpp \
    mainwindow.cpp \
    cameradevice.cpp
HEADERS += inc/main.h \
    inc/mainwindow.h \
    inc/timeevaluations.h \
    inc/cameradevice.h
FORMS += mainwindow.ui
