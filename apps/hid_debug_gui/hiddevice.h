#ifndef HIDDEVICE_H
#define HIDDEVICE_H
#include "../../signal11/hidapi/hidapi.h"
#include <QString>
#define MAX_STR 512

class Hiddevice
{
public:
    Hiddevice();
    QString get_device_list(void);
    bool device_connect(QString vid,QString pid);
    bool device_is_connected(void);

    QString device_list;
    QString device_pid;
    QString device_vid;
};

#endif // HIDDEVICE_H
