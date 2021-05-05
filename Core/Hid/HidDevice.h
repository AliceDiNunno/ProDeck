#ifndef HIDDEVICE_H
#define HIDDEVICE_H

#include "hidapi/hidapi.h"
#include "HidDeviceInformation.h"

class HidDevice
{
public:
    HidDevice(HidDeviceInformation device);

    bool open();
    void close();

    QByteArray read(int );
    void writeFeature(const unsigned char *, int);
    void write(QByteArray );

    bool isOpen();

private:
    HidDeviceInformation _device;

    hid_device *_pDeviceDescriptor;
};

#endif // HIDDEVICE_H
