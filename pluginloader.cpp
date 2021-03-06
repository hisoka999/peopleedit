#include "pluginloader.h"
#include <QDir>
#include <QMainWindow>
#include <QDebug>

PluginLoader::PluginLoader(QWidget *parent, QString path)
{
    this->parent = parent;
    QDir dir(path);
    if(dir.exists())
    {
        QStringList filters;
        filters<<"*.so"<<"*.dll";
        QStringList list = dir.entryList(filters);
        for(int i = 0;i< list.size();++i)
        {
            qDebug()<<(path+QDir::separator()+list.at(i));
            loadPlugin(path+QDir::separator()+list.at(i));
        }
    }
}

void PluginLoader::loadPlugin(QString path)
{
    QLibrary *lib = new QLibrary(path);
    lib->load();
    typedef QString(*GetNameFunction)();
    typedef void(*SetTitleBar)(QMainWindow*);
    QMainWindow *win = static_cast<QMainWindow*>(parent);
    GetNameFunction getName = (GetNameFunction) lib->resolve("getPluginName");
    if(getName)
    {
        QString name=getName();
        libs[name]=lib;
        qDebug()<<"PluginName: "<<name;
        //setTitleBar
        SetTitleBar setTitleBar = (SetTitleBar) lib->resolve("setTitleBar");
        if(setTitleBar)
            setTitleBar(win);

    }
}

bool PluginLoader::exec(QString plugin)
{
    typedef int(*ExecFuntion)();
    ExecFuntion exec = (ExecFuntion)libs[plugin]->resolve("ddd");
    if(exec)
        exec();
}
