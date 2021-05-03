#ifndef HIDDEVICEINFORMATION_H
#define HIDDEVICEINFORMATION_H

#include <QString>

struct HidDeviceInformation {
    unsigned short vendorId;
    unsigned short productId;
    QString vendorName;
    QString productName;
    QString serialNumber;
};

#endif // HIDDEVICEINFORMATION_H
