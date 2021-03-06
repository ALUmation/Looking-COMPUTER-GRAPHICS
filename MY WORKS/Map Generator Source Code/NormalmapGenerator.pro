QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NormalMAP Generator
TEMPLATE = app

QMAKE_CXXFLAGS += -fopenmp -std=c++11
LIBS += -fopenmp

SOURCES += main.cpp\
        src_gui/mainwindow.cpp \
    src_generators/intensitymap.cpp \
    src_generators/normalmapgenerator.cpp \
    src_generators/specularmapgenerator.cpp \
    src_gui/graphicsscene.cpp \
    src_gui/graphicsview.cpp \
    src_gui/queueitem.cpp \
    src_gui/queuemanager.cpp \
    src_generators/gaussianblur.cpp \
    src_generators/boxblur.cpp \
    src_generators/ssaogenerator.cpp \
    src_gui/aboutdialog.cpp \
    src_gui/listwidget.cpp

HEADERS  += src_gui/mainwindow.h \
    src_generators/intensitymap.h \
    src_generators/normalmapgenerator.h \
    src_generators/specularmapgenerator.h \
    src_gui/graphicsscene.h \
    src_gui/graphicsview.h \
    src_gui/queueitem.h \
    src_gui/queuemanager.h \
    src_generators/gaussianblur.h \
    src_generators/boxblur.h \
    src_generators/ssaogenerator.h \
    src_gui/aboutdialog.h \
    src_gui/listwidget.h \
    src_gui/clickablelabel.h

FORMS    += src_gui/mainwindow.ui \
    src_gui/aboutdialog.ui

win32:RC_FILE = resources.rc

RESOURCES += \
    stylesheets.qrc

target.path = /usr/local/bin
INSTALLS += target
