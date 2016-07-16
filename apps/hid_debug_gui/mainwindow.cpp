#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //  this->setupDock(this);
    ui->setupUi(this);

    devlist=new Hiddevice();
    QList<QStringList> buf=devlist->get_device_list();

    QGridLayout *hid_desc_layout=new QGridLayout();
    tree = new QTreeWidget();
    tree->setColumnCount(5);
    QStringList header;
    header<<"product"<<"type"<<"path"<<"Manufacturer"<<"serial #";

    tree->setHeaderLabels(header);
    QList<QTreeWidgetItem *> items;
    for (int i=0;i<buf.size()/5;i+=1)
    {
        items.append(new QTreeWidgetItem(buf.at(i*5)));
        items.at(i)->setText(1, buf.at(i*5+1).at(0));
        items.at(i)->setText(2, buf.at(i*5+2).at(0));
        items.at(i)->setText(3, buf.at(i*5+3).at(0));
        items.at(i)->setText(4, buf.at(i*5+4).at(0));
    }

    tree->addTopLevelItems(items);
    hid_desc_layout->addWidget(tree);

    QHBoxLayout *connexion_layout=new QHBoxLayout();
    devpath=new QLineEdit();
    connect_bouton=new QPushButton("connexion");
    connexion_layout->addWidget(devpath);
    connexion_layout->addWidget(connect_bouton);

    QVBoxLayout *hidinfo_layout=new QVBoxLayout();
    hidinfo_layout->addLayout(connexion_layout);
    hidinfo_layout->addLayout(hid_desc_layout);
    QWidget *container=new QWidget();
    container->setLayout(hidinfo_layout);
    ui->verticalTabWidget->addTab(container,"info");
    ui->verticalTabWidget->setCurrentWidget(container);

    //hid_set_nonblocking(connected_device, 1);

    //getApp()->addTimeout(this, ID_TIMER,  5 * timeout_scalar /*5ms*/);

    // char* connected_label;
    //       sprintf(connected_label,"Connected to: %04hx:%04hx -", devlist->connected_vendor_id, devlist->connected_product_id);
    connect(connect_bouton,SIGNAL(clicked()),this,SLOT(connect_to()));
    connect(ui->moinschaudButton,SIGNAL(clicked()),this,SLOT(chauffemoins()));
    connect(ui->pluschaudButton,SIGNAL(clicked()),this,SLOT(chauffeplus()));
    connect(ui->hgButton,SIGNAL(clicked()),this,SLOT(mw_hgmove()));
    connect(ui->hdButton,SIGNAL(clicked()),this,SLOT(mw_hdmove()));
    connect(ui->hButton,SIGNAL(clicked()),this,SLOT(mw_hmove()));
    connect(ui->gButton,SIGNAL(clicked()),this,SLOT(mw_gmove()));
    connect(ui->dButton,SIGNAL(clicked()),this,SLOT(mw_dmove()));
    connect(ui->runstopbutton,SIGNAL(clicked()),this,SLOT(mw_HALTmove()));
    connect(ui->bgButton,SIGNAL(clicked()),this,SLOT(mw_bgmove()));
    connect(ui->bdButton,SIGNAL(clicked()),this,SLOT(mw_bdmove()));
    connect(ui->bButton,SIGNAL(clicked()),this,SLOT(mw_bmove()));
    connect(this , SIGNAL(realquit()), qApp, SLOT(quit()));
    connect(this,SIGNAL(temp_changed(int)),ui->tempbare,SLOT(setValue(int)));
    connect(this,SIGNAL(moveway_changed(move_way)),this,SLOT(setwhatrunbutton(move_way)));
    connect(this->tree,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(select_path(QTreeWidgetItem*,int)));
    // connect(ui->actionConnecter , SIGNAL(triggered()), this, SLOT(openmachinelist()));

    timer = new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(readHID()));

    //!
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    ui->verticalTabWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
container->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
//hidinfo_layout->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
//hid_desc_layout->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
tree->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->centralWidget()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


}
void MainWindow::readHID(){
    unsigned char *buf=devlist->dumpDATA();
    char *str=(char*)malloc(800*sizeof(char));
    int res=sizeof(buf);
    QString dbg;
if (buf>0)
{
   // sprintf(str,"Received %d bytes:\n", res);
   // dbg.append(str);
    for (int i = 0; i < res; i++) {
        //FXString t;
   //     sprintf(str,"%01hx ", buf[i]);
        dbg.append(buf[i]);

       // dbg.append(str);
        /*s += t;
        if ((i+1) % 4 == 0)
            s += " ";
        if ((i+1) % 16 == 0)
            s += "\n";*/
    }
 //dbg += "\n";
    statusBar()->showMessage(dbg);
}
else     statusBar()->showMessage("rien recu les 5 dernieres ms");

}

void MainWindow::select_path(QTreeWidgetItem* item,int index)
{

    //    printf ("clicked: %s\n",item->text(1));
    //  statusBar()->showMessage(tr("bien cliqué:")+item->text(1));
    devpath->setText(item->text(2));


}


void MainWindow::mw_hgmove()
{
    emit(moveway_changed(mwHG));

}
void MainWindow::connect_to()
{
    if (devlist->connect_Hiddevice(devpath->text().toStdString().c_str()))
        {
        statusBar()->showMessage(devpath->text()+" OK!");
    //donc normalement on a hid_set_nonblocking(connected_device, 1), reste la mise en place du timer

           timer->start(1000);

    }
    else statusBar()->showMessage("bien tenté:"+devpath->text());

}

void MainWindow::mw_hdmove()
{
    emit(moveway_changed(mwHD));

}


void MainWindow::mw_gmove()
{
    emit(moveway_changed(mwG));

}

void MainWindow::mw_dmove()
{
    emit(moveway_changed(mwD));

}

void MainWindow::mw_bgmove()
{
    emit(moveway_changed(mwBG));

}

void MainWindow::mw_bdmove()
{
    emit(moveway_changed(mwBD));

}

void MainWindow::mw_bmove()
{
    emit(moveway_changed(mwB));

}

void MainWindow::mw_HALTmove()
{
    emit(moveway_changed(mwHALT));

}

void MainWindow::setwhatrunbutton(move_way wayin)
{
    switch (wayin)
    {
    case mwHALT:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:green");

        ui->movewaylabel->setText("Stop");
        break;
    case mwH:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("haut");
        break;
    case mwHG:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("Haut/gauche");
        break;
    case mwHD:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("Haut/droite");
        break;
    case mwG:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("Gauche");
        break;
    case mwD:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("Droite");
        break;
    case mwBG:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("Bas/gauche");
        break;
    case mwBD:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("Bas/droite");
        break;
    case mwB:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");
        ui->movewaylabel->setText("Bas");
        break;
    }
}

void MainWindow::chauffeplus()
{
    actual_dest_temp=actual_dest_temp+1;
    if (actual_dest_temp>100)
    {
        actual_dest_temp=100;
    }
    emit (temp_changed(actual_dest_temp));
}
void MainWindow::chauffemoins()
{
    actual_dest_temp=actual_dest_temp-1;

    if (actual_dest_temp<0)
    {
        actual_dest_temp=0;
    }

    emit (temp_changed(actual_dest_temp));
}


void MainWindow::asktoquit(){
    //machine->close();
    emit realquit();
}
void MainWindow::mw_hmove()
{
    emit(moveway_changed(mwH));

}

void MainWindow::testmove()
{

    std::cout<<"main->testmoveslot()!"<<std::endl;
    //eg: usb data to move the first motor on 10 stepwhile 1 second
    //1 . send reset from pc: 0x42+0x00
    //1a. IPL5X answer is 0x42+0xFF
    //2 .source=USB (from PC): 0x42+0x01
    //2a. IPL5X answer is 0x42+0xFF
    //3 .Fill buffer
    unsigned char data=0x42; //Return the size of written data



    //return
    //machine->testmove();

}


void MainWindow::init_machine()
{


}



void MainWindow::teststatut()
{

}

MainWindow::~MainWindow()
{
    delete ui;
}
