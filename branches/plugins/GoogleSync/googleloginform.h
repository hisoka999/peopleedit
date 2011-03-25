#ifndef GOOGLELOGINFORM_H
#define GOOGLELOGINFORM_H

#include <QWidget>
#include <QtNetwork>
#include <gauth.h>

namespace Ui {
    class GoogleLoginForm;
}

class GoogleLoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit GoogleLoginForm(QWidget *parent = 0);
    ~GoogleLoginForm();
    void login();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::GoogleLoginForm *ui;
    QHttp *http;
    QNetworkAccessManager manager;
private slots:
    void done();
};

#endif // GOOGLELOGINFORM_H
