#include "sqlmodel.h"
SqlModel::SqlModel(QSqlDatabase db) : QSqlTableModel(0,db)
{

    this->setTable("contacts");

    this->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //this->setRelation(2, QSqlRelation("city", "id", "name"));
    //this->setRelation(3, QSqlRelation("country", "id", "name"));

    this->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    this->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
    this->setHeaderData(2, Qt::Horizontal, QObject::tr("forname"));
    this->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
    this->setHeaderData(4, Qt::Horizontal, QObject::tr("nickname"));

    this->select();
}

void SqlModel::createTable()
{
    QSqlQuery query;
    query.exec("CREATE TABLE contacts "
               "(id INTEGER PRIMARY KEY , name VARCHAR , forename VARCHAR , email VARCHAR , nickname VARCHAR , contactname VARCHAR , company VARCHAR ,"
               "company_city VARCHAR , company_postal INTEGER , company_street VARCHAR , company_housenumber VARCHAR , company_telephone VARCHAR , company_fax VARCHAR , "
               "telephone_private VARCHAR , telephone_car VARCHAR , fax_private VARCHAR , street VARCHAR , housenumber VARCHAR , city VARCHAR , postal INTEGER , "
               "state VARCHAR , country VARCHAR , image VARCHAR , webpage VARCHAR , icq VARCHAR , skype VARCHAR , jabber VARCHAR , aol VARCHAR , msn VARCHAR);");
}
