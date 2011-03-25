#ifndef GOOGLEUPDATEFORM_H
#define GOOGLEUPDATEFORM_H

#include <QWidget>
#include <QtNetwork/QtNetwork>
#include <QUrl>
#include <gauth.h>
#include <gcontacts.h>

namespace Ui {
    class GoogleUpdateForm;
}

class GoogleUpdateForm : public QWidget
{
    Q_OBJECT

public:
    explicit GoogleUpdateForm(QWidget *parent = 0);
    ~GoogleUpdateForm();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::GoogleUpdateForm *ui;
    GContacts *contacts;
    QNetworkAccessManager manager;
    QHttp *http;
private slots:
    void done();
};

#endif // GOOGLEUPDATEFORM_H
