#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sqlmodel.h>
#include <QtSql/QSqlDatabase>
#include <QtNetwork/QtNetwork>
#include <QUrl>
#include <gauth.h>
#include <gcontacts.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    SqlModel *model;
    QHttp *http;
    GAuth *auth;
    GContacts *contacts;
    QNetworkAccessManager manager;
    QModelIndex oldindex;
    void saveContent(QModelIndex index);
    void updateContent(QModelIndex index);

private slots:
    void on_pushButton_clicked();
    void on_actionGoogle_Contacts_triggered();
    void on_actionDelete_triggered();
    void on_actionNew_triggered();
    void on_actionAbout_qt_triggered();
    void on_tableView_clicked(QModelIndex index);
    void on_actionAbout_triggered();
    void on_actionExit_triggered();
};

#endif // MAINWINDOW_H