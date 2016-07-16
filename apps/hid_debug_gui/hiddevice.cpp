#include "hiddevice.h"

Hiddevice::Hiddevice()
{

}



bool Hiddevice::connect_Hiddevice(const char *path)
{

    /*Qli
    FXint cur_item = device_list->getCurrentItem();
    if (cur_item < 0)
        return -1;
    FXListItem *item = device_list->getItem(cur_item);
    if (!item)
        return -1;
    struct hid_device_info *device_info = (struct hid_device_info*) item->getData();
    if (!device_info)
        return -1;
*/

 // connected_device =  hid_open(0x046b,0xc52b,NULL);
   connected_device =  hid_open_path(path);

    //connected_vendor_id=connected_device->hid_in vendor_id;
    //       connected_product_id=connected_device->product_id;
    if (!connected_device) {
        // FXMessageBox::error(this, MBOX_OK, "Device Error", "Unable To Connect to Device");
        return false;
    }
    hid_set_nonblocking(connected_device, 1);

    return true;
}


QList<QStringList> Hiddevice::get_device_list(void)
{
    //this->device_list
    int res;
    unsigned char buf[65];
    wchar_t wstr[__MNC_MAX_STR];
    hid_device *handle;
    QList<QStringList> retu;

    // Enumerate and print the HID devices on the system
    struct hid_device_info *devs, *cur_dev;

    devs = hid_enumerate(0x0, 0x0);
    cur_dev = devs;
    char *str=(char*)malloc(80*5*sizeof(char));
    int i=0;
    while (cur_dev) {


        sprintf(str,"%ls", cur_dev->product_string);
        device_list.append(str);
        retu.insert(i,QStringList(str));

        sprintf(str,"type: %04hx %04hx", cur_dev->product_id,cur_dev->vendor_id);
        device_list.append(str);
        retu.insert(i+1,QStringList(str));

        sprintf(str,"%s", cur_dev->path);
        device_list.append(str);
        retu.insert(i+2,QStringList(str));
        //printf("%s\n",cur_dev->path);
        //  sprintf(str,"\n");
        //device_list.append(str);
        //  retu.insert(i,QStringList(str));

        sprintf(str,"%ls", cur_dev->manufacturer_string);
        device_list.append(str);
        retu.insert(i+3,QStringList(str));

        sprintf(str,"%ls",cur_dev->serial_number);
        device_list.append(str);
        retu.insert(i+4,QStringList(str));

        cur_dev = cur_dev->next;
        //device_list.append(str);
        //  retu.insert(i,QStringList(str));
        //    i++;

    }
    hid_free_enumeration(devs);
    return retu;//device_list;
}
/*

    handle = hid_open(0x046d, 0xc52b, NULL);
    if(handle)
    {
        // Read the Manufacturer String
        res = hid_get_manufacturer_string(handle, wstr, __MNC_MAX_STR);
        printf("Manufacturer String: %ls\n", wstr);

        // Read the Product String
        res = hid_get_product_string(handle, wstr, __MNC_MAX_STR);
        printf("Product String: %ls\n", wstr);

        // Read the Serial Number String
        res = hid_get_serial_number_string(handle, wstr, __MNC_MAX_STR);
        printf("Serial Number String: %ls", wstr);
        printf("\n");

        // Send a Feature Report to the device
        buf[0] = 0x2; // First byte is report number
        buf[1] = 0xa0;
        buf[2] = 0x0a;
        res = hid_send_feature_report(handle, buf, 17);

        // Read a Feature Report from the device
        buf[0] = 0x2;
        res = hid_get_feature_report(handle, buf, sizeof(buf));

        // Print out the returned buffer.
        printf("Feature Report\n   ");
        for (i = 0; i < res; i++)
            printf("%02hhx ", buf[i]);
        printf("\n");

        // Set the hid_read() function to be non-blocking.
        hid_set_nonblocking(handle, 1);

        // Send an Output report to toggle the LED (cmd 0x80)
        buf[0] = 1; // First byte is report number
        buf[1] = 0x80;
        res = hid_write(handle, buf, 65);

        // Send an Output report to request the state (cmd 0x81)
        buf[1] = 0x81;
        hid_write(handle, buf, 65);

        // Read requested state
        res = hid_read(handle, buf, 65);
        if (res < 0)
            printf("Unable to read()\n");

        // Print out the returned buffer.
        for (i = 0; i < res; i++)
            printf("buf[%d]: %d\n", i, buf[i]);
    }


}
*/


/*
 * Version
Buffer
Data
Information
Stop
Table
PWM
Motors
General input/output
Override
LCD
 *
Char  Dec  Oct  Hex | Char  Dec  Oct  Hex | Char  Dec  Oct  Hex | Char Dec  Oct   Hex
-------------------------------------------------------------------------------------
(nul)   0 0000 0x00 | (sp)   32 0040 0x20 | @      64 0100 0x40 | `      96 0140 0x60
(soh)   1 0001 0x01 | !      33 0041 0x21 | A      65 0101 0x41 | a      97 0141 0x61
(stx)   2 0002 0x02 | "      34 0042 0x22 | B      66 0102 0x42 | b      98 0142 0x62
(etx)   3 0003 0x03 | #      35 0043 0x23 | C      67 0103 0x43 | c      99 0143 0x63
(eot)   4 0004 0x04 | $      36 0044 0x24 | D      68 0104 0x44 | d     100 0144 0x64
(enq)   5 0005 0x05 | %      37 0045 0x25 | E      69 0105 0x45 | e     101 0145 0x65
(ack)   6 0006 0x06 | &      38 0046 0x26 | F      70 0106 0x46 | f     102 0146 0x66
(bel)   7 0007 0x07 | '      39 0047 0x27 | G      71 0107 0x47 | g     103 0147 0x67
(bs)    8 0010 0x08 | (      40 0050 0x28 | H      72 0110 0x48 | h     104 0150 0x68
(ht)    9 0011 0x09 | )      41 0051 0x29 | I      73 0111 0x49 | i     105 0151 0x69
(nl)   10 0012 0x0a | *      42 0052 0x2a | J      74 0112 0x4a | j     106 0152 0x6a
(vt)   11 0013 0x0b | +      43 0053 0x2b | K      75 0113 0x4b | k     107 0153 0x6b
(np)   12 0014 0x0c | ,      44 0054 0x2c | L      76 0114 0x4c | l     108 0154 0x6c
(cr)   13 0015 0x0d | -      45 0055 0x2d | M      77 0115 0x4d | m     109 0155 0x6d
(so)   14 0016 0x0e | .      46 0056 0x2e | N      78 0116 0x4e | n     110 0156 0x6e
(si)   15 0017 0x0f | /      47 0057 0x2f | O      79 0117 0x4f | o     111 0157 0x6f
(dle)  16 0020 0x10 | 0      48 0060 0x30 | P      80 0120 0x50 | p     112 0160 0x70
(dc1)  17 0021 0x11 | 1      49 0061 0x31 | Q      81 0121 0x51 | q     113 0161 0x71
(dc2)  18 0022 0x12 | 2      50 0062 0x32 | R      82 0122 0x52 | r     114 0162 0x72
(dc3)  19 0023 0x13 | 3      51 0063 0x33 | S      83 0123 0x53 | s     115 0163 0x73
(dc4)  20 0024 0x14 | 4      52 0064 0x34 | T      84 0124 0x54 | t     116 0164 0x74
(nak)  21 0025 0x15 | 5      53 0065 0x35 | U      85 0125 0x55 | u     117 0165 0x75
(syn)  22 0026 0x16 | 6      54 0066 0x36 | V      86 0126 0x56 | v     118 0166 0x76
(etb)  23 0027 0x17 | 7      55 0067 0x37 | W      87 0127 0x57 | w     119 0167 0x77
(can)  24 0030 0x18 | 8      56 0070 0x38 | X      88 0130 0x58 | x     120 0170 0x78
(em)   25 0031 0x19 | 9      57 0071 0x39 | Y      89 0131 0x59 | y     121 0171 0x79
(sub)  26 0032 0x1a | :      58 0072 0x3a | Z      90 0132 0x5a | z     122 0172 0x7a
(esc)  27 0033 0x1b | ;      59 0073 0x3b | [      91 0133 0x5b | {     123 0173 0x7b
(fs)   28 0034 0x1c | <      60 0074 0x3c | \      92 0134 0x5c | |     124 0174 0x7c
(gs)   29 0035 0x1d | =      61 0075 0x3d | ]      93 0135 0x5d | }     125 0175 0x7d
(rs)   30 0036 0x1e | >      62 0076 0x3e | ^      94 0136 0x5e | ~     126 0176 0x7e
(us)   31 0037 0x1f | ?      63 0077 0x3f | _      95 0137 0x5f | (del) 127 0177 0x7f
*/
int Hiddevice::teststatus(void)
{
    //PC-> send 0x49 to get status of machine buffer
    //IPL5X: STATUS 0x00=not full. 0XFF=FULL (page 11
    //  0x49+STATUS
    // ! unsigned char data='\049';
    //unsigned char data=0x49;
    // ok u_int8_t data=0x56;
    /*OK!!! parrot lit V et mainwindow 86 (son code decimal)*/
    //u_int8_t data='V';
    unsigned char data='V';

    //uchar data='\049';
    //char *data_ptr = data;

    QChar ch( data );
    std::cout<<ch.unicode()<<std::endl;
    //uchar dateb='V';
    //u_int8_t data='V';
    //unsigned char data='V';
    char* ret=0;


    hid_write(minicut_device,  &data, sizeof(data));
    ret= read1s();
    if(ret==NULL)
    {
        qDebug("parrot write error!");
        this->machinestate=false;
        return 0;

    }
    else {            this->machinestate=true;
        return 1;

    }
}




unsigned char* Hiddevice::dumpDATA()
{

unsigned char buf[256];
    int res = hid_read(connected_device, buf, sizeof(buf));

    if (res > 0) {

        for (int i = 0; i < res; i++) {
    printf("%02hhx:", buf[i]);
/*
            FXString t;
            t.format("%02hhx ", buf[i]);
            s += t;
            if ((i+1) % 4 == 0)
                s += " ";
            if ((i+1) % 16 == 0)
                s += "\n";
 */
 }
printf("\n");
        return buf;

    }
    if (res < 0) {
        //input_text->appendText("hid_read() returned error\n");
        //input_text->setBottomLine(INT_MAX);
        return false;

    }
    }






char* Hiddevice::read1s()
{
    this->buffer=(unsigned char*)malloc(36*sizeof(unsigned char));

    hid_read_timeout(minicut_device,this->buffer,sizeof(buffer),1000);
    return  (char*)buffer;
}


/*test et initialise une connexion hid vers vId:0x046d pId:0xc050
 * une souris usb hid logitech rx250 ;) */
bool  Hiddevice::try_device(void)
{

    wchar_t wstr[__MNC_MAX_STR];
    QString pr;

    int res;
    unsigned char buf[65];

    if(minicut_device)
    {
        //set_connection_state("open");
        //driver_real=true;//is real driver
        // Read the Manufacturer String
        res = hid_get_manufacturer_string(minicut_device, wstr, __MNC_MAX_STR);
        // printf("Manufacturer String: %ls\n", wstr);
        pr= QString::fromWCharArray(wstr);
        std::cout << "Succefully opened:"<<pr.toStdString()<<std::endl;
        // Read the Product String
        res = hid_get_product_string(minicut_device, wstr, __MNC_MAX_STR);
        //printf("Product String: %ls\n", wstr);
        pr= QString::fromWCharArray(wstr);
        //driver_path=realmnc->path;
        std::cout << "Succefully opened:"<<pr.toStdString()<<std::endl;

        //  std::cout << wstr;
        // Read the Serial Number String
        res = hid_get_serial_number_string(minicut_device, wstr, __MNC_MAX_STR);
        //std::cout << wstr;
        //printf("Serial Number String: %ls", wstr);
        //printf("\n");
        /**/
        pr= QString::fromWCharArray(wstr);
        //driver_path="/dev/minicut_virtmnc";


        //std::cout << pr.ascii();

        //driver_real=true;
        // this->driver_path="/dev/null";
        //driver_path=minicut_test_device
    }

    if (teststatus())
    {return true;}
    else
    {return false;}
    return false;
}

void Hiddevice::softstop(){} //0x53+0x01


void Hiddevice::hardstop(){} //0x53+0x00

void Hiddevice::teststop(){} //0x53+0x03

int Hiddevice::testmove()
{
    //eg: usb data to move the first motor on 10 stepwhile 1 second
    //1 . send reset from pc: 0x42+0x00
    //1a. IPL5X answer is 0x42+0xFF
    //2 .source=USB (from PC): 0x42+0x01
    //2a. IPL5X answer is 0x42+0xFF
    //3 .Fill buffer
    //page7
    unsigned char data[]={0x42,0x00}; //Return the size of written data

    unsigned char data1[]={0x42,0x01}; //Return the size of written data
    unsigned char data2[]={0x42,0x01};
    //...
    unsigned char reset=0x42;



    hid_write(connected_device,  data, sizeof(data));

    //hid_write(virtmnc,  &data, sizeof(data));

    //      hid_write(virtmnc,  &data, sizeof(data));
    return 0;

}



void Hiddevice::set_pwm()
{
    //PC:0x50PWM+[OxOOpwmoff/0x01pwmon/0x02/read]+[0x00->0xFFVALUE

}
