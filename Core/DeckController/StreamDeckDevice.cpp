#include <QTimer>
#include <QBuffer>
#include <QIODevice>
#include <QDebug>

#include "StreamDeckDevice.h"
#include "Core/Logging/Logging.h"

StreamDeckDevice::StreamDeckDevice(StreamDeckDeviceInformation information, QString serial): QObject(), _deviceType(information), _serialNumber(serial)
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
    auto open = _device->open();
    return open;
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
    auto IMAGE_REPORT_LENGTH = 1024;
    QByteArray payload(IMAGE_REPORT_LENGTH, (char) 0);
    payload[0] = 0x02;

    _device->write(payload);
}

void StreamDeckDevice::Draw(short key, QPixmap pix) {
    if (key < 0 || key > 31) {
        Logging::log("StreamDeckDevice: Attempting to write to a non-existant key. Aborting.");
        return;
    }

    QByteArray bArray;
    QBuffer buffer(&bArray);
    buffer.open(QIODevice::WriteOnly);
    pix.save(&buffer, "JPEG");

    auto IMAGE_REPORT_LENGTH = 1024;
    auto IMAGE_REPORT_HEADER_LENGTH = 8;
    auto IMAGE_REPORT_PAYLOAD_LENGTH = IMAGE_REPORT_LENGTH - IMAGE_REPORT_HEADER_LENGTH;

    auto page_number = 0;
    auto bytes_remaining = bArray.size();
    while (bytes_remaining > 0) {
        auto this_length = bytes_remaining < IMAGE_REPORT_PAYLOAD_LENGTH ? bytes_remaining : IMAGE_REPORT_PAYLOAD_LENGTH;
        auto bytes_sent = page_number * IMAGE_REPORT_PAYLOAD_LENGTH;

        QByteArray payload(IMAGE_REPORT_LENGTH, (char) 0);

        payload[0] = 0x02;
        payload[1] = 0x07;
        payload[2] = key;
        payload[3] = this_length == bytes_remaining ? 1 : 0;
        payload[4] = this_length & 0xFF;
        payload[5] = this_length >> 8;
        payload[6] = page_number & 0xFF;
        payload[7] = page_number >> 8;

        for (int i = 0; i < this_length; i++) {
            payload[i + 8] = bArray[bytes_sent + i];
        }

        _device->write(payload);

        bytes_remaining = bytes_remaining - this_length;
        page_number = page_number + 1;
    }
    ResetStream();
}

void StreamDeckDevice::Clear() {
    const unsigned char clearData[] = {0x03, 0x02};

    _device->writeFeature(clearData, 2);
}

QString StreamDeckDevice::serialNumber() {
    return _serialNumber;
}

bool StreamDeckDevice::operator==(const StreamDeckDevice *other) const {
    return this->_serialNumber == other->_serialNumber;
}

bool StreamDeckDevice::operator<(const StreamDeckDevice *other) const {
    return this->_serialNumber < other->_serialNumber;
}

StreamDeckDevice::~StreamDeckDevice() {

}
