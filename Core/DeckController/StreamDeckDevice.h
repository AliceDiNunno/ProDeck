#ifndef STREAMDECKDEVICE_H
#define STREAMDECKDEVICE_H

#include "Core/Device/StreamDeckDeviceInformation.h"
#include "Core/Hid/HidDevice.h"
#include <QtGui/QPixmap>

class StreamDeckDevice: public QObject
{
    Q_OBJECT
public:
    StreamDeckDevice(StreamDeckDeviceInformation information, QString serial);
    ~StreamDeckDevice();

    bool Open();
    void Close();
    void ResetStream();
    void SetBrightness(short );
    void Draw(short key, QPixmap pix);
    void Clear();

    bool operator==(const StreamDeckDevice *) const;
    bool operator<(const StreamDeckDevice *) const;
    QString serialNumber();

private:
    HidDevice *_device;
    StreamDeckDeviceInformation _deviceType;
    QString _serialNumber;
};

#endif // STREAMDECKDEVICE_H
