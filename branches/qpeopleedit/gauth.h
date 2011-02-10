#ifndef GAUTH_H
#define GAUTH_H

#include <QString>
class GAuth
{
public:

    static GAuth *get();

    QString SID;
    QString Auth;
    QString LSID;
    bool complete;
private:
    GAuth();
    static GAuth* instance;
};

#endif // GAUTH_H
