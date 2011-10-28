#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QFile>
#include <QFileDialog>
#include <QLibrary>
#include "vcard.h"
#include "freedesktopmime.h"
#include <QDebug>


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
    setAcceptDrops(true);
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
        qDebug()<<menuBar()->children().at(i)->objectName();
    if(m!=NULL)
    {
        qDebug()<<QString("sync menu was found");
    }
    model = new SqlModel(db);
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->hideColumn(0);
    for(int i=5;i<model->columnCount();++i)
        ui->tableView->hideColumn(i);
    updateContent(model->index(0,0));

    loader = new PluginLoader(this,"/home/stefan/projects/qpeopleedit/plugins");

}
void MainWindow::syncAction(QAction* action)
{
    qDebug()<<QString("action executed");
    qDebug()<<action->objectName();
    loader->exec(action->objectName());
}
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{


    event->acceptProposedAction();
    //emit changed(event->mimeData());
}

void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    qDebug()<<mimeData->urls().first().toString();
    if (mimeData->hasImage()) {
        QGraphicsScene *scene = new QGraphicsScene();

        QPixmap image = qvariant_cast<QPixmap>(mimeData->imageData());
        if (!image.isNull())
        {
            image.scaled(100,100);
            scene->addPixmap(image);
        }
        ui->graphicsView->setScene(scene);
    }else if(mimeData->hasUrls())
    {
        QUrl url = mimeData->urls().first();
        QFileInfo info(url.path());
        qDebug()<<info.absoluteFilePath();
        QFreeDesktopMime mime;

        //QFile *file = new QFile(url);
        QString fmime = mime.fromFile(info.absoluteFilePath());
        if(fmime.startsWith("image")){
            model->setData(model->index(oldindex.row(),model->fieldIndex("image")),info.absoluteFilePath());
            updateContent(oldindex);
        }
        else if(fmime == "text/directory"){
            qDebug()<<QString("No Drag & Drop for vCards");
        }

    }
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
    ui->graphicsView->setScene(NULL);
    QGraphicsScene *scene = new QGraphicsScene();
    qDebug()<<path;
    QPixmap image = QPixmap(path);
    if (!image.isNull())
    {
        if(image.width()>100 || image.height()>100)
            image=image.scaled(100,100,Qt::KeepAspectRatio);
        //cerr<<image.scaledToHeight()
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
    QMessageBox::about(this,QObject::tr("About PeopleEdit"),QObject::tr(QString("this is free software under the <br>terms of the GPL.<br><br><b>Version:</b> "+QApplication::applicationVersion()+"<br><b>Author:</b> Stefan L&uuml;dtke<br><a href=\"http://code.google.com/p/peopleedit/\">Website</a>").toUtf8()));
}

void MainWindow::on_tableView_clicked(QModelIndex index)
{

    saveContent(oldindex);
    oldindex = index;
    updateContent(index);
    ui->tableView->setCurrentIndex(index);
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
    qDebug()<<path;
    QPixmap image = QPixmap(path);
    if (!image.isNull())
    {
    image.scaled(100,100);
    scene->addPixmap(image);
    }
    ui->graphicsView->setScene(scene);
    model->setData(model->index(oldindex.row(),model->fieldIndex("image")),path);
}

void MainWindow::on_actionVCard_triggered()
{
    QString path = QFileDialog::getOpenFileName(this,tr("Open vCard"),QDir::homePath(),tr("vCard Files (*.vcf)"));
    qDebug()<<path;
    QList<vCard> vcards = vCard::readFromFile(path);

    // ...and then we can use it.
    if (!vcards.isEmpty())
    {

    }
}
