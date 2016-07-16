#ifndef HIDDEVICE_H
#define HIDDEVICE_H
#include "../../signal11/hidapi/hidapi.h"
//#include <QString>
#define __MNC_MAX_STR 512
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <QStringList>
class Hiddevice
{
public:
    Hiddevice();
    QList<QStringList> get_device_list(void);
    QString get_device_stringlist(void);

    bool device_connect(QString vid,QString pid);
    bool device_is_connected(void);
    int teststatus(void);
    char* read1s();
    bool machinestate;
    unsigned char *buffer;
    bool  try_device(void);

    void softstop(); //0x53+0x01

    bool connect_Hiddevice(const char *path);

    void hardstop(); //0x53+0x00

    void teststop(); //0x53+0x03
    void set_pwm();
    hid_device *connected_device=NULL;

   unsigned char* dumpDATA();

    unsigned short connected_vendor_id;
    /** Device Product ID */
    unsigned short connected_product_id;
    int testmove();
private:
    /*HID device to open*/
    hid_device *minicut_device=NULL;
    QString device_list;
    QString device_pid;
    QString device_vid;
};

#endif // HIDDEVICE_H
