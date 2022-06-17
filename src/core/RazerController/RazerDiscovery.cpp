#include "RazerDiscovery.h"

#include "src/core/Logging/Logging.h"
#include "src/core/Device/Razer/RazerFactory.h"
#include "src/core/Hid/HidDiscovery.h"

#include <QDebug>

RazerDiscovery::RazerDiscovery(RazerAvailableDevice device): _device(RazerFactory::buildDevice(device))
{
    _pRefreshTimer = new QTimer();
    connect(_pRefreshTimer, SIGNAL(timeout()), this, SLOT(refresh()));
}

void RazerDiscovery::start() {
    Logging::log("Starting discovery for: " + _device.deviceName);
    _pRefreshTimer->start(1000);
}

void RazerDiscovery::stop() {
    Logging::log("Stopping discovery for: " + _device.deviceName);
    _pRefreshTimer->stop();
}

void RazerDiscovery::refresh() {
    auto items = HidDiscovery::startDiscovery(_device.productId, _device.vendorId);

    auto updatedItems = QList<RazerDevice *>();

    for (int iItem = 0; iItem < items.count(); iItem++) {
        auto currentDevice = items[iItem];

        qDebug() << currentDevice.serialNumber;

        //updatedItems.append(new RazerDevice(_device, currentDevice.serialNumber));
    }

    emit deviceListUpdated(updatedItems);
}
