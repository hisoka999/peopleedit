#include "vcard.h"
#include <QFile>
#include <iostream>
vCard::vCard(QStringList data)
{
    //QStringList lines =data.split('\n');
    std::cout<<"begin parsing"<<std::endl;
    foreach(QString line,data)
    {
        QStringList tmp = line.split(':');
        QStringList prop = tmp.at(0).split(';');
        if (prop.at(0) == "N")
            props[prop.at(0)] = new vCardName(prop.at(0),tmp.at(1));
        else
            props[prop.at(0)] = new vCardProperty(prop.at(0),tmp.at(1));
        //std::cout<<prop.at(0).toStdString()<<"::"<<tmp.at(1).toStdString()<<std::endl;

    }
}
vCardProperty* vCard::property(QString name)
{
    return props[name];
}

QList<vCard> vCard::readFromFile(QString filename)
{
    QList<vCard> vcards;
    QStringList tmp;
    QFile *card = new QFile(filename);
    if (!card->open(QIODevice::ReadOnly | QIODevice::Text))
        return vcards;

    while (!card->atEnd())
    {
        QString line =card->readLine();
        if(line.startsWith("END:VCARD") )
        {
            vcards.append(vCard(tmp));
            tmp.clear();
        }
        else if(!line.startsWith("BEGIN:VCARD"))
        {
            tmp.append(line);
        }


    }
    return vcards;
}
