#ifndef SQLMODEL_H
#define SQLMODEL_H

#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>

class SqlModel : public QSqlTableModel
{
public:
    SqlModel(QSqlDatabase db);
    static void createTable();
};

#endif // SQLMODEL_H
