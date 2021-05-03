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

void StreamDeckDevice::SetBrightness(short brightness) {
    if (brightness < 0) {
        brightness = 0;
    }

    if (brightness > 100) {
        brightness = 100;
    }

    const unsigned char brightnessData[] = {0x03, 0x08, (const unsigned char)brightness};
    _device->writeFeature(brightnessData, 3);
}

void StreamDeckDevice::ResetStream() {

}

void StreamDeckDevice::Clear() {
    const unsigned char clearData[] = {0x03, 0x02};

    _device->writeFeature(clearData, 2);
}

QString StreamDeckDevice::serialNumber() {
    return _serialNumber;
}

bool StreamDeckDevice::operator==(const StreamDeckDevice &other) const {
    return this->_serialNumber == other._serialNumber;
}

bool StreamDeckDevice::operator<(const StreamDeckDevice &other) const {
    return this->_serialNumber < other._serialNumber;
}
