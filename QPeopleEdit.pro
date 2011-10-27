#-------------------------------------------------
#
# Project created by QtCreator 2011-01-13T12:24:17
#
#-------------------------------------------------

QT       += core gui \
         sql\
         network

TARGET = QPeopleEdit
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    sqlmodel.cpp \
    pluginloader.cpp \
    vcard.cpp

HEADERS  += mainwindow.h \
    sqlmodel.h \
    pluginloader.h \
    vcard.h

FORMS    += mainwindow.ui

TRANSLATIONS = de.ts

RESOURCES += \
    resources.qrc
