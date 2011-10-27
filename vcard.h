#ifndef VCARD_H
#define VCARD_H
#include <QList>
#include <QMap>
#include <QStringList>

class vCard
{
public:
    vCard(QStringList data);
    static QList<vCard> readFromFile(QString filename);
private:
    QMap<QString,QString> props;
};

#endif // VCARD_H
