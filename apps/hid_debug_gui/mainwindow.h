#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <stdio.h>
#include <stdlib.h>
#include "hiddevice.h"

#include <QtGui>
#include <QtWidgets>
#include <hiddevice.h>
#include <QLayout>
#include <QMainWindow>
#include <QTimer>
namespace Ui {
class MainWindow;
}
enum move_way{mwHALT,mwH,mwB,mwG,mwD,mwHG,mwHD,mwBG,mwBD};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    move_way button_said;
    int actual_dest_temp;
    QTimer *timer;

signals:
    void temp_changed(int);
    void realquit();

void moveway_changed(move_way);
private:
Hiddevice *devlist;
QPushButton *connect_bouton;
QLineEdit *devpath;

QTreeWidget *tree;


    void setupDock(QWidget *target);
    QIcon openIcon,newIcon ,gearIcon,saveAsIcon ,saveIcon,aproposIcon;
    QWidget* get_menuWidget(void);
    QSizePolicy litleSizePolicy;

public slots:
    void connect_to();
    void select_path(QTreeWidgetItem *item, int index);
    void readHID();

void chauffeplus();
void chauffemoins();
void setwhatrunbutton(move_way);
void mw_hdmove();
void mw_dmove();
void mw_bdmove();

void mw_hgmove();
void mw_bgmove();
void mw_gmove();

void mw_bmove();
void mw_hmove();
void mw_HALTmove();

void teststatut();
void init_machine(void);
void testmove();
void asktoquit();

};

#endif // MAINWINDOW_H
