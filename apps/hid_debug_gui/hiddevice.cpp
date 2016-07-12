#include "hiddevice.h"

Hiddevice::Hiddevice()
{

}




QString Hiddevice::get_device_list(void)
{
//this->device_list
int res;
unsigned char buf[65];
wchar_t wstr[MAX_STR];
hid_device *handle;
int i;

// Enumerate and print the HID devices on the system
struct hid_device_info *devs, *cur_dev;

devs = hid_enumerate(0x0, 0x0);
cur_dev = devs;
char *str=(char*)malloc(80*5*sizeof(char));

while (cur_dev) {
    sprintf(str,"Device Found\n  type: %04hx %04hx\n  path: %s\n  serial_number: %ls",
        cur_dev->vendor_id, cur_dev->product_id, cur_dev->path, cur_dev->serial_number);
    device_list.append(str);

    sprintf(str,"\n");
    device_list.append(str);

    sprintf(str,"  Manufacturer: %ls\n", cur_dev->manufacturer_string);
    device_list.append(str);

    sprintf(str,"  Product:      %ls\n", cur_dev->product_string);
    device_list.append(str);

    sprintf(str,"\n");
    cur_dev = cur_dev->next;
    device_list.append(str);
}
hid_free_enumeration(devs);
/*IPL5X is a USB 2.0 device working at full speed.
It identifies itself on the system as a HID compatible device with the following IDs:
VENDOR ID
0x04D8
PRODUCT ID
0x00AA
USB input and output buffers length are 36 Bytes.
Polling time is set to 1ms.

Answers from machine always start with the first byte sent:
It's the kind of order to execute (move,info, etc)*/

// Open the device using the VID, PID,
// and optionally the Serial number.
handle = hid_open(0x46d, 0xc52b, NULL);
if(handle)
{
// Read the Manufacturer String
res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
printf("Manufacturer String: %ls\n", wstr);

// Read the Product String
res = hid_get_product_string(handle, wstr, MAX_STR);
printf("Product String: %ls\n", wstr);

// Read the Serial Number String
res = hid_get_serial_number_string(handle, wstr, MAX_STR);
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
return device_list;


}
