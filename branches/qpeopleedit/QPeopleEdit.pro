#-------------------------------------------------
#
# Project created by QtCreator 2011-01-13T12:24:17
#
#-------------------------------------------------

QT       += core gui \
         sql\
         network\
         xml

TARGET = QPeopleEdit
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    sqlmodel.cpp \
    pluginloader.cpp \
    vcard.cpp \
    freedesktopmime.cpp

HEADERS  += mainwindow.h \
    sqlmodel.h \
    pluginloader.h \
    vcard.h \
    freedesktopmime.h

FORMS    += mainwindow.ui

TRANSLATIONS = de.ts

RESOURCES += \
    resources.qrc