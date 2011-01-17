/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 17. Jan 19:20:04 2011
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
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
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
    QAction *actionAbout_qt;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTableView *tableView;
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
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(401, 572);
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
        actionAbout_qt = new QAction(MainWindow);
        actionAbout_qt->setObjectName(QString::fromUtf8("actionAbout_qt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_2->addWidget(tableView, 0, 0, 2, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        nameLabel = new QLabel(tab);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        gridLayout_3->addWidget(nameLabel, 0, 2, 1, 1);

        nameLineEdit = new QLineEdit(tab);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        gridLayout_3->addWidget(nameLineEdit, 0, 3, 1, 1);

        forenameLabel = new QLabel(tab);
        forenameLabel->setObjectName(QString::fromUtf8("forenameLabel"));

        gridLayout_3->addWidget(forenameLabel, 1, 2, 1, 1);

        forenameLineEdit = new QLineEdit(tab);
        forenameLineEdit->setObjectName(QString::fromUtf8("forenameLineEdit"));

        gridLayout_3->addWidget(forenameLineEdit, 1, 3, 1, 1);

        nicknameLineEdit = new QLineEdit(tab);
        nicknameLineEdit->setObjectName(QString::fromUtf8("nicknameLineEdit"));

        gridLayout_3->addWidget(nicknameLineEdit, 2, 3, 1, 1);

        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
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
        contactnameLineEdit->setObjectName(QString::fromUtf8("contactnameLineEdit"));

        gridLayout_3->addWidget(contactnameLineEdit, 3, 3, 1, 1);

        postalLineEdit = new QLineEdit(tab);
        postalLineEdit->setObjectName(QString::fromUtf8("postalLineEdit"));

        gridLayout_3->addWidget(postalLineEdit, 4, 3, 1, 1);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMaximumSize(QSize(100, 100));

        gridLayout_3->addWidget(pushButton, 3, 1, 1, 1);

        cityLineEdit = new QLineEdit(tab);
        cityLineEdit->setObjectName(QString::fromUtf8("cityLineEdit"));

        gridLayout_3->addWidget(cityLineEdit, 5, 3, 1, 1);

        streetLineEdit = new QLineEdit(tab);
        streetLineEdit->setObjectName(QString::fromUtf8("streetLineEdit"));

        gridLayout_3->addWidget(streetLineEdit, 6, 3, 1, 1);

        housenumberLineEdit = new QLineEdit(tab);
        housenumberLineEdit->setObjectName(QString::fromUtf8("housenumberLineEdit"));

        gridLayout_3->addWidget(housenumberLineEdit, 7, 3, 1, 1);

        countryLineEdit = new QLineEdit(tab);
        countryLineEdit->setObjectName(QString::fromUtf8("countryLineEdit"));

        gridLayout_3->addWidget(countryLineEdit, 8, 3, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 2, 2, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 3, 2, 1, 1);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 4, 2, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 5, 2, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 6, 2, 1, 1);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 7, 2, 1, 1);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 8, 2, 1, 1);

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
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(6);
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        emailLineEdit = new QLineEdit(tab_3);
        emailLineEdit->setObjectName(QString::fromUtf8("emailLineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(emailLineEdit->sizePolicy().hasHeightForWidth());
        emailLineEdit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(emailLineEdit, 0, 1, 1, 1);

        writemailButton = new QPushButton(tab_3);
        writemailButton->setObjectName(QString::fromUtf8("writemailButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(writemailButton->sizePolicy().hasHeightForWidth());
        writemailButton->setSizePolicy(sizePolicy4);
        writemailButton->setMinimumSize(QSize(13, 20));

        gridLayout->addWidget(writemailButton, 0, 2, 1, 1);

        webpageLineEdit = new QLineEdit(tab_3);
        webpageLineEdit->setObjectName(QString::fromUtf8("webpageLineEdit"));

        gridLayout->addWidget(webpageLineEdit, 1, 1, 1, 2);

        icqLineEdit = new QLineEdit(tab_3);
        icqLineEdit->setObjectName(QString::fromUtf8("icqLineEdit"));

        gridLayout->addWidget(icqLineEdit, 2, 1, 1, 2);

        aolLineEdit = new QLineEdit(tab_3);
        aolLineEdit->setObjectName(QString::fromUtf8("aolLineEdit"));

        gridLayout->addWidget(aolLineEdit, 3, 1, 1, 2);

        skypeLineEdit = new QLineEdit(tab_3);
        skypeLineEdit->setObjectName(QString::fromUtf8("skypeLineEdit"));
        skypeLineEdit->setFrame(true);
        skypeLineEdit->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout->addWidget(skypeLineEdit, 6, 1, 1, 2);

        msnLineEdit = new QLineEdit(tab_3);
        msnLineEdit->setObjectName(QString::fromUtf8("msnLineEdit"));
        msnLineEdit->setEchoMode(QLineEdit::Normal);
        msnLineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(msnLineEdit, 4, 1, 1, 2);

        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy5.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        widget = new QWidget(tab_3);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout->addWidget(widget, 7, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        tabWidget->addTab(tab_3, QString());

        gridLayout_2->addWidget(tabWidget, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 401, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
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
        menuHelp->addAction(actionAbout_qt);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionDelete);
        mainToolBar->addAction(actionAbout);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Peopleedit", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "new", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "about", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "exit", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("MainWindow", "delete", 0, QApplication::UnicodeUTF8));
        actionAbout_qt->setText(QApplication::translate("MainWindow", "about qt", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        forenameLabel->setText(QApplication::translate("MainWindow", "forename", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "nickname:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "contactname:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "postal:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "city:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "street:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "house number:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "country:", 0, QApplication::UnicodeUTF8));
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
