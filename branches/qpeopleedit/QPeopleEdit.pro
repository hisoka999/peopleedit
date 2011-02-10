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
    gauth.cpp \
    gcontacts.cpp \
    googlecontactdialog.cpp \
    googleloginform.cpp \
    googleupdateform.cpp

HEADERS  += mainwindow.h \
    sqlmodel.h \
    gauth.h \
    gcontacts.h \
    googlecontactdialog.h \
    googleloginform.h \
    googleupdateform.h

FORMS    += mainwindow.ui \
    googlecontactdialog.ui \
    googleloginform.ui \
    googleupdateform.ui

TRANSLATIONS = de.ts

RESOURCES += \
    resources.qrc
