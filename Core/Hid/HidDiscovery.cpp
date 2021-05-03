#include <hidapi/hidapi.h>

#include "HidDiscovery.h"

#include <QDebug>

QList<HidDeviceInformation> HidDiscovery::startDiscovery(unsigned short vendorId, unsigned short productId) {
    hid_device_info *info = hid_enumerate(productId, vendorId);

    auto devices = QList<HidDeviceInformation>();

    while (info != nullptr) {
        auto device = HidDeviceInformation();

        device.productId = info->product_id;
        device.vendorId = info->vendor_id;
        device.vendorName = QString::fromWCharArray(info->manufacturer_string);
        device.productName = QString::fromWCharArray(info->product_string);
        device.serialNumber = QString::fromWCharArray(info->serial_number);

        devices << device;

        info = info->next;
    }

    return devices;
}
