#include "HidDevice.h"
#include <QDebug>

HidDevice::HidDevice(HidDeviceInformation device): _device(device), _pDeviceDescriptor(nullptr)
{

}

bool HidDevice::isOpen() {
    return _pDeviceDescriptor != nullptr;
}

bool HidDevice::open() {
    if (_pDeviceDescriptor != nullptr) {
        return isOpen();
    }

    _pDeviceDescriptor = hid_open(_device.vendorId, _device.productId, _device.serialNumber.toStdWString().c_str());

    return isOpen();
}

void HidDevice::writeFeature(const unsigned char *feature, int length) {
    if (_pDeviceDescriptor == nullptr) { return; }
    hid_send_feature_report(_pDeviceDescriptor, feature, length);
}

void HidDevice::close() {
    if (_pDeviceDescriptor == nullptr) return;

    hid_close(_pDeviceDescriptor);
}
