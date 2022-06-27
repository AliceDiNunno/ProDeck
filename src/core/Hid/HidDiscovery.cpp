#include <hidapi/hidapi.h>

#include "HidDiscovery.h"

//Returns the list of serial number found, if a device has no SN, an empty string will appear in the list
QList<QString> HidDiscovery::startDiscovery(unsigned short vendorId, unsigned short productId) {
    hid_device_info *info = hid_enumerate(vendorId, productId);

    auto devices = QList<QString>();

    while (info != nullptr) {
        devices << QString::fromWCharArray(info->serial_number);

        info = info->next;
    }

    return devices;
}
