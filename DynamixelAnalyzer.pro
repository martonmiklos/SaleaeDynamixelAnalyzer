#-------------------------------------------------
#
# Project created by QtCreator 2016-11-04T09:29:07
#
#-------------------------------------------------

QT       -= core gui

TARGET = DynamixelAnalyzer
TEMPLATE = lib


OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
RCC_DIR = build

DESTDIR = bin

CONFIG += DEBUG
CONFIG += plugin


DEFINES += DYNAMIXEL_ANALYZER_LIBRARY


INCLUDEPATH += $$PWD/AnalyzerSDK/include
LIBS += -L$$PWD/AnalyzerSDK/lib

macx: {
    target.path = /Applications/Logic.app/Contents/Resources/Analyzers
    INSTALLS += target
    LIBS += -lc++
    LIBS += -lAnalyzer
}

unix:!macx {
    target.path = /usr/lib
    INSTALLS += target

    LIBS += -lAnalyzer64
}

win32 {
    CONFIG += dll
    target.path = "C:\\Program Files\\Saleae Inc\\Analyzers"
    INSTALLS += target

    !contains(QMAKE_TARGET.arch, x86_64) {
        LIBS += -lAnalyzer
    } else {
        LIBS += -lAnalyzer64
    }
}

HEADERS += \
    DynamixelAnalyzer.h \
    DynamixelAnalyzerResults.h \
    DynamixelAnalyzerSettings.h \
    DynamixelSimulationDataGenerator.h

SOURCES += \
    DynamixelAnalyzer.cpp \
    DynamixelAnalyzerResults.cpp \
    DynamixelAnalyzerSettings.cpp \
    DynamixelSimulationDataGenerator.cpp

