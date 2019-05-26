#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "mainwindow.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(resources);
    QTranslator translator;
    QString locale = QLocale::system().name();;
    a.addLibraryPath("plugins");
    locale.resize(2);
    std::cout<<locale.toStdString()<<std::endl;
    translator.load("de.qm");
    a.installTranslator(&translator);
    MainWindow w;
    w.show();

    return a.exec();
}
