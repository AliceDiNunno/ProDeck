#ifndef STREAMDECKDISCOVERY_H
#define STREAMDECKDISCOVERY_H

#include <QObject>
#include <QTimer>

#include "Core/Device/StreamDeckAvailableDevice.h"
#include "StreamDeckDevice.h"

class StreamDeckDiscovery: public QObject
{
    Q_OBJECT

public:
    StreamDeckDiscovery(StreamDeckAvailableDevice device);
    void start();
    void stop();

signals:
    void deviceListUpdated(QList<StreamDeckDevice > );

private slots:
    void refresh();

private:
    QTimer *_pRefreshTimer;
    StreamDeckDeviceInformation _device;
};

#endif // STREAMDECKDISCOVERY_H
