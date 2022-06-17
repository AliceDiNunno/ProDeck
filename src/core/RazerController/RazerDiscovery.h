#ifndef RAZERDISCOVERY_H
#define RAZERDISCOVERY_H

#include <QObject>
#include <QTimer>

#include "src/core/Device/Razer/RazerAvailableDevice.h"
#include "RazerDevice.h"

class RazerDiscovery: public QObject
{
    Q_OBJECT

public:
    RazerDiscovery(RazerAvailableDevice device);
    void start();
    void stop();

signals:
    void deviceListUpdated(QList<RazerDevice *> );

private slots:
    void refresh();

private:
    QTimer *_pRefreshTimer;
    RazerDeviceInformation _device;
};


#endif // RAZERDISCOVERY_H
