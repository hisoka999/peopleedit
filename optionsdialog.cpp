#include "optionsdialog.h"
#include "ui_optionsdialog.h"

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    item->setText(QObject::tr("Plugins"));
    item->setIcon(QIcon(":/base/icons/plugin.png"));
    ui->listWidget->addItem(item);
}

OptionsDialog::~OptionsDialog()
{
    delete ui;
}

void OptionsDialog::changeEvent(QEvent *e)
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
