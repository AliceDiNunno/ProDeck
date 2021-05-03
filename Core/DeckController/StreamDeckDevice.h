#ifndef STREAMDECKDEVICE_H
#define STREAMDECKDEVICE_H

#include "Core/Device/StreamDeckDeviceInformation.h"
#include "Core/Hid/HidDevice.h"

class StreamDeckDevice
{
public:
    StreamDeckDevice(StreamDeckDeviceInformation information, QString serial);
    bool Open();
    void Close();
    void Clear();

    bool operator==(const StreamDeckDevice &a) const;

private:
    HidDevice *_device;
    StreamDeckDeviceInformation _deviceType;
    QString _serialNumber;
};

#endif // STREAMDECKDEVICE_H
