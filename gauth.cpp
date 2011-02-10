#include "gauth.h"

GAuth* GAuth::instance = NULL;
GAuth::GAuth()
{
    Auth = "";
    this->SID = "";
    this->LSID = "";
}

GAuth* GAuth::get()
{
    if (instance == NULL)instance = new GAuth();
    return instance;
}
