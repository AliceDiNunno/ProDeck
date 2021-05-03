#include "StreamDeckDevice.h"

StreamDeckDevice::StreamDeckDevice(StreamDeckDeviceInformation information, QString serial): _deviceType(information), _serialNumber(serial)
{
    HidDeviceInformation hidInfo;
    hidInfo.productId = information.productId;
    hidInfo.productName = information.deviceName;
    hidInfo.serialNumber = serial;
    hidInfo.vendorId = information.vendorId;
    hidInfo.vendorName = "Elgato";

    _device = new HidDevice(hidInfo);
}

bool StreamDeckDevice::Open() {
    return _device->open();
}

void StreamDeckDevice::Close() {
    _device->close();
}

void StreamDeckDevice::Clear() {

bool StreamDeckDevice::operator==(const StreamDeckDevice &other) const {
    return this->_serialNumber == other._serialNumber;
}

bool StreamDeckDevice::operator<(const StreamDeckDevice &other) const {
    return this->_serialNumber < other._serialNumber;
}
