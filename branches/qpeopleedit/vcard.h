#ifndef VCARD_H
#define VCARD_H
#include <QList>
#include <QMap>
#include <QStringList>

class vCardProperty
{
public:
    vCardProperty(QString pName,QString pValue)
    {
        name = pName;
        value = pValue;
    }
    vCardProperty(){name = "";value="";}
    QString getName(){return name;}
    QString getValue(){return value;}
private:
    QString name;
    QString value;
};
class vCardName : public vCardProperty
{
public:
    vCardName(QString name,QString value): vCardProperty(name,value)
    {
        QStringList tmp = value.split(';');
        firstname = tmp.at(0);
        lastname = tmp.at(1);
    }

    void setFirstName(QString name){firstname = name;}
private:
    QString firstname;
    QString lastname;
};

class vCard
{
public:
    vCard(QStringList data);
    static QList<vCard> readFromFile(QString filename);
private:
    QMap<QString,vCardProperty> props;
};

#endif // VCARD_H
