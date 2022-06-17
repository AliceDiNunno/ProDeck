#ifndef RAZERDEVICEINFORMATION_H
#define RAZERDEVICEINFORMATION_H

#include <QString>

struct RazerDeviceInformation {
    QString deviceName;
    unsigned short vendorId = 0x1532;
    unsigned short productId;
};

#endif // RAZERDEVICEINFORMATION_H
