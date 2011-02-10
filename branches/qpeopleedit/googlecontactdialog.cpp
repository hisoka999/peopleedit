#include "googlecontactdialog.h"
#include "ui_googlecontactdialog.h"
#include <QAbstractButton>
#include <QMessageBox>
GoogleContactDialog::GoogleContactDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoogleContactDialog)
{
    ui->setupUi(this);
    loginform = new GoogleLoginForm(this);

    ((QBoxLayout*)this->layout())->insertWidget(0,loginform);
    this->layout()->removeWidget(ui->widget);
    step = 0;

}

GoogleContactDialog::~GoogleContactDialog()
{
    delete ui;
}

void GoogleContactDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void GoogleContactDialog::on_btnTwo_clicked()
{
    QThread *t= new QThread();
    switch(step){
    case 0:
        ui->btnOne->setText(tr("Back"));
        loginform->login();

    case 1:
        updateform = new GoogleUpdateForm(this);
        ((QBoxLayout*)this->layout())->insertWidget(0,updateform);
        this->layout()->removeWidget(loginform);
        this->layout()->update();
        break;
    case 2:
        this->close();
    }
    step++;
}
