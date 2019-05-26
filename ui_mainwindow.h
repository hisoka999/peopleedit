/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionAbout;
    QAction *actionExit;
    QAction *actionDelete;
    QAction *actionAbout_qt;
    QAction *actionVCard;
    QAction *actionVCard_2;
    QAction *actionOptions;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *forenameLabel;
    QLineEdit *forenameLineEdit;
    QLineEdit *nicknameLineEdit;
    QGraphicsView *graphicsView;
    QLineEdit *contactnameLineEdit;
    QLineEdit *postalLineEdit;
    QPushButton *pushButton;
    QLineEdit *cityLineEdit;
    QLineEdit *streetLineEdit;
    QLineEdit *housenumberLineEdit;
    QLineEdit *countryLineEdit;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *companyLabel;
    QLineEdit *companyLineEdit;
    QLabel *companyPhoneLabel;
    QLineEdit *company_telephoneLineEdit;
    QLabel *faxLabel;
    QLineEdit *company_faxLineEdit;
    QLabel *company_cityLabel;
    QLineEdit *company_cityLineEdit;
    QLabel *companyPostalLabel;
    QLineEdit *company_postalLineEdit;
    QLabel *companyStreetLabel;
    QLineEdit *company_streetLineEdit;
    QLabel *companyHousenumberLabel;
    QLineEdit *company_housenumberLineEdit;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *emailLineEdit;
    QPushButton *writemailButton;
    QLineEdit *webpageLineEdit;
    QLineEdit *icqLineEdit;
    QLineEdit *aolLineEdit;
    QLineEdit *skypeLineEdit;
    QLineEdit *msnLineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widget;
    QPushButton *openPageButton;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuImport;
    QMenu *menuExport;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuSync;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(425, 606);
        QIcon icon;
        icon.addFile(QStringLiteral(":/base/peopleedit.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/base/icons/book_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/base/icons/gtk-about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/base/icons/book_delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon3);
        actionAbout_qt = new QAction(MainWindow);
        actionAbout_qt->setObjectName(QStringLiteral("actionAbout_qt"));
        actionVCard = new QAction(MainWindow);
        actionVCard->setObjectName(QStringLiteral("actionVCard"));
        actionVCard_2 = new QAction(MainWindow);
        actionVCard_2->setObjectName(QStringLiteral("actionVCard_2"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        nameLabel = new QLabel(tab);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout_3->addWidget(nameLabel, 0, 2, 1, 1);

        nameLineEdit = new QLineEdit(tab);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout_3->addWidget(nameLineEdit, 0, 3, 1, 1);

        forenameLabel = new QLabel(tab);
        forenameLabel->setObjectName(QStringLiteral("forenameLabel"));

        gridLayout_3->addWidget(forenameLabel, 1, 2, 1, 1);

        forenameLineEdit = new QLineEdit(tab);
        forenameLineEdit->setObjectName(QStringLiteral("forenameLineEdit"));

        gridLayout_3->addWidget(forenameLineEdit, 1, 3, 1, 1);

        nicknameLineEdit = new QLineEdit(tab);
        nicknameLineEdit->setObjectName(QStringLiteral("nicknameLineEdit"));

        gridLayout_3->addWidget(nicknameLineEdit, 2, 3, 1, 1);

        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMinimumSize(QSize(100, 100));
        graphicsView->setMaximumSize(QSize(110, 110));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_3->addWidget(graphicsView, 0, 1, 3, 1);

        contactnameLineEdit = new QLineEdit(tab);
        contactnameLineEdit->setObjectName(QStringLiteral("contactnameLineEdit"));

        gridLayout_3->addWidget(contactnameLineEdit, 3, 3, 1, 1);

        postalLineEdit = new QLineEdit(tab);
        postalLineEdit->setObjectName(QStringLiteral("postalLineEdit"));

        gridLayout_3->addWidget(postalLineEdit, 4, 3, 1, 1);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMaximumSize(QSize(100, 100));

        gridLayout_3->addWidget(pushButton, 3, 1, 1, 1);

        cityLineEdit = new QLineEdit(tab);
        cityLineEdit->setObjectName(QStringLiteral("cityLineEdit"));

        gridLayout_3->addWidget(cityLineEdit, 5, 3, 1, 1);

        streetLineEdit = new QLineEdit(tab);
        streetLineEdit->setObjectName(QStringLiteral("streetLineEdit"));

        gridLayout_3->addWidget(streetLineEdit, 6, 3, 1, 1);

        housenumberLineEdit = new QLineEdit(tab);
        housenumberLineEdit->setObjectName(QStringLiteral("housenumberLineEdit"));

        gridLayout_3->addWidget(housenumberLineEdit, 7, 3, 1, 1);

        countryLineEdit = new QLineEdit(tab);
        countryLineEdit->setObjectName(QStringLiteral("countryLineEdit"));

        gridLayout_3->addWidget(countryLineEdit, 8, 3, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 2, 2, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 3, 2, 1, 1);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 4, 2, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 5, 2, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_3->addWidget(label_11, 6, 2, 1, 1);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 7, 2, 1, 1);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 8, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        companyLabel = new QLabel(tab_2);
        companyLabel->setObjectName(QStringLiteral("companyLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, companyLabel);

        companyLineEdit = new QLineEdit(tab_2);
        companyLineEdit->setObjectName(QStringLiteral("companyLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, companyLineEdit);

        companyPhoneLabel = new QLabel(tab_2);
        companyPhoneLabel->setObjectName(QStringLiteral("companyPhoneLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, companyPhoneLabel);

        company_telephoneLineEdit = new QLineEdit(tab_2);
        company_telephoneLineEdit->setObjectName(QStringLiteral("company_telephoneLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, company_telephoneLineEdit);

        faxLabel = new QLabel(tab_2);
        faxLabel->setObjectName(QStringLiteral("faxLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, faxLabel);

        company_faxLineEdit = new QLineEdit(tab_2);
        company_faxLineEdit->setObjectName(QStringLiteral("company_faxLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, company_faxLineEdit);

        company_cityLabel = new QLabel(tab_2);
        company_cityLabel->setObjectName(QStringLiteral("company_cityLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, company_cityLabel);

        company_cityLineEdit = new QLineEdit(tab_2);
        company_cityLineEdit->setObjectName(QStringLiteral("company_cityLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, company_cityLineEdit);

        companyPostalLabel = new QLabel(tab_2);
        companyPostalLabel->setObjectName(QStringLiteral("companyPostalLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, companyPostalLabel);

        company_postalLineEdit = new QLineEdit(tab_2);
        company_postalLineEdit->setObjectName(QStringLiteral("company_postalLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, company_postalLineEdit);

        companyStreetLabel = new QLabel(tab_2);
        companyStreetLabel->setObjectName(QStringLiteral("companyStreetLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, companyStreetLabel);

        company_streetLineEdit = new QLineEdit(tab_2);
        company_streetLineEdit->setObjectName(QStringLiteral("company_streetLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, company_streetLineEdit);

        companyHousenumberLabel = new QLabel(tab_2);
        companyHousenumberLabel->setObjectName(QStringLiteral("companyHousenumberLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, companyHousenumberLabel);

        company_housenumberLineEdit = new QLineEdit(tab_2);
        company_housenumberLineEdit->setObjectName(QStringLiteral("company_housenumberLineEdit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, company_housenumberLineEdit);


        verticalLayout->addLayout(formLayout);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(6);
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        emailLineEdit = new QLineEdit(tab_3);
        emailLineEdit->setObjectName(QStringLiteral("emailLineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(emailLineEdit->sizePolicy().hasHeightForWidth());
        emailLineEdit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(emailLineEdit, 0, 1, 1, 1);

        writemailButton = new QPushButton(tab_3);
        writemailButton->setObjectName(QStringLiteral("writemailButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(writemailButton->sizePolicy().hasHeightForWidth());
        writemailButton->setSizePolicy(sizePolicy4);
        writemailButton->setMinimumSize(QSize(13, 20));

        gridLayout->addWidget(writemailButton, 0, 2, 1, 1);

        webpageLineEdit = new QLineEdit(tab_3);
        webpageLineEdit->setObjectName(QStringLiteral("webpageLineEdit"));

        gridLayout->addWidget(webpageLineEdit, 1, 1, 1, 1);

        icqLineEdit = new QLineEdit(tab_3);
        icqLineEdit->setObjectName(QStringLiteral("icqLineEdit"));

        gridLayout->addWidget(icqLineEdit, 2, 1, 1, 2);

        aolLineEdit = new QLineEdit(tab_3);
        aolLineEdit->setObjectName(QStringLiteral("aolLineEdit"));

        gridLayout->addWidget(aolLineEdit, 3, 1, 1, 2);

        skypeLineEdit = new QLineEdit(tab_3);
        skypeLineEdit->setObjectName(QStringLiteral("skypeLineEdit"));
        skypeLineEdit->setFrame(true);
        skypeLineEdit->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout->addWidget(skypeLineEdit, 6, 1, 1, 2);

        msnLineEdit = new QLineEdit(tab_3);
        msnLineEdit->setObjectName(QStringLiteral("msnLineEdit"));
        msnLineEdit->setEchoMode(QLineEdit::Normal);
        msnLineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(msnLineEdit, 4, 1, 1, 2);

        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy5.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        widget = new QWidget(tab_3);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout->addWidget(widget, 7, 0, 1, 1);

        openPageButton = new QPushButton(tab_3);
        openPageButton->setObjectName(QStringLiteral("openPageButton"));

        gridLayout->addWidget(openPageButton, 1, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        tabWidget->addTab(tab_3, QString());

        gridLayout_2->addWidget(tabWidget, 5, 0, 1, 1);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setAutoFillBackground(false);
        tableView->setDragDropOverwriteMode(true);
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);
        tableView->verticalHeader()->setVisible(false);

        gridLayout_2->addWidget(tableView, 3, 0, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 425, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuImport = new QMenu(menuFile);
        menuImport->setObjectName(QStringLiteral("menuImport"));
        menuExport = new QMenu(menuFile);
        menuExport->setObjectName(QStringLiteral("menuExport"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuSync = new QMenu(menuBar);
        menuSync->setObjectName(QStringLiteral("menuSync"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(tableView, tabWidget);
        QWidget::setTabOrder(tabWidget, nameLineEdit);
        QWidget::setTabOrder(nameLineEdit, forenameLineEdit);
        QWidget::setTabOrder(forenameLineEdit, nicknameLineEdit);
        QWidget::setTabOrder(nicknameLineEdit, contactnameLineEdit);
        QWidget::setTabOrder(contactnameLineEdit, postalLineEdit);
        QWidget::setTabOrder(postalLineEdit, cityLineEdit);
        QWidget::setTabOrder(cityLineEdit, streetLineEdit);
        QWidget::setTabOrder(streetLineEdit, housenumberLineEdit);
        QWidget::setTabOrder(housenumberLineEdit, countryLineEdit);
        QWidget::setTabOrder(countryLineEdit, graphicsView);
        QWidget::setTabOrder(graphicsView, pushButton);
        QWidget::setTabOrder(pushButton, companyLineEdit);
        QWidget::setTabOrder(companyLineEdit, company_telephoneLineEdit);
        QWidget::setTabOrder(company_telephoneLineEdit, company_faxLineEdit);
        QWidget::setTabOrder(company_faxLineEdit, company_cityLineEdit);
        QWidget::setTabOrder(company_cityLineEdit, company_postalLineEdit);
        QWidget::setTabOrder(company_postalLineEdit, company_streetLineEdit);
        QWidget::setTabOrder(company_streetLineEdit, company_housenumberLineEdit);
        QWidget::setTabOrder(company_housenumberLineEdit, emailLineEdit);
        QWidget::setTabOrder(emailLineEdit, writemailButton);
        QWidget::setTabOrder(writemailButton, webpageLineEdit);
        QWidget::setTabOrder(webpageLineEdit, openPageButton);
        QWidget::setTabOrder(openPageButton, icqLineEdit);
        QWidget::setTabOrder(icqLineEdit, aolLineEdit);
        QWidget::setTabOrder(aolLineEdit, msnLineEdit);
        QWidget::setTabOrder(msnLineEdit, skypeLineEdit);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuSync->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(menuImport->menuAction());
        menuFile->addAction(menuExport->menuAction());
        menuFile->addAction(actionExit);
        menuImport->addAction(actionVCard);
        menuExport->addAction(actionVCard_2);
        menuEdit->addAction(actionDelete);
        menuEdit->addAction(actionOptions);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_qt);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionDelete);
        mainToolBar->addAction(actionAbout);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Peopleedit", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "new", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "about", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "exit", nullptr));
        actionDelete->setText(QApplication::translate("MainWindow", "delete", nullptr));
        actionAbout_qt->setText(QApplication::translate("MainWindow", "about qt", nullptr));
        actionVCard->setText(QApplication::translate("MainWindow", "vCard", nullptr));
        actionVCard_2->setText(QApplication::translate("MainWindow", "vCard", nullptr));
        actionOptions->setText(QApplication::translate("MainWindow", "options", nullptr));
        nameLabel->setText(QApplication::translate("MainWindow", "Name", nullptr));
        forenameLabel->setText(QApplication::translate("MainWindow", "forename", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "nickname:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "contactname:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "postal:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "city:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "street:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "house number:", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "country:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "private", nullptr));
        companyLabel->setText(QApplication::translate("MainWindow", "company:", nullptr));
        companyPhoneLabel->setText(QApplication::translate("MainWindow", "phone:", nullptr));
        faxLabel->setText(QApplication::translate("MainWindow", "fax:", nullptr));
        company_cityLabel->setText(QApplication::translate("MainWindow", "company city:", nullptr));
        companyPostalLabel->setText(QApplication::translate("MainWindow", "company postal:", nullptr));
        companyStreetLabel->setText(QApplication::translate("MainWindow", "company street:", nullptr));
        companyHousenumberLabel->setText(QApplication::translate("MainWindow", "company housenumber:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "office", nullptr));
        label->setText(QApplication::translate("MainWindow", "email:", nullptr));
        writemailButton->setText(QApplication::translate("MainWindow", "write email", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "webpage:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "icq:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "aol:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "msn:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "skype:", nullptr));
        openPageButton->setText(QApplication::translate("MainWindow", "open page", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "online", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuImport->setTitle(QApplication::translate("MainWindow", "import", nullptr));
        menuExport->setTitle(QApplication::translate("MainWindow", "export", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuSync->setTitle(QApplication::translate("MainWindow", "Sync", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
