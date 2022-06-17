#include "HidDevice.h"
#include <QDebug>
#include <QElapsedTimer>

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

    if (_pDeviceDescriptor != nullptr) {
        hid_set_nonblocking(_pDeviceDescriptor, 1);
    }
    return isOpen();
}

void HidDevice::writeFeature(const unsigned char *feature, int length) {
    if (_pDeviceDescriptor == nullptr) { return; }
    hid_send_feature_report(_pDeviceDescriptor, feature, length);
}

void HidDevice::write(QByteArray array) {
    if (_pDeviceDescriptor == nullptr) { return; }
    hid_write(_pDeviceDescriptor, (const unsigned char *) array.data(), array.length());
}

QByteArray HidDevice::read(int size) {
    if (isOpen()) { return QByteArray(); }

    QElapsedTimer timer;
    timer.start();

    unsigned char *data = (unsigned char *)calloc(size, sizeof(unsigned char));    

    int readCount = hid_read_timeout(_pDeviceDescriptor, data, size, 1);

    if (readCount == -1) {
        close();
    }

    QByteArray array(size, 0);

    for (int i = 0; i < size; i++) {
        array[i] = data[i];
    }
    free(data);

    if (readCount > 0) {
        return array;
    }

    return QByteArray();
}

void HidDevice::close() {
    if (_pDeviceDescriptor == nullptr) return;

    hid_close(_pDeviceDescriptor);
    _pDeviceDescriptor = nullptr;
}
