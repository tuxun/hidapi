#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtWidgets>
#include <hiddevice.h>
#include <QLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Hiddevice *devlist=new Hiddevice();
    QGridLayout *hid_desc_layout=new QGridLayout();
    QLabel *hid_status=new QLabel(devlist->get_device_list());

    hid_desc_layout->addWidget(hid_status);
this->centralWidget()->setLayout(hid_desc_layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
