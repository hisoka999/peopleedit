#include "googleloginform.h"
#include "ui_googleloginform.h"
#include <googlecontactdialog.h>

GoogleLoginForm::GoogleLoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoogleLoginForm)
{
    ui->setupUi(this);

}

void GoogleLoginForm::login()
{
    QUrl url("https://www.google.com/accounts/ClientLogin");
    http = new QHttp(url.host(),QHttp::ConnectionModeHttps);
    QHttpRequestHeader header("POST", url.path());
    header.setContentType("application/x-www-form-urlencoded");


    QString data="accountType=GOOGLE&Email="+ui->emailLineEdit->text()+"&Passwd="+ui->passwordLineEdit->text()+"&service=cp";

    //header.setContentLength(data.length());

    http->request(header,data.toUtf8());

    connect(http,SIGNAL(done(bool)),this,SLOT(done()));

}
void GoogleLoginForm::done()
{

    QString tmp = http->readAll();
    QStringList list=tmp.split("\n");
    GAuth::get()->SID=list.at(0).split("=").at(1);
    GAuth::get()->LSID=list.at(1).split("=").at(1);
    GAuth::get()->Auth=list.at(2).split("=").at(1);
    GAuth::get()->complete=true;
    ((GoogleContactDialog*)this->parentWidget())->on_btnTwo_clicked();

}

GoogleLoginForm::~GoogleLoginForm()
{
    delete ui;
}

void GoogleLoginForm::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
