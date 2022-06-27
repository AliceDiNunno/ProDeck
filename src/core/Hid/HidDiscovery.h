#ifndef HIDDISCOVERY_H
#define HIDDISCOVERY_H

#include <QList>

class HidDiscovery {
public:
    static QList<QString> startDiscovery(unsigned short vendorId, unsigned short productId);
};

#endif // HIDDISCOVERY_H
