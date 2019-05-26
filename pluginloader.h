#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H
#include <QString>
#include <QWidget>
#include <QLibrary>
#include <QMap>

class Library{
public:
    Library(QLibrary* library,QString name,QString version)
    {
        this->library = library;
        this->name    = name;
        this->version = version;
    }
private:
    QLibrary *library;
    QString name;
    QString version;
};

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
