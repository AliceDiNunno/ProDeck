#ifndef STREAMDECKDEVICE_H
#define STREAMDECKDEVICE_H

#include "src/core/Device/Elgato/StreamDeckDeviceInformation.h"
#include "src/core/Hid/HidDevice.h"
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
    QSize size();

private slots:
    void readKeys();

signals:
    void keyUp(int);
    void keyDown(int);

private:
    HidDevice *_device;
    StreamDeckDeviceInformation _deviceType;
    QString _serialNumber;
    QTimer *_pReadTimer;
};

#endif // STREAMDECKDEVICE_H
