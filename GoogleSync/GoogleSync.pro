#-------------------------------------------------
#
# Project created by QtCreator 2011-02-28T15:12:04
#
#-------------------------------------------------

QT       += network xml gui

TARGET = GoogleSync
TEMPLATE = lib

DEFINES += GOOGLESYNC_LIBRARY

SOURCES += \
    googleupdateform.cpp \
    googleloginform.cpp \
    googlecontactdialog.cpp \
    gcontacts.cpp \
    gauth.cpp \
    googlesync.cpp

HEADERS +=\
        GoogleSync_global.h \
    googleupdateform.h \
    googleloginform.h \
    googlecontactdialog.h \
    gcontacts.h \
    gauth.h \
    googlesync.h

OTHER_FILES +=

FORMS += \
    googleupdateform.ui \
    googleloginform.ui \
    googlecontactdialog.ui
