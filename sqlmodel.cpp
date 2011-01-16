#include "sqlmodel.h"
#include <iostream>
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
    std::cout<<"rows:"<<this->rowCount()<<std::endl;
    std::cerr<<this->columnCount()<<std::endl;
}
