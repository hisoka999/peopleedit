#ifndef GOOGLESYNC_GLOBAL_H
#define GOOGLESYNC_GLOBAL_H

#include <QtCore/qglobal.h>
#if defined(GOOGLESYNC_LIBRARY)
#  define GOOGLESYNCSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GOOGLESYNCSHARED_EXPORT Q_DECL_IMPORT
#endif
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <googlecontactdialog.h>
extern "C" int ddd()
{
    GoogleContactDialog *dialog = new GoogleContactDialog();
    dialog->show();
    return 0;
}

extern "C" QString getPluginName()
{
    return QString("GoogleSync");
}

extern "C" void setTitleBar(QMainWindow *window)
{
    QMenu *m = window->menuBar()->findChild<QMenu*>(QString("menuSync"));
    if(m!=NULL)
    {
        QAction *action = new QAction("Google Contact Sync",NULL);
        action->setObjectName(getPluginName());
        m->addAction(action);
    }
}

#endif // GOOGLESYNC_GLOBAL_H
