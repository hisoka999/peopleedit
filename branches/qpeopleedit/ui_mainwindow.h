/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jan 14 23:42:12 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionAbout;
    QAction *actionExit;
    QAction *actionDelete;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *forenameLabel;
    QLineEdit *forenameLineEdit;
    QWidget *tab_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *emailLineEdit;
    QPushButton *writemailButton;
    QLineEdit *webpageLineEdit;
    QLineEdit *icqLineEdit;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(368, 515);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/base/peopleedit.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setMaximumSize(QSize(110, 110));

        verticalLayout->addWidget(graphicsView);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMaximumSize(QSize(100, 100));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        nameLabel = new QLabel(tab);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(tab);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        forenameLabel = new QLabel(tab);
        forenameLabel->setObjectName(QString::fromUtf8("forenameLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, forenameLabel);

        forenameLineEdit = new QLineEdit(tab);
        forenameLineEdit->setObjectName(QString::fromUtf8("forenameLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, forenameLineEdit);


        horizontalLayout->addLayout(formLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        emailLineEdit = new QLineEdit(tab_3);
        emailLineEdit->setObjectName(QString::fromUtf8("emailLineEdit"));

        gridLayout->addWidget(emailLineEdit, 0, 1, 1, 1);

        writemailButton = new QPushButton(tab_3);
        writemailButton->setObjectName(QString::fromUtf8("writemailButton"));

        gridLayout->addWidget(writemailButton, 0, 2, 1, 1);

        webpageLineEdit = new QLineEdit(tab_3);
        webpageLineEdit->setObjectName(QString::fromUtf8("webpageLineEdit"));

        gridLayout->addWidget(webpageLineEdit, 1, 1, 1, 2);

        icqLineEdit = new QLineEdit(tab_3);
        icqLineEdit->setObjectName(QString::fromUtf8("icqLineEdit"));

        gridLayout->addWidget(icqLineEdit, 2, 1, 1, 2);

        lineEdit_4 = new QLineEdit(tab_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 2);

        lineEdit_6 = new QLineEdit(tab_3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 6, 1, 1, 2);

        lineEdit_5 = new QLineEdit(tab_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 4, 1, 1, 2);

        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 368, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionDelete);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionDelete);
        mainToolBar->addAction(actionAbout);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "new", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "about", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "exit", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("MainWindow", "delete", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        forenameLabel->setText(QApplication::translate("MainWindow", "forename", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "private", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "office", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "email:", 0, QApplication::UnicodeUTF8));
        writemailButton->setText(QApplication::translate("MainWindow", "write email", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "webpage:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "icq:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "aol:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "msn:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "skype:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "online", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
