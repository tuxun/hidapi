/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionV_rifier_mahine;
    QAction *actionInfo;
    QAction *actionManuel;
    QAction *actionDebug;
    QAction *actionNouvelle;
    QAction *actionConnecter;
    QAction *actionLibrary_path;
    QAction *actionLittle_height_1024px;
    QAction *actionNormal_15_fullscreen_test;
    QAction *actionAutodetect;
    QAction *actionImport;
    QAction *actionToggle_Library;
    QWidget *centralWidget;
    QTabWidget *verticalTabWidget;
    QWidget *verticalTabWidgetPage1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *moinschaudButton;
    QProgressBar *tempbare;
    QPushButton *pluschaudButton;
    QGridLayout *gridLayout;
    QPushButton *bgButton;
    QPushButton *hButton;
    QPushButton *bButton;
    QPushButton *hgButton;
    QPushButton *hdButton;
    QPushButton *bdButton;
    QPushButton *gButton;
    QPushButton *dButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *runstopbutton;
    QLabel *movewaylabel;
    QMenuBar *menuBar;
    QMenu *menuM;
    QMenu *menuStatut;
    QMenu *menuAide;
    QMenu *menuSettings;
    QMenu *menuScreen_size;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(640, 559);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setDockNestingEnabled(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::VerticalTabs);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionV_rifier_mahine = new QAction(MainWindow);
        actionV_rifier_mahine->setObjectName(QStringLiteral("actionV_rifier_mahine"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        actionManuel = new QAction(MainWindow);
        actionManuel->setObjectName(QStringLiteral("actionManuel"));
        actionDebug = new QAction(MainWindow);
        actionDebug->setObjectName(QStringLiteral("actionDebug"));
        actionNouvelle = new QAction(MainWindow);
        actionNouvelle->setObjectName(QStringLiteral("actionNouvelle"));
        actionConnecter = new QAction(MainWindow);
        actionConnecter->setObjectName(QStringLiteral("actionConnecter"));
        actionLibrary_path = new QAction(MainWindow);
        actionLibrary_path->setObjectName(QStringLiteral("actionLibrary_path"));
        actionLittle_height_1024px = new QAction(MainWindow);
        actionLittle_height_1024px->setObjectName(QStringLiteral("actionLittle_height_1024px"));
        actionNormal_15_fullscreen_test = new QAction(MainWindow);
        actionNormal_15_fullscreen_test->setObjectName(QStringLiteral("actionNormal_15_fullscreen_test"));
        actionAutodetect = new QAction(MainWindow);
        actionAutodetect->setObjectName(QStringLiteral("actionAutodetect"));
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        actionToggle_Library = new QAction(MainWindow);
        actionToggle_Library->setObjectName(QStringLiteral("actionToggle_Library"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalTabWidget = new QTabWidget(centralWidget);
        verticalTabWidget->setObjectName(QStringLiteral("verticalTabWidget"));
        verticalTabWidget->setGeometry(QRect(0, 0, 641, 511));
        sizePolicy.setHeightForWidth(verticalTabWidget->sizePolicy().hasHeightForWidth());
        verticalTabWidget->setSizePolicy(sizePolicy);
        verticalTabWidgetPage1 = new QWidget();
        verticalTabWidgetPage1->setObjectName(QStringLiteral("verticalTabWidgetPage1"));
        verticalLayout = new QVBoxLayout(verticalTabWidgetPage1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        moinschaudButton = new QPushButton(verticalTabWidgetPage1);
        moinschaudButton->setObjectName(QStringLiteral("moinschaudButton"));

        horizontalLayout_2->addWidget(moinschaudButton);

        tempbare = new QProgressBar(verticalTabWidgetPage1);
        tempbare->setObjectName(QStringLiteral("tempbare"));
        tempbare->setValue(24);

        horizontalLayout_2->addWidget(tempbare);

        pluschaudButton = new QPushButton(verticalTabWidgetPage1);
        pluschaudButton->setObjectName(QStringLiteral("pluschaudButton"));

        horizontalLayout_2->addWidget(pluschaudButton);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        bgButton = new QPushButton(verticalTabWidgetPage1);
        bgButton->setObjectName(QStringLiteral("bgButton"));

        gridLayout->addWidget(bgButton, 3, 0, 1, 1);

        hButton = new QPushButton(verticalTabWidgetPage1);
        hButton->setObjectName(QStringLiteral("hButton"));

        gridLayout->addWidget(hButton, 1, 1, 1, 1);

        bButton = new QPushButton(verticalTabWidgetPage1);
        bButton->setObjectName(QStringLiteral("bButton"));

        gridLayout->addWidget(bButton, 3, 1, 1, 1);

        hgButton = new QPushButton(verticalTabWidgetPage1);
        hgButton->setObjectName(QStringLiteral("hgButton"));

        gridLayout->addWidget(hgButton, 1, 0, 1, 1);

        hdButton = new QPushButton(verticalTabWidgetPage1);
        hdButton->setObjectName(QStringLiteral("hdButton"));

        gridLayout->addWidget(hdButton, 1, 2, 1, 1);

        bdButton = new QPushButton(verticalTabWidgetPage1);
        bdButton->setObjectName(QStringLiteral("bdButton"));

        gridLayout->addWidget(bdButton, 3, 2, 1, 1);

        gButton = new QPushButton(verticalTabWidgetPage1);
        gButton->setObjectName(QStringLiteral("gButton"));

        gridLayout->addWidget(gButton, 2, 0, 1, 1);

        dButton = new QPushButton(verticalTabWidgetPage1);
        dButton->setObjectName(QStringLiteral("dButton"));

        gridLayout->addWidget(dButton, 2, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        runstopbutton = new QPushButton(verticalTabWidgetPage1);
        runstopbutton->setObjectName(QStringLiteral("runstopbutton"));

        horizontalLayout->addWidget(runstopbutton);

        movewaylabel = new QLabel(verticalTabWidgetPage1);
        movewaylabel->setObjectName(QStringLiteral("movewaylabel"));

        horizontalLayout->addWidget(movewaylabel);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalTabWidget->addTab(verticalTabWidgetPage1, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 18));
        menuM = new QMenu(menuBar);
        menuM->setObjectName(QStringLiteral("menuM"));
        menuStatut = new QMenu(menuBar);
        menuStatut->setObjectName(QStringLiteral("menuStatut"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuScreen_size = new QMenu(menuSettings);
        menuScreen_size->setObjectName(QStringLiteral("menuScreen_size"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuM->menuAction());
        menuBar->addAction(menuStatut->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuM->addAction(actionImport);
        menuM->addAction(actionQuitter);
        menuStatut->addAction(actionV_rifier_mahine);
        menuStatut->addAction(actionNouvelle);
        menuStatut->addAction(actionConnecter);
        menuAide->addAction(actionInfo);
        menuAide->addAction(actionManuel);
        menuAide->addAction(actionDebug);
        menuSettings->addAction(actionLibrary_path);
        menuSettings->addAction(menuScreen_size->menuAction());
        menuSettings->addAction(actionToggle_Library);
        menuScreen_size->addAction(actionLittle_height_1024px);
        menuScreen_size->addAction(actionNormal_15_fullscreen_test);
        menuScreen_size->addAction(actionAutodetect);

        retranslateUi(MainWindow);

        verticalTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionV_rifier_mahine->setText(QApplication::translate("MainWindow", "V\303\251rifier machine", 0));
        actionInfo->setText(QApplication::translate("MainWindow", "Info", 0));
        actionManuel->setText(QApplication::translate("MainWindow", "Manuel", 0));
        actionDebug->setText(QApplication::translate("MainWindow", "Debug", 0));
        actionNouvelle->setText(QApplication::translate("MainWindow", "Nouvelle...", 0));
        actionConnecter->setText(QApplication::translate("MainWindow", "Connecter...", 0));
        actionLibrary_path->setText(QApplication::translate("MainWindow", "Library path...", 0));
        actionLittle_height_1024px->setText(QApplication::translate("MainWindow", "Little(height<960px)", 0));
        actionNormal_15_fullscreen_test->setText(QApplication::translate("MainWindow", "normal(15\" fullscreen test)", 0));
        actionAutodetect->setText(QApplication::translate("MainWindow", "Autodetect", 0));
        actionImport->setText(QApplication::translate("MainWindow", "Import", 0));
        actionToggle_Library->setText(QApplication::translate("MainWindow", "Toggle Library", 0));
        moinschaudButton->setText(QApplication::translate("MainWindow", "MOINS chaud", 0));
        pluschaudButton->setText(QApplication::translate("MainWindow", "PLUS chaud", 0));
        bgButton->setText(QApplication::translate("MainWindow", "GAUCHE/BAS", 0));
        hButton->setText(QApplication::translate("MainWindow", "HAUT", 0));
        bButton->setText(QApplication::translate("MainWindow", "BAS", 0));
        hgButton->setText(QApplication::translate("MainWindow", "GAUCHE/HAUT", 0));
        hdButton->setText(QApplication::translate("MainWindow", "DROITE/HAUT", 0));
        bdButton->setText(QApplication::translate("MainWindow", "DROITE/BAS", 0));
        gButton->setText(QApplication::translate("MainWindow", "GAUCHE", 0));
        dButton->setText(QApplication::translate("MainWindow", "DROITE", 0));
        runstopbutton->setText(QApplication::translate("MainWindow", "Run/Stop", 0));
        movewaylabel->setText(QApplication::translate("MainWindow", "ordre", 0));
        verticalTabWidget->setTabText(verticalTabWidget->indexOf(verticalTabWidgetPage1), QApplication::translate("MainWindow", "Pilotage manuel", 0));
        menuM->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuStatut->setTitle(QApplication::translate("MainWindow", "Machine", 0));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0));
        menuScreen_size->setTitle(QApplication::translate("MainWindow", "Screen size", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
