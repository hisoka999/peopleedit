#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFile>
#include <QFileDialog>
#include <QLibrary>


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
    QFile dbfile(path.absolutePath()+path.separator()+"data.db");
    if (!path.exists(path.absolutePath()))
    {
        path.mkpath(path.absolutePath());
        dbfile.open(QIODevice::WriteOnly);
       dbfile.flush();
       dbfile.close();
       newdb = true;
    }


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbfile.fileName());
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);


        this->close();
    }
    if(newdb)SqlModel::createTable();
    ui->setupUi(this);
    connect(ui->menuSync,SIGNAL(triggered(QAction*)),this,SLOT(syncAction(QAction*)));

    QMenu *m = this->menuBar()->findChild<QMenu*>(QString("menuSync"));
    for(int i=0;i<menuBar()->children().size();++i)
        cout<<menuBar()->children().at(i)->objectName().toStdString()<<endl;
    if(m!=NULL)
    {
        cout<<"sync menu was found"<<endl;
    }
    model = new SqlModel(db);
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->hideColumn(0);
    for(int i=5;i<model->columnCount();++i)
        ui->tableView->hideColumn(i);
    updateContent(model->index(0,0));

    //cout<<QApplication::libraryPaths()
    foreach (QString path, QApplication::libraryPaths())
         cout<<path.toStdString()<<endl;
    QLibrary mylib("/home/stefan/projects/GoogleSync/libGoogleSync.so");
    //QLibrary mylib("/home/stefan/projects/Testplugin/libTestplugin.so");
    typedef int(*ExecFunction)();
    //mylib.load();
    ExecFunction exec = (ExecFunction) mylib.resolve("ddd");
    //mylib.resolve("GoogleContactDialog");
    if(exec)
    {
        //exec();
        cout<<"exec function executed!"<<endl;
    }

    //if(!mylib.isLoaded())
    loader = new PluginLoader(this,"/home/stefan/projects/qpeopleedit/plugins");
    cout<<mylib.errorString().toStdString()<<endl;
}
void MainWindow::syncAction(QAction* action)
{
    cout<<"action executed"<<endl;
    cout<<action->objectName().toStdString()<<endl;
    loader->exec(action->objectName());
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
    for (int i=0;i<ui->tab_3->children().count();++i)
    {
        const char* name=ui->tab_3->children().at(i)->metaObject()->className();
        if (name == ui->nameLineEdit->metaObject()->className())
        {
            //cout<<ui->tab->children().at(i)->objectName().toStdString()<<std::endl;
            QLineEdit *edit =(QLineEdit*)ui->tab_3->children().at(i);
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
    model->submitAll();
    delete model;
    QSqlDatabase::removeDatabase("QSQLITE");
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

void MainWindow::on_actionDelete_triggered()
{
    model->removeRow(oldindex.row());
}

void MainWindow::on_actionGoogle_Contacts_triggered()
{
    //GoogleContactDialog *dialog = new GoogleContactDialog();
    //dialog->show();
}

void MainWindow::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,
                                            tr("Open Image"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));

    //QString path = model->index(index.row(),model->fieldIndex("image")).data().toString();
    QGraphicsScene *scene = new QGraphicsScene();
    cerr<<path.toStdString()<<endl;
    QPixmap image = QPixmap(path);
    if (!image.isNull())
    {
    image.scaled(100,100);
    scene->addPixmap(image);
    }
    ui->graphicsView->setScene(scene);
    model->setData(model->index(oldindex.row(),model->fieldIndex("image")),path);
}
