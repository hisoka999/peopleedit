#include "gcontacts.h"
#include <QtXml/QtXml>
#include <iostream>
using namespace std;
GContacts::GContacts(QString xmlcontent)
{
    QDomDocument *doc = new QDomDocument();
    doc->setContent(xmlcontent);
    contacts = new QList<GContact*>();
    QDomNodeList list=doc->elementsByTagName("entry");
    for(int i=0;i<list.count();i++)
    {
        QDomNode node = list.at(i);
        QString tmp=node.namedItem("title").firstChild().nodeValue();
        GContact *contact= new GContact();
        contact->setForename(tmp.split(" ").at(0));
        if(tmp.split(" ").size()>1)
        contact->setSurename(tmp.split(" ").at(1));
        contact->setPhone(node.namedItem("gd:phoneNumber").firstChild().nodeValue());
        contacts->append(contact);
        cout<<node.namedItem("title").firstChild().nodeValue().toStdString()<<endl;
    }
}

QList<GContact*> *GContacts::list()
{
    return contacts;
}
