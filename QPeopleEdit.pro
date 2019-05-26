#-------------------------------------------------
#
# Project created by QtCreator 2011-01-13T12:24:17
#
#-------------------------------------------------

QT       += core gui widgets\
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
    freedesktopmime.cpp \
    optionsdialog.cpp

HEADERS  += mainwindow.h \
    sqlmodel.h \
    pluginloader.h \
    vcard.h \
    freedesktopmime.h \
    optionsdialog.h

FORMS    += mainwindow.ui \
    optionsdialog.ui

TRANSLATIONS = de.ts

RESOURCES += \
    resources.qrc
