#ifndef STREAMDECKDEVICEINFORMATION_H
#define STREAMDECKDEVICEINFORMATION_H

#include <QString>

struct StreamDeckDeviceInformation {
    QString deviceName;
    unsigned short vendorId = 0x0fd9;
    unsigned short productId;
    unsigned short keyResolution;
    unsigned short rows;
    unsigned short columns;

    unsigned short keyCount() {
        return rows * columns;
    }
};

#endif // STREAMDECKDEVICE_H
