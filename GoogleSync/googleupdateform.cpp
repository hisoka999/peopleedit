#include "googleupdateform.h"
#include "ui_googleupdateform.h"
#include <iostream>
#include <QFile>

GoogleUpdateForm::GoogleUpdateForm(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::GoogleUpdateForm)
{
    ui->setupUi(this);
    if (!GAuth::get()->Auth.isEmpty())
    {
        QUrl url("https://www.google.com/m8/feeds/contacts/default/full");
        http = new QHttp(url.host(),QHttp::ConnectionModeHttps);
        QHttpRequestHeader header("GET",url.path());
        //QString data ="Authorization: GoogleLogin auth="+auth->Auth;
        header.setValue("Authorization","GoogleLogin auth="+GAuth::get()->Auth);
        http->request(header);
        connect(http,SIGNAL(done(bool)),this,SLOT(done()));

    }else{
        std::cerr<<"login failed"<<std::endl;
    }

}
void GoogleUpdateForm::done()
{
    QString tmp =http->readAll();
    //std::cout<<tmp.toStdString()<<std::endl;
    if(tmp.size()>0)GAuth::get()->complete=true;
    try{
        QFile *f = new QFile("/home/stefan/Desktop/debug.xml");
        f->open(QIODevice::WriteOnly);
        f->write(tmp.toUtf8());
        f->close();
        contacts = new GContacts(tmp);
        QList<GContact*> *list = contacts->list();
        ui->tableWidget->setColumnCount(3);
        for(int i = 0;i<list->size();++i)
        {
            ui->tableWidget->insertRow(i);
            QTableWidgetItem *item = new QTableWidgetItem();
            QTableWidgetItem *item2 = new QTableWidgetItem();
            QTableWidgetItem *item3 = new QTableWidgetItem();
            item->setText(list->at(i)->getForename());
            ui->tableWidget->setItem(i,0,item);

            item2->setText(list->at(i)->getSurename());
            ui->tableWidget->setItem(i,1,item2);

            item3->setText(list->at(i)->getPhone());
            ui->tableWidget->setItem(i,2,item3);
            //ui->tableWidget->item(i,0)->setText(list->at(i)->getForename());
            //ui->tableWidget->item(i,1)->setText(list->at(i)->getSurename());
            //ui->tableWidget->item(i,2)->setText(list->at(i)->getPhone());


        }
    }catch(std::bad_alloc& bad)
    {
        std::cerr<<"exception: "<<bad.what()<<std::endl;
        exit(1);
    }

}

GoogleUpdateForm::~GoogleUpdateForm()
{
    delete ui;
}

void GoogleUpdateForm::changeEvent(QEvent *e)
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
