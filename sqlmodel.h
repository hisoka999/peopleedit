#ifndef SQLMODEL_H
#define SQLMODEL_H

#include <Qt/QtSql>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>

class SqlModel : public QSqlTableModel
{
public:
    SqlModel(QSqlDatabase db);
};

#endif // SQLMODEL_H
