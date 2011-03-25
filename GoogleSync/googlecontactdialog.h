#ifndef GOOGLECONTACTDIALOG_H
#define GOOGLECONTACTDIALOG_H

#include <QDialog>
#include <googleloginform.h>
#include <googleupdateform.h>
#include <QAbstractButton>

namespace Ui {
    class GoogleContactDialog;
}

class GoogleContactDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoogleContactDialog(QWidget *parent = 0);
    ~GoogleContactDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::GoogleContactDialog *ui;
    GoogleLoginForm *loginform;
    GoogleUpdateForm *updateform;
    int step;

public slots:
    void on_btnTwo_clicked();
};

#endif // GOOGLECONTACTDIALOG_H
