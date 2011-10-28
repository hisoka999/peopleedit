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
            props[prop.at(0)] = vCardName(prop.at(0),tmp.at(1));
        else
            props[prop.at(0)] = vCardProperty(prop.at(0),tmp.at(1));
        std::cout<<prop.at(0).toStdString()<<"::"<<tmp.at(1).toStdString()<<std::endl;

    }
    foreach(vCardProperty obj,props)
    {
        //QString tmp = (QString)obj;
        std::cout<<obj.getValue().toStdString()<<std::endl;
    }
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
