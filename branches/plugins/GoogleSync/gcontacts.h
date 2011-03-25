#ifndef GCONTACTS_H
#define GCONTACTS_H

#include <QString>

class GContact
{
public:
    GContact(){
        forename = "";
        surename = "";
        city = "";
        phone = "";
    }
    QString getForename(){return forename;}
    QString getSurename(){return surename;}
    QString getCity(){return city;}
    QString getPhone(){return phone;}
    void setForename(QString name){forename = name;}
    void setSurename(QString name){surename = name;}
    void setCity(QString c){city = c;}
    void setPhone(QString p){phone = p;}

private:
    QString forename;
    QString surename;
    QString city;
    QString phone;

};

class GContacts
{
public:
    GContacts(QString xmlcontent);
    QList<GContact*> *list();

private:
    QList<GContact*> *contacts;
};

#endif // GCONTACTS_H
