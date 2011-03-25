#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H
#include <QString>
#include <QWidget>
#include <QLibrary>
#include <QMap>

class PluginLoader
{
public:
    PluginLoader(QWidget *parent,QString path);
    bool exec(QString plugin);
    void loadPlugin(QString path);

private:
    QWidget *parent;
    QMap<QString,QLibrary*> libs;
};

#endif // PLUGINLOADER_H
