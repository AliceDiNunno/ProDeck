#ifndef HIDDISCOVERY_H
#define HIDDISCOVERY_H

#include <QList>
#include "HidDeviceInformation.h"

class HidDiscovery {
public:
    static QList<HidDeviceInformation> startDiscovery(unsigned short vendorId, unsigned short productId);
};

#endif // HIDDISCOVERY_H
