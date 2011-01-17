#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFile>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QApplication::setApplicationVersion("0.1");
    QApplication::setApplicationName("peopleEdit");
    QApplication::setOrganizationName("PeopleEdit");

    QSettings ini(QSettings::IniFormat, QSettings::UserScope,
    QCoreApplication::organizationName(),
    QCoreApplication::applicationName());
    QString dir = QFileInfo(ini.fileName()).absolutePath();

    QDir path = QDir(dir);
    bool newdb= false;
    QMessageBox::critical(0,"PATH",dir,QMessageBox::Ok);
    QFile dbfile(path.absolutePath()+path.separator()+"data.db");
    if (!path.exists(path.absolutePath()))
    {
        path.mkpath(path.absolutePath());
        dbfile.open(QIODevice::WriteOnly);
       dbfile.flush();
       dbfile.close();
       newdb = true;
    }
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbfile.fileName());
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);


        this->close();
    }
    if(newdb)SqlModel::createTable();
    ui->setupUi(this);
    model = new SqlModel(db);
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->hideColumn(0);
    for(int i=5;i<model->columnCount();++i)
        ui->tableView->hideColumn(i);
    updateContent(model->index(0,0));

}
void MainWindow::saveContent(QModelIndex index)
{
    for (int i=0;i<ui->tab->children().count();++i)
    {
        const char* name=ui->tab->children().at(i)->metaObject()->className();
        if (name == ui->nameLineEdit->metaObject()->className())
        {
            //cout<<ui->tab->children().at(i)->objectName().toStdString()<<std::endl;
            QLineEdit *edit =(QLineEdit*)ui->tab->children().at(i);
            QString cont = model->index(index.row(),model->fieldIndex(edit->objectName().replace("LineEdit",""))).data().toString();

            QString text = edit->text();
            model->setData(model->index(index.row(),model->fieldIndex(edit->objectName().replace("LineEdit",""))),text);
            //cout<<edit->objectName().toStdString()<<": "<<text.toStdString()<<endl;
        }
    }
    model->submitAll();
}

void MainWindow::updateContent(QModelIndex index)
{
    for (int i=0;i<ui->tab->children().count();++i)
    {
        const char* name=ui->tab->children().at(i)->metaObject()->className();
        if (name == ui->nameLineEdit->metaObject()->className())
        {
            //cout<<ui->tab->children().at(i)->objectName().toStdString()<<std::endl;
            QLineEdit *edit =(QLineEdit*)ui->tab->children().at(i);
            QString cont = model->index(index.row(),model->fieldIndex(edit->objectName().replace("LineEdit",""))).data().toString();

            edit->setText(cont);
        }
    }
    for (int i=0;i<ui->tab_3->children().count();++i)
    {
        const char* name=ui->tab_3->children().at(i)->metaObject()->className();
        if (name == ui->nameLineEdit->metaObject()->className())
        {
            //cout<<ui->tab_3->children().at(i)->objectName().toStdString()<<std::endl;
            QLineEdit *edit =(QLineEdit*)ui->tab_3->children().at(i);
            QString cont = model->index(index.row(),model->fieldIndex(edit->objectName().replace("LineEdit",""))).data().toString();

            edit->setText(cont);
        }
    }
    QString path = model->index(index.row(),model->fieldIndex("image")).data().toString();
    QGraphicsScene *scene = new QGraphicsScene();
    cerr<<path.toStdString()<<endl;
    QPixmap image = QPixmap(path);
    if (!image.isNull())
    {
    image.scaled(100,100);
    scene->addPixmap(image);
    }
    ui->graphicsView->setScene(scene);
    //ui->graphicsView->scale(100,100);
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,QObject::tr("About PeopleEdit"),QObject::tr("this is free software."));
}

void MainWindow::on_tableView_clicked(QModelIndex index)
{

    saveContent(oldindex);
    oldindex = index;
    updateContent(index);
}

void MainWindow::on_actionAbout_qt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionNew_triggered()
{
    model->insertRow(0);

}
